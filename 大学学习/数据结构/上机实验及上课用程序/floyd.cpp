 // floyd.cpp 实现教科书图7.33的程序   (台北为孤立顶点)

 #define MAX_NAME 9 // 顶点字符串的最大长度+1
 #define MAX_INFO 20 // 相关信息字符串的最大长度+1
 typedef int VRType;
 typedef char VertexType[MAX_NAME];
 typedef char InfoType;
 
 #include<string.h> 
 #include<limits.h> 
 #include<stdio.h>       
 
 #define TRUE 1
 #define FALSE 0 

// 图的数组(邻接矩阵)存储表示
 #define INFINITY INT_MAX // 用整型最大值代替∞
 #define MAX_VERTEX_NUM 26 // 最大顶点个数
 enum GraphKind{DG,DN,UDG,UDN}; 
 typedef struct
 { VRType adj; 
   InfoType *info; 
 }ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
 struct MGraph
 { VertexType vexs[MAX_VERTEX_NUM]; 
   AdjMatrix arcs; 
   int vexnum,arcnum; 
   GraphKind kind; 
 };
 
 //  图的邻接矩阵存储表示的基本操作(2个)
 int LocateVex(MGraph G,VertexType u)
 { // 初始条件：图G存在，u和G中顶点有相同特征
   // 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i])==0) return i;
   return -1;
 }

 void CreateFUDN(MGraph &G) // 采用数组(邻接矩阵)表示法，由文件构造没有相关信息的无向网G
 { int i,j,k,w;
   char filename[13];
   VertexType va,vb;
   FILE *graphlist;
   printf("请输入数据文件名：");
   scanf("%s",filename);
   graphlist=fopen(filename,"r"); // 打开数据文件
   fscanf(graphlist,"%d",&G.vexnum);
   fscanf(graphlist,"%d",&G.arcnum);
   for(i=0;i<G.vexnum;++i) // 构造顶点向量
     fscanf(graphlist,"%s",G.vexs[i]);
   for(i=0;i<G.vexnum;++i) // 初始化邻接矩阵
     for(j=0;j<G.vexnum;++j)
     { G.arcs[i][j].adj=INFINITY; 
       G.arcs[i][j].info=NULL; 
     }
   for(k=0;k<G.arcnum;++k)
   { fscanf(graphlist,"%s%s%d",va,vb,&w);
     i=LocateVex(G,va);
     j=LocateVex(G,vb);
     G.arcs[i][j].adj=G.arcs[j][i].adj=w; 
   }
   fclose(graphlist);
   G.kind=UDN;
 }

 typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 3维数组
 typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

// 算法7.16  求有向网中各对顶点之间最短距离的Floyd算法
 void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D)
 { // 用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]。
   // 若P[v][w][u]为TRUE，则u是从v到w当前求得最短路径上的顶点。
   int u,v,w,i;
   for(v=0;v<G.vexnum;v++) // 各对结点之间初始已知路径及距离
     for(w=0;w<G.vexnum;w++)
     { D[v][w]=G.arcs[v][w].adj; // 顶点v到顶点w的直接距离
       for(u=0;u<G.vexnum;u++)
         P[v][w][u]=FALSE; // 路径矩阵初值
       if(D[v][w]<INFINITY) // 从v到w有直接路径
         P[v][w][v]=P[v][w][w]=TRUE; // 由v到w的路径经过v和w两点
     }
   for(u=0;u<G.vexnum;u++)
     for(v=0;v<G.vexnum;v++)
       for(w=0;w<G.vexnum;w++)
         if(D[v][u]<INFINITY&&D[u][w]<INFINITY&&D[v][u]+D[u][w]<D[v][w])
         { // 从v经u到w的一条路径更短
           D[v][w]=D[v][u]+D[u][w]; // 更新最短距离
           for(i=0;i<G.vexnum;i++)
             P[v][w][i]=P[v][u][i]||P[u][w][i]; // 从v到w的路径经过从v到u和从u到w的所有路径
         }
 }

 void path(MGraph G,PathMatrix P,int i,int j)
 { // 求由序号为i的起点城市到序号为j的终点城市最短路径沿途所经过的城市
   int k;
   int m=i; // 起点城市序号赋给m
   printf("依次经过的城市：\n");
   while(m!=j) // 没到终点城市
   { G.arcs[m][m].adj=INFINITY; // 对角元素赋值无穷大
     for(k=0;k<G.vexnum;k++)
       if(G.arcs[m][k].adj<INFINITY&&P[m][j][k]) // m到k有直接通路，且k在m到j的最短路径上
       { printf("%s ",G.vexs[m]);
         G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY; // 将直接通路设为不通
         m=k; // 经过的城市序号赋给m，继续查找
         break;
       }
   }
   printf("%s\n",G.vexs[j]); // 输出终点城市
 }

 void main()
 { MGraph g;
   int i,j,k,q=1;
   PathMatrix p; // 3维数组
   DistancMatrix d; // 2维数组
   printf("请输入数据文件名P187.txt\n");
   CreateFUDN(g); // 通过文件构造无向网g
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0; // ShortestPath_FLOYD()要求对角元素值为0，因为两点相同，其距离为0
   ShortestPath_FLOYD(g,p,d); // 求每对顶点间的最短路径
   while(q)
   { printf("请选择：1 查询  0 结束\n");
     scanf("%d",&q);
     if(q)
     { for(i=0;i<g.vexnum;i++)
       { printf("%2d %-9s",i+1,g.vexs[i]);
         if(i%6==5) // 输出6个数据就换行
           printf("\n");
       }
       printf("\n请输入要查询的起点城市代码 终点城市代码: ");
       scanf("%d%d",&i,&j);
       if(d[i-1][j-1]<INFINITY) // 有通路
       { printf("%s到%s的最短距离为%d\n",g.vexs[i-1],g.vexs[j-1],d[i-1][j-1]);
         path(g,p,i-1,j-1); // 求最短路径上由起点城市到终点城市沿途所经过的城市
       }
       else
         printf("%s到%s没有路径可通\n",g.vexs[i-1],g.vexs[j-1]);
       printf("与%s到%s有关的p矩阵:\n",g.vexs[i-1],g.vexs[j-1]);
       for(k=0;k<g.vexnum;k++)
         printf("%2d",p[i-1][j-1][k]);
       printf("\n");
     }
   }
 }
