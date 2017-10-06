 // floyd.cpp ʵ�ֽ̿���ͼ7.33�ĳ���   (̨��Ϊ��������)

 #define MAX_NAME 9 // �����ַ�������󳤶�+1
 #define MAX_INFO 20 // �����Ϣ�ַ�������󳤶�+1
 typedef int VRType;
 typedef char VertexType[MAX_NAME];
 typedef char InfoType;
 
 #include<string.h> 
 #include<limits.h> 
 #include<stdio.h>       
 
 #define TRUE 1
 #define FALSE 0 

// ͼ������(�ڽӾ���)�洢��ʾ
 #define INFINITY INT_MAX // ���������ֵ�����
 #define MAX_VERTEX_NUM 26 // ��󶥵����
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
 
 //  ͼ���ڽӾ���洢��ʾ�Ļ�������(2��)
 int LocateVex(MGraph G,VertexType u)
 { // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
   // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i])==0) return i;
   return -1;
 }

 void CreateFUDN(MGraph &G) // ��������(�ڽӾ���)��ʾ�������ļ�����û�������Ϣ��������G
 { int i,j,k,w;
   char filename[13];
   VertexType va,vb;
   FILE *graphlist;
   printf("�����������ļ�����");
   scanf("%s",filename);
   graphlist=fopen(filename,"r"); // �������ļ�
   fscanf(graphlist,"%d",&G.vexnum);
   fscanf(graphlist,"%d",&G.arcnum);
   for(i=0;i<G.vexnum;++i) // ���춥������
     fscanf(graphlist,"%s",G.vexs[i]);
   for(i=0;i<G.vexnum;++i) // ��ʼ���ڽӾ���
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

 typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 3ά����
 typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

// �㷨7.16  ���������и��Զ���֮����̾����Floyd�㷨
 void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D)
 { // ��Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]��
   // ��P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ��㡣
   int u,v,w,i;
   for(v=0;v<G.vexnum;v++) // ���Խ��֮���ʼ��֪·��������
     for(w=0;w<G.vexnum;w++)
     { D[v][w]=G.arcs[v][w].adj; // ����v������w��ֱ�Ӿ���
       for(u=0;u<G.vexnum;u++)
         P[v][w][u]=FALSE; // ·�������ֵ
       if(D[v][w]<INFINITY) // ��v��w��ֱ��·��
         P[v][w][v]=P[v][w][w]=TRUE; // ��v��w��·������v��w����
     }
   for(u=0;u<G.vexnum;u++)
     for(v=0;v<G.vexnum;v++)
       for(w=0;w<G.vexnum;w++)
         if(D[v][u]<INFINITY&&D[u][w]<INFINITY&&D[v][u]+D[u][w]<D[v][w])
         { // ��v��u��w��һ��·������
           D[v][w]=D[v][u]+D[u][w]; // ������̾���
           for(i=0;i<G.vexnum;i++)
             P[v][w][i]=P[v][u][i]||P[u][w][i]; // ��v��w��·��������v��u�ʹ�u��w������·��
         }
 }

 void path(MGraph G,PathMatrix P,int i,int j)
 { // �������Ϊi�������е����Ϊj���յ�������·����;�������ĳ���
   int k;
   int m=i; // ��������Ÿ���m
   printf("���ξ����ĳ��У�\n");
   while(m!=j) // û���յ����
   { G.arcs[m][m].adj=INFINITY; // �Խ�Ԫ�ظ�ֵ�����
     for(k=0;k<G.vexnum;k++)
       if(G.arcs[m][k].adj<INFINITY&&P[m][j][k]) // m��k��ֱ��ͨ·����k��m��j�����·����
       { printf("%s ",G.vexs[m]);
         G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY; // ��ֱ��ͨ·��Ϊ��ͨ
         m=k; // �����ĳ�����Ÿ���m����������
         break;
       }
   }
   printf("%s\n",G.vexs[j]); // ����յ����
 }

 void main()
 { MGraph g;
   int i,j,k,q=1;
   PathMatrix p; // 3ά����
   DistancMatrix d; // 2ά����
   printf("�����������ļ���P187.txt\n");
   CreateFUDN(g); // ͨ���ļ�����������g
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0; // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0����Ϊ������ͬ�������Ϊ0
   ShortestPath_FLOYD(g,p,d); // ��ÿ�Զ��������·��
   while(q)
   { printf("��ѡ��1 ��ѯ  0 ����\n");
     scanf("%d",&q);
     if(q)
     { for(i=0;i<g.vexnum;i++)
       { printf("%2d %-9s",i+1,g.vexs[i]);
         if(i%6==5) // ���6�����ݾͻ���
           printf("\n");
       }
       printf("\n������Ҫ��ѯ�������д��� �յ���д���: ");
       scanf("%d%d",&i,&j);
       if(d[i-1][j-1]<INFINITY) // ��ͨ·
       { printf("%s��%s����̾���Ϊ%d\n",g.vexs[i-1],g.vexs[j-1],d[i-1][j-1]);
         path(g,p,i-1,j-1); // �����·�����������е��յ������;�������ĳ���
       }
       else
         printf("%s��%sû��·����ͨ\n",g.vexs[i-1],g.vexs[j-1]);
       printf("��%s��%s�йص�p����:\n",g.vexs[i-1],g.vexs[j-1]);
       for(k=0;k<g.vexnum;k++)
         printf("%2d",p[i-1][j-1][k]);
       printf("\n");
     }
   }
 }
