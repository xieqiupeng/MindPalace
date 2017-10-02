 //DFS&BFS.cpp  ���ڽӱ�ʵ�ֵ�������Ⱥ͹�����ȵĳ���

 #include<string.h> 
 #include<malloc.h> 
 #include<stdio.h> 
 #include<math.h> 
 #include<process.h> 
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; 
 typedef int Boolean; 

 #define MAX_NAME 5 // �����ַ�������󳤶�+1
 typedef int InfoType; // ����Ȩֵ����
 typedef char VertexType[MAX_NAME]; // ��������Ϊ�ַ���

  // ������ͼ���ڽӱ�洢��ʾ(�뵥����ı������ͽ�����ϵ)
 #define MAX_VERTEX_NUM 20
 enum GraphKind{DG,DN,UDG,UDN}; // {����ͼ,������,����ͼ,������}
 struct ElemType // �¼ӵ�
 { int adjvex; // �û���ָ��Ķ����λ��
   InfoType *info; // ����Ȩֵָ��
 };
 struct ArcNode // // ���㡣 �иĶ�
 { ElemType data; // ��ָ������Ĳ��ֶ�����ElemType
   ArcNode *nextarc; // ָ����һ������ָ��
 }; 
 typedef struct  // ͷ���
 { VertexType data; // ������Ϣ
   ArcNode *firstarc; // ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ��
 }VNode,AdjList[MAX_VERTEX_NUM]; 
 struct ALGraph
 { AdjList vertices;
   int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ���
   GraphKind kind; // ͼ�������־
 };  // ͼ���ڽӱ�洢��ʾ

 #define LNode ArcNode // �¼ӵġ����嵥����Ľ��������ͼ�ı��������
 #define next nextarc // �¼ӵġ����嵥�������ָ�����Ǳ���ָ����һ������ָ����
 typedef ArcNode *LinkList; // �¼ӵġ�����ָ���������ָ����ָ��ͼ�ı����ָ��

 //*********�ڽӱ�洢�ṹ�Ļ���������ʼ*********
//  ͼ���ڽӱ�洢�Ļ����������Լ��㷨7.4��7.6
 
// ------����ͷ���ĵ�����Ĳ��ֻ�������(5��) ------
 #define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ����
 
 void ClearList(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p;
   while(L) // L����
   { p=L; // pָ����Ԫ���
     L=L->next; // Lָ���2�����(����Ԫ���)
     free(p); // �ͷ���Ԫ���
   }
 }

 int ListLength(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
   int i=0;
   LinkList p=L;
   while(p) // pָ����(û����β)
   { p=p->next; // pָ����һ�����
     i++;
   }
   return i;
 }
 
 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0;
   LinkList p=L;
   while(p)
   { i++;
     if(compare(p->data,e)) return i; // �ҵ�����������Ԫ��       
     p=p->next;
   }
   return 0;
 }

 Status ListInsert(LinkList &L,int i,ElemType e)
 { // �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
   int j=1;
   LinkList p=L,s;
   if(i<1) return ERROR; // iֵ���Ϸ�     
   s=(LinkList)malloc(sizeof(LNode)); // �����½��
   s->data=e; // ��s��data��ֵ
   if(i==1) // ���ڱ�ͷ
   { s->next=L;
     L=s; // �ı�L
   }
   else   // ���ڱ�����ദ
   { while(p&&j<i-1) // Ѱ�ҵ�i-1�����
      { p=p->next;
       j++;
	  }
     if(!p) return ERROR;  // i���ڱ�+1       
     s->next=p->next;
     p->next=s;
   }
   return OK;
 }

 Status ListDelete(LinkList &L,int i,ElemType &e)
 { // �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
   int j=1;
   LinkList p=L,q;
   if(i==1) // ɾ����1�����
   { L=p->next; // L�ɵ�2����㿪ʼ
     e=p->data;
     free(p); // ɾ�����ͷŵ�1�����
   }
   else
   {while(p->next&&j<i-1) // Ѱ�ҵ�i����㣬����pָ����ǰ��
     { p=p->next;
       j++;
     }
     if(!p->next||j>i-1)  return ERROR;  // ɾ��λ�ò�����      
     q=p->next; // ɾ�����ͷŽ��
     p->next=q->next;
     e=q->data;
     free(q);
   }
   return OK;
 }
 // ------����ͷ���ĵ����������������------

