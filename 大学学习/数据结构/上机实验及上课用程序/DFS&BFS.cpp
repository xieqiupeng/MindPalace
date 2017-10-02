 //DFS&BFS.cpp  用邻接表实现的深度优先和广度优先的程序

 #include<string.h> 
 #include<malloc.h> 
 #include<stdio.h> 
 #include<math.h> 
 #include<process.h> 
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; 
 typedef int Boolean; 

 #define MAX_NAME 5 // 顶点字符串的最大长度+1
 typedef int InfoType; // 网的权值类型
 typedef char VertexType[MAX_NAME]; // 顶点类型为字符串

  // 以下是图的邻接表存储表示(与单链表的变量类型建立联系)
 #define MAX_VERTEX_NUM 20
 enum GraphKind{DG,DN,UDG,UDN}; // {有向图,有向网,无向图,无向网}
 struct ElemType // 新加的
 { int adjvex; // 该弧所指向的顶点的位置
   InfoType *info; // 网的权值指针
 };
 struct ArcNode // // 表结点。 有改动
 { ElemType data; // 除指针以外的部分都属于ElemType
   ArcNode *nextarc; // 指向下一条弧的指针
 }; 
 typedef struct  // 头结点
 { VertexType data; // 顶点信息
   ArcNode *firstarc; // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
 }VNode,AdjList[MAX_VERTEX_NUM]; 
 struct ALGraph
 { AdjList vertices;
   int vexnum,arcnum; // 图的当前顶点数和弧数
   GraphKind kind; // 图的种类标志
 };  // 图的邻接表存储表示

 #define LNode ArcNode // 新加的。定义单链表的结点类型是图的表结点的类型
 #define next nextarc // 新加的。定义单链表结点的指针域是表结点指向下一条弧的指针域
 typedef ArcNode *LinkList; // 新加的。定义指向单链表结点的指针是指向图的表结点的指针

 //*********邻接表存储结构的基本操作开始*********
//  图的邻接表存储的基本操作，以及算法7.4～7.6
 
// ------不带头结点的单链表的部分基本操作(5个) ------
 #define DestroyList ClearList // DestroyList()和ClearList()的操作是一样的
 
 void ClearList(LinkList &L)
 { // 初始条件：线性表L已存在。操作结果：将L重置为空表
   LinkList p;
   while(L) // L不空
   { p=L; // p指向首元结点
     L=L->next; // L指向第2个结点(新首元结点)
     free(p); // 释放首元结点
   }
 }

 int ListLength(LinkList L)
 { // 初始条件：线性表L已存在。操作结果：返回L中数据元素个数
   int i=0;
   LinkList p=L;
   while(p) // p指向结点(没到表尾)
   { p=p->next; // p指向下一个结点
     i++;
   }
   return i;
 }
 
 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // 初始条件：线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
   // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
   //           若这样的数据元素不存在，则返回值为0
   int i=0;
   LinkList p=L;
   while(p)
   { i++;
     if(compare(p->data,e)) return i; // 找到这样的数据元素       
     p=p->next;
   }
   return 0;
 }

 Status ListInsert(LinkList &L,int i,ElemType e)
 { // 在不带头结点的单链线性表L中第i个位置之前插入元素e
   int j=1;
   LinkList p=L,s;
   if(i<1) return ERROR; // i值不合法     
   s=(LinkList)malloc(sizeof(LNode)); // 生成新结点
   s->data=e; // 给s的data域赋值
   if(i==1) // 插在表头
   { s->next=L;
     L=s; // 改变L
   }
   else   // 插在表的其余处
   { while(p&&j<i-1) // 寻找第i-1个结点
      { p=p->next;
       j++;
	  }
     if(!p) return ERROR;  // i大于表长+1       
     s->next=p->next;
     p->next=s;
   }
   return OK;
 }

 Status ListDelete(LinkList &L,int i,ElemType &e)
 { // 在不带头结点的单链线性表L中，删除第i个元素，并由e返回其值
   int j=1;
   LinkList p=L,q;
   if(i==1) // 删除第1个结点
   { L=p->next; // L由第2个结点开始
     e=p->data;
     free(p); // 删除并释放第1个结点
   }
   else
   {while(p->next&&j<i-1) // 寻找第i个结点，并令p指向其前趋
     { p=p->next;
       j++;
     }
     if(!p->next||j>i-1)  return ERROR;  // 删除位置不合理      
     q=p->next; // 删除并释放结点
     p->next=q->next;
     e=q->data;
     free(q);
   }
   return OK;
 }
 // ------不带头结点的单链表基本操作结束------