//------ �����ǲ���ͷ���ĵ��������չ����(3��)------
void InsertAscend(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType))
 { // ���ؼ��ַǽ���e�����L������compare()����ֵΪ���β�1�Ĺؼ���-�β�2�Ĺؼ���
   LinkList q=L;
   if(!L||compare(e,L->data)<=0) // ����ջ�e�Ĺؼ���С�ڵ����׽��Ĺؼ���
     ListInsert(L,1,e); // ��e���ڱ�ͷ����bo2-8.cpp��
   else
   { while(q->next&&compare(q->next->data,e)<0) // q����β�����q����һ���ؼ���<e�Ĺؼ���
         q=q->next;
     ListInsert(q,2,e); // ����q��ָ����(��q��Ϊͷָ��)
   }
 }

 LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
 { // ���ұ�L�����������Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��(���ý����
   // ��Ԫ��㣬��p=NULL)�����L�������������Ľ�㣬�򷵻�NULL��p�޶��塣
   // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
   int i,j;
   i=LocateElem(L,e,equal);
   if(i) // �ҵ�
   {if(i==1) // ����Ԫ���
     { p=NULL;
       return L;
     }
     p=L;
     for(j=2;j<i;j++)  p=p->next;
     return p->next;
   }
   return NULL; // û�ҵ�
 }

 Status DeleteElem(LinkList &L,ElemType &e,Status(*equal)(ElemType,ElemType))
 { // ɾ����L�����������Ľ�㣬������TRUE�����޴˽�㣬�򷵻�FALSE��
   // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
   LinkList p,q;
   q=Point(L,e,equal,p);
   if(q) // �ҵ��˽�㣬��qָ��ý��
   { if(p) // �ý�㲻����Ԫ��㣬pָ����ǰ��
       ListDelete(p,2,e); // ��p��Ϊͷָ��,ɾ����2�����
     else  ListDelete(L,1,e);   // �ý������Ԫ���       
     return TRUE;
   }
   return FALSE;
 }

//------ ����ͷ���ĵ�������չ��������------


 int LocateVex(ALGraph G,VertexType u)
 { // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
   // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1
   int i;
   for(i=0;i<G.vexnum;++i)
	   {if(strcmp(u,G.vertices[i].data)==0) return i;}
   return -1;
 }

 void CreateGraphF(ALGraph &G)
 { // �����ڽӱ�洢�ṹ�����ļ�����û�������Ϣͼ����G(��һ����������4��ͼ)
   int i,j,k,w; // w��Ȩֵ
   VertexType va,vb; // ���ӱ߻򻡵�2����
   ElemType e;
   char filename[13];
   FILE *graphlist;
   printf("�����������ļ���(f7-1.txt��f7-2.txt)��");
   scanf("%s",filename);
   printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
   scanf("%d",&G.kind);
   graphlist=fopen(filename,"r"); // �Զ��ķ�ʽ�������ļ�������graphlist��ʾ
   fscanf(graphlist,"%d",&G.vexnum);
   fscanf(graphlist,"%d",&G.arcnum);
   for(i=0;i<G.vexnum;++i) // ���춥������
   { fscanf(graphlist,"%s",G.vertices[i].data);
     G.vertices[i].firstarc=NULL; // ��ʼ����ö����йصĳ�������
   }
   for(k=0;k<G.arcnum;++k) // ������ػ�����
   { if(G.kind%2) fscanf(graphlist,"%d%s%s",&w,va,vb);// ��
     else fscanf(graphlist,"%s%s",va,vb);  // ͼ
     i=LocateVex(G,va); // ��β
     j=LocateVex(G,vb); // ��ͷ
     e.info=NULL; // ���������e��ֵ��ͼ��Ȩ
     e.adjvex=j; // ��ͷ
     if(G.kind%2) // ��
     { e.info=(int *)malloc(sizeof(int)); // ��̬���ɴ��Ȩֵ�Ŀռ�
       *(e.info)=w;
     }
     ListInsert(G.vertices[i].firstarc,1,e); // ���ڵ�i��Ԫ��(����)�ı�ͷ
     if(G.kind>=2) // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
     { e.adjvex=i; // e.info���䣬�����ٸ�ֵ
       ListInsert(G.vertices[j].firstarc,1,e); // ���ڵ�j��Ԫ�صı�ͷ
     }
   }
   fclose(graphlist); // �ر������ļ�
 }

 void DestroyGraph(ALGraph &G)
 { // ��ʼ������ͼG���ڡ��������������ͼG
   int i;
   ElemType e;
   for(i=0;i<G.vexnum;++i) // �������ж���
     if(G.kind%2) // ��
       while(G.vertices[i].firstarc) // ��Ӧ�Ļ����������
       {ListDelete(G.vertices[i].firstarc,1,e); // ɾ������ĵ�1����㣬����ֵ����e
	    if(e.adjvex>i)  free(e.info);   // �������>i(��֤��̬���ɵ�Ȩֵ�ռ�ֻ�ͷ�1��)	   
       }
     else  DestroyList(G.vertices[i].firstarc); // ͼ�� ���ٻ��������
   G.vexnum=0; // ������Ϊ0
   G.arcnum=0; // �߻���Ϊ0
 }

 int FirstAdjVex(ALGraph G,VertexType v)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ������
   // �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
   ArcNode *p;
   int v1;
   v1=LocateVex(G,v); // v1Ϊ����v��ͼG�е����
   p=G.vertices[v1].firstarc;
   if(p)  return p->data.adjvex;
   else   return -1;
 }

 Status equalvex(ElemType a,ElemType b)
 { // DeleteArc()��DeleteVex()��NextAdjVex()Ҫ���õĺ���
   if(a.adjvex==b.adjvex)   return OK;
   else   return ERROR;
 }

 int NextAdjVex(ALGraph G,VertexType v,VertexType w)
 { // ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
   // �������������v��(�����w��)��һ���ڽӶ������š���w��v�����һ���ڽӵ㣬�򷵻�-1
   LinkList p,p1; // p1��Point()����������ָ��
   ElemType e;
   int v1;
   v1=LocateVex(G,v); // v1Ϊ����v��ͼG�е����
   e.adjvex=LocateVex(G,w); // e.adjvexΪ����w��ͼG�е����
   p=Point(G.vertices[v1].firstarc,e,equalvex,p1); // pָ�򶥵�v���������ڽӶ���Ϊw�Ľ��
   if(!p||!p->next)   return -1;   // û�ҵ�w��w�����һ���ڽӵ�    
   else // p->data.adjvex==w
     return p->next->data.adjvex; // ����v��(�����w��)��һ���ڽӶ�������
 } 

 Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)
 void(*VisitFunc)(char* v); // ��������(ȫ����)
 void DFS(ALGraph G,int v)
 { // �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5
   int w;
   visited[v]=TRUE; // ���÷��ʱ�־ΪTRUE(�ѷ���)
   VisitFunc(G.vertices[v].data); // ���ʵ�v������
   for(w=FirstAdjVex(G,G.vertices[v].data);w>=0;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data))
     if(!visited[w]) DFS(G,w); // ��v����δ���ʵ��ڽӵ�w�ݹ����DFS
 }

 void DFSTraverse(ALGraph G,void(*Visit)(char*))
 { // ��ͼG��������ȱ������㷨7.4
   int v;
   VisitFunc=Visit; // ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
   for(v=0;v<G.vexnum;v++)  visited[v]=FALSE; // ���ʱ�־�����ʼ��
   for(v=0;v<G.vexnum;v++)
	  {if(!visited[v])  DFS(G,v); }// ����δ���ʵĶ������DFS
   printf("\n");
 }

 typedef int QElemType; // ����Ԫ������
 // ���е���ʽ�洢�ṹ
 typedef struct QNode
 { QElemType data;
   QNode *next;
 }*QueuePtr;
 struct LinkQueue
 { QueuePtr front,rear;  };