//------ 以下是不带头结点的单链表的扩展操作(3个)------
void InsertAscend(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType))
 { // 按关键字非降序将e插入表L。函数compare()返回值为：形参1的关键字-形参2的关键字
   LinkList q=L;
   if(!L||compare(e,L->data)<=0) // 链表空或e的关键字小于等于首结点的关键字
     ListInsert(L,1,e); // 将e插在表头，在bo2-8.cpp中
   else
   { while(q->next&&compare(q->next->data,e)<0) // q不是尾结点且q的下一结点关键字<e的关键字
         q=q->next;
     ListInsert(q,2,e); // 插在q所指结点后(将q作为头指针)
   }
 }

 LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
 { // 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是
   // 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
   // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
   int i,j;
   i=LocateElem(L,e,equal);
   if(i) // 找到
   {if(i==1) // 是首元结点
     { p=NULL;
       return L;
     }
     p=L;
     for(j=2;j<i;j++)  p=p->next;
     return p->next;
   }
   return NULL; // 没找到
 }

 Status DeleteElem(LinkList &L,ElemType &e,Status(*equal)(ElemType,ElemType))
 { // 删除表L中满足条件的结点，并返回TRUE；如无此结点，则返回FALSE。
   // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
   LinkList p,q;
   q=Point(L,e,equal,p);
   if(q) // 找到此结点，且q指向该结点
   { if(p) // 该结点不是首元结点，p指向其前驱
       ListDelete(p,2,e); // 将p作为头指针,删除第2个结点
     else  ListDelete(L,1,e);   // 该结点是首元结点       
     return TRUE;
   }
   return FALSE;
 }

//------ 不带头结点的单链表扩展操作结束------


 int LocateVex(ALGraph G,VertexType u)
 { // 初始条件：图G存在，u和G中顶点有相同特征
   // 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
   int i;
   for(i=0;i<G.vexnum;++i)
	   {if(strcmp(u,G.vertices[i].data)==0) return i;}
   return -1;
 }

 void CreateGraphF(ALGraph &G)
 { // 采用邻接表存储结构，由文件构造没有相关信息图或网G(用一个函数构造4种图)
   int i,j,k,w; // w是权值
   VertexType va,vb; // 连接边或弧的2顶点
   ElemType e;
   char filename[13];
   FILE *graphlist;
   printf("请输入数据文件名(f7-1.txt或f7-2.txt)：");
   scanf("%s",filename);
   printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
   scanf("%d",&G.kind);
   graphlist=fopen(filename,"r"); // 以读的方式打开数据文件，并以graphlist表示
   fscanf(graphlist,"%d",&G.vexnum);
   fscanf(graphlist,"%d",&G.arcnum);
   for(i=0;i<G.vexnum;++i) // 构造顶点向量
   { fscanf(graphlist,"%s",G.vertices[i].data);
     G.vertices[i].firstarc=NULL; // 初始化与该顶点有关的出弧链表
   }
   for(k=0;k<G.arcnum;++k) // 构造相关弧链表
   { if(G.kind%2) fscanf(graphlist,"%d%s%s",&w,va,vb);// 网
     else fscanf(graphlist,"%s%s",va,vb);  // 图
     i=LocateVex(G,va); // 弧尾
     j=LocateVex(G,vb); // 弧头
     e.info=NULL; // 给待插表结点e赋值，图无权
     e.adjvex=j; // 弧头
     if(G.kind%2) // 网
     { e.info=(int *)malloc(sizeof(int)); // 动态生成存放权值的空间
       *(e.info)=w;
     }
     ListInsert(G.vertices[i].firstarc,1,e); // 插在第i个元素(出弧)的表头
     if(G.kind>=2) // 无向图或网，产生第2个表结点，并插在第j个元素(入弧)的表头
     { e.adjvex=i; // e.info不变，不必再赋值
       ListInsert(G.vertices[j].firstarc,1,e); // 插在第j个元素的表头
     }
   }
   fclose(graphlist); // 关闭数据文件
 }

 void DestroyGraph(ALGraph &G)
 { // 初始条件：图G存在。操作结果：销毁图G
   int i;
   ElemType e;
   for(i=0;i<G.vexnum;++i) // 对于所有顶点
     if(G.kind%2) // 网
       while(G.vertices[i].firstarc) // 对应的弧或边链表不空
       {ListDelete(G.vertices[i].firstarc,1,e); // 删除链表的第1个结点，并将值赋给e
	    if(e.adjvex>i)  free(e.info);   // 顶点序号>i(保证动态生成的权值空间只释放1次)	   
       }
     else  DestroyList(G.vertices[i].firstarc); // 图。 销毁弧或边链表，
   G.vexnum=0; // 顶点数为0
   G.arcnum=0; // 边或弧数为0
 }

 int FirstAdjVex(ALGraph G,VertexType v)
 { // 初始条件：图G存在，v是G中某个顶点
   // 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
   ArcNode *p;
   int v1;
   v1=LocateVex(G,v); // v1为顶点v在图G中的序号
   p=G.vertices[v1].firstarc;
   if(p)  return p->data.adjvex;
   else   return -1;
 }

 Status equalvex(ElemType a,ElemType b)
 { // DeleteArc()、DeleteVex()和NextAdjVex()要调用的函数
   if(a.adjvex==b.adjvex)   return OK;
   else   return ERROR;
 }

 int NextAdjVex(ALGraph G,VertexType v,VertexType w)
 { // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
   // 操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点，则返回-1
   LinkList p,p1; // p1在Point()中用作辅助指针
   ElemType e;
   int v1;
   v1=LocateVex(G,v); // v1为顶点v在图G中的序号
   e.adjvex=LocateVex(G,w); // e.adjvex为顶点w在图G中的序号
   p=Point(G.vertices[v1].firstarc,e,equalvex,p1); // p指向顶点v的链表中邻接顶点为w的结点
   if(!p||!p->next)   return -1;   // 没找到w或w是最后一个邻接点    
   else // p->data.adjvex==w
     return p->next->data.adjvex; // 返回v的(相对于w的)下一个邻接顶点的序号
 } 

 Boolean visited[MAX_VERTEX_NUM]; // 访问标志数组(全局量)
 void(*VisitFunc)(char* v); // 函数变量(全局量)
 void DFS(ALGraph G,int v)
 { // 从第v个顶点出发递归地深度优先遍历图G。算法7.5
   int w;
   visited[v]=TRUE; // 设置访问标志为TRUE(已访问)
   VisitFunc(G.vertices[v].data); // 访问第v个顶点
   for(w=FirstAdjVex(G,G.vertices[v].data);w>=0;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data))
     if(!visited[w]) DFS(G,w); // 对v的尚未访问的邻接点w递归调用DFS
 }

 void DFSTraverse(ALGraph G,void(*Visit)(char*))
 { // 对图G作深度优先遍历。算法7.4
   int v;
   VisitFunc=Visit; // 使用全局变量VisitFunc，使DFS不必设函数指针参数
   for(v=0;v<G.vexnum;v++)  visited[v]=FALSE; // 访问标志数组初始化
   for(v=0;v<G.vexnum;v++)
	  {if(!visited[v])  DFS(G,v); }// 对尚未访问的顶点调用DFS
   printf("\n");
 }

 typedef int QElemType; // 队列元素类型
 // 队列的链式存储结构
 typedef struct QNode
 { QElemType data;
   QNode *next;
 }*QueuePtr;
 struct LinkQueue
 { QueuePtr front,rear;  };