// ------�����еĻ�������(4��)------
 void InitQueue(LinkQueue &Q)
 { // ����һ���ն���Q
   if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
     exit(OVERFLOW);
   Q.front->next=NULL;
 }

 Status QueueEmpty(LinkQueue Q)
 { // ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
   if(Q.front->next==NULL)
     return TRUE;
   else
     return FALSE;
 }

 void EnQueue(LinkQueue &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   QueuePtr p;
   if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // �洢����ʧ��
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   Q.rear->next=p;
   Q.rear=p;
 }

 Status DeQueue(LinkQueue &Q,QElemType &e)
 { // �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
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

 // ------�����еĻ�����������------


 void BFSTraverse(ALGraph G,void(*Visit)(char*))
 {//��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited���㷨7.6
   int v,u,w;
   LinkQueue Q;
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; // �ó�ֵ
   InitQueue(Q); // �ÿյĸ�������Q
   for(v=0;v<G.vexnum;v++) // �������ͨͼ��ֻv=0�ͱ���ȫͼ
     if(!visited[v]) // v��δ����
     { visited[v]=TRUE;
       Visit(G.vertices[v].data);
       EnQueue(Q,v); // v�����
       while(!QueueEmpty(Q)) // ���в���
       { DeQueue(Q,u); // ��ͷԪ�س��Ӳ���Ϊu
         for(w=FirstAdjVex(G,G.vertices[u].data);w>=0;w=NextAdjVex(G,G.vertices[u].data,G.vertices[w].data))
           if(!visited[w]) // wΪu����δ���ʵ��ڽӶ���
           { visited[w]=TRUE;
             Visit(G.vertices[w].data);
             EnQueue(Q,w); // w���
	   }
       }
     }
   printf("\n");
 }

 void DFS1(ALGraph G,int v,void(*Visit)(char*))
 { // �ӵ�v����������ݹ��������ȱ���ͼG�����������ڽӱ�洢�ṹ
   ArcNode *p; // pָ�����
   visited[v]=TRUE; // ���÷��ʱ�־ΪTRUE(�ѷ���)
   Visit(G.vertices[v].data); // ���ʸö���
   for(p=G.vertices[v].firstarc;p;p=p->next) // p����ָ��v���ڽӶ���
     if(!visited[p->data.adjvex])
       DFS1(G,p->data.adjvex,Visit); // ��v����δ���ʵ��ڽӵ�ݹ����DFS1
 }

 void DFSTraverse1(ALGraph G,void(*Visit)(char*))
 { // ��ͼG��������ȱ�����DFS1�躯��ָ�����
   int v;
   for(v=0;v<G.vexnum;v++)
     visited[v]=FALSE; // ���ʱ�־�����ʼ�����ó�ֵΪδ������
   for(v=0;v<G.vexnum;v++) // �������ͨͼ��ֻv=0�ͱ���ȫͼ
     if(!visited[v]) // v��δ������
       DFS1(G,v,Visit); // ��v����DFS1
   printf("\n");
 }

 void BFSTraverse1(ALGraph G,void(*Visit)(char*))
 { // ��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited�����������ڽӱ�ṹ
   int v,u;
   ArcNode *p; // pָ�����
   LinkQueue Q; // ����������
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; // �ó�ֵΪδ������
   InitQueue(Q); // ��ʼ����������Q
   for(v=0;v<G.vexnum;v++) // �������ͨͼ��ֻv=0�ͱ���ȫͼ
     if(!visited[v]) // v��δ������
     {
       visited[v]=TRUE; // ��vΪ�ѱ�����
       Visit(G.vertices[v].data); // ����v
       EnQueue(Q,v); // v�����
       while(!QueueEmpty(Q)) // ���в���
       {
         DeQueue(Q,u); // ��ͷԪ�س��Ӳ���Ϊu
         for(p=G.vertices[u].firstarc;p;p=p->next) // p����ָ��u���ڽӶ���
           if(!visited[p->data.adjvex]) // u���ڽӶ�����δ������
           {
             visited[p->data.adjvex]=TRUE; // ���ڽӶ�����Ϊ�ѱ�����
             Visit(G.vertices[p->data.adjvex].data); // ���ʸ��ڽӶ���
             EnQueue(Q,p->data.adjvex); // ��Ӹ��ڽӶ������
           }
       }
     }
   printf("\n");
 }

 void Display(ALGraph G)
 { // ���ͼ���ڽӾ���G
   int i;
   ArcNode *p;
   switch(G.kind)
   { case DG: printf("����ͼ\n");
	      break;
     case DN: printf("������\n");
	      break;
     case UDG:printf("����ͼ\n");
	      break;
     case UDN:printf("������\n");
   }
   printf("%d�����㣺\n",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     printf("%s ",G.vertices[i].data);
   printf("\n%d����(��):\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   { p=G.vertices[i].firstarc;
     while(p)
     {if(G.kind<=1||i<p->data.adjvex) // ��������������е�һ��
       { printf("%s��%s ",G.vertices[i].data,G.vertices[p->data.adjvex].data);
         if(G.kind%2) // ��
            printf(":%d ",*(p->data.info));
       }
       p=p->nextarc;
     }
     printf("\n");
   }
 }
 //*********�ڽӱ�洢�ṹ�Ļ�����������*********


 void visit(char *i)
 { printf("%s ",i);
 }

 void main()
 { ALGraph g;
   CreateGraphF(g); // ���������ļ���������ͼ
   Display(g); // �������ͼ
   printf("������������Ľ��:\n");
   DFSTraverse(g,visit); 
   DFSTraverse1(g,visit); 
   printf("������������Ľ��:\n");
   BFSTraverse(g,visit); 
   BFSTraverse1(g,visit); 
   DestroyGraph(g); 
 }