// ------链队列的基本操作(4个)------
 void InitQueue(LinkQueue &Q)
 { // 构造一个空队列Q
   if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
     exit(OVERFLOW);
   Q.front->next=NULL;
 }

 Status QueueEmpty(LinkQueue Q)
 { // 若Q为空队列，则返回TRUE，否则返回FALSE
   if(Q.front->next==NULL)
     return TRUE;
   else
     return FALSE;
 }

 void EnQueue(LinkQueue &Q,QElemType e)
 { // 插入元素e为Q的新的队尾元素
   QueuePtr p;
   if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // 存储分配失败
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   Q.rear->next=p;
   Q.rear=p;
 }

 Status DeQueue(LinkQueue &Q,QElemType &e)
 { // 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
   QueuePtr p;
   if(Q.front==Q.rear)
     return ERROR;
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p)
     Q.rear=Q.front;
   free(p);
   return OK;
 }

 // ------链队列的基本操作结束------


 void BFSTraverse(ALGraph G,void(*Visit)(char*))
 {//按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。算法7.6
   int v,u,w;
   LinkQueue Q;
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; // 置初值
   InitQueue(Q); // 置空的辅助队列Q
   for(v=0;v<G.vexnum;v++) // 如果是连通图，只v=0就遍历全图
     if(!visited[v]) // v尚未访问
     { visited[v]=TRUE;
       Visit(G.vertices[v].data);
       EnQueue(Q,v); // v入队列
       while(!QueueEmpty(Q)) // 队列不空
       { DeQueue(Q,u); // 队头元素出队并置为u
         for(w=FirstAdjVex(G,G.vertices[u].data);w>=0;w=NextAdjVex(G,G.vertices[u].data,G.vertices[w].data))
           if(!visited[w]) // w为u的尚未访问的邻接顶点
           { visited[w]=TRUE;
             Visit(G.vertices[w].data);
             EnQueue(Q,w); // w入队
	   }
       }
     }
   printf("\n");
 }

 void DFS1(ALGraph G,int v,void(*Visit)(char*))
 { // 从第v个顶点出发递归地深度优先遍历图G。仅适用于邻接表存储结构
   ArcNode *p; // p指向表结点
   visited[v]=TRUE; // 设置访问标志为TRUE(已访问)
   Visit(G.vertices[v].data); // 访问该顶点
   for(p=G.vertices[v].firstarc;p;p=p->next) // p依次指向v的邻接顶点
     if(!visited[p->data.adjvex])
       DFS1(G,p->data.adjvex,Visit); // 对v的尚未访问的邻接点递归调用DFS1
 }

 void DFSTraverse1(ALGraph G,void(*Visit)(char*))
 { // 对图G作深度优先遍历。DFS1设函数指针参数
   int v;
   for(v=0;v<G.vexnum;v++)
     visited[v]=FALSE; // 访问标志数组初始化，置初值为未被访问
   for(v=0;v<G.vexnum;v++) // 如果是连通图，只v=0就遍历全图
     if(!visited[v]) // v尚未被访问
       DFS1(G,v,Visit); // 对v调用DFS1
   printf("\n");
 }

 void BFSTraverse1(ALGraph G,void(*Visit)(char*))
 { // 按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。仅适用于邻接表结构
   int v,u;
   ArcNode *p; // p指向表结点
   LinkQueue Q; // 链队列类型
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; // 置初值为未被访问
   InitQueue(Q); // 初始化辅助队列Q
   for(v=0;v<G.vexnum;v++) // 如果是连通图，只v=0就遍历全图
     if(!visited[v]) // v尚未被访问
     {
       visited[v]=TRUE; // 设v为已被访问
       Visit(G.vertices[v].data); // 访问v
       EnQueue(Q,v); // v入队列
       while(!QueueEmpty(Q)) // 队列不空
       {
         DeQueue(Q,u); // 队头元素出队并置为u
         for(p=G.vertices[u].firstarc;p;p=p->next) // p依次指向u的邻接顶点
           if(!visited[p->data.adjvex]) // u的邻接顶点尚未被访问
           {
             visited[p->data.adjvex]=TRUE; // 该邻接顶点设为已被访问
             Visit(G.vertices[p->data.adjvex].data); // 访问该邻接顶点
             EnQueue(Q,p->data.adjvex); // 入队该邻接顶点序号
           }
       }
     }
   printf("\n");
 }

 void Display(ALGraph G)
 { // 输出图的邻接矩阵G
   int i;
   ArcNode *p;
   switch(G.kind)
   { case DG: printf("有向图\n");
	      break;
     case DN: printf("有向网\n");
	      break;
     case UDG:printf("无向图\n");
	      break;
     case UDN:printf("无向网\n");
   }
   printf("%d个顶点：\n",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     printf("%s ",G.vertices[i].data);
   printf("\n%d条弧(边):\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   { p=G.vertices[i].firstarc;
     while(p)
     {if(G.kind<=1||i<p->data.adjvex) // 有向或无向两次中的一次
       { printf("%s→%s ",G.vertices[i].data,G.vertices[p->data.adjvex].data);
         if(G.kind%2) // 网
            printf(":%d ",*(p->data.info));
       }
       p=p->nextarc;
     }
     printf("\n");
   }
 }
 //*********邻接表存储结构的基本操作结束*********


 void visit(char *i)
 { printf("%s ",i);
 }

 void main()
 { ALGraph g;
   CreateGraphF(g); // 利用数据文件创建无向图
   Display(g); // 输出无向图
   printf("深度优先搜索的结果:\n");
   DFSTraverse(g,visit); 
   DFSTraverse1(g,visit); 
   printf("广度优先搜索的结果:\n");
   BFSTraverse(g,visit); 
   BFSTraverse1(g,visit); 
   DestroyGraph(g); 
 }

