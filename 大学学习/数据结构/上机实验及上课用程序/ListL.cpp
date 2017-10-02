  //ListL.cpp
 #include<string.h> 
 #include<malloc.h> // malloc()等 
 #include<stdio.h> // EOF(=^Z或F6),NULL 
 #include<math.h> // floor(),ceil(),abs(),OVERFLOW
 #include<process.h> // exit()
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 typedef int ElemType;

 typedef struct LNode   // 线性表的单链表存储结构
 { ElemType  data;
   LNode *next;
 }LNode,*LinkList; 

 void print(ElemType c)
 {   printf("%d ",c);
 }

//带有头结点的单链表的基本操作,包括算法2.8,算法2.9,算法2.10
 void InitList_L(LinkList &L)
 { // 操作结果：构造一个空的线性表L
   L=(LinkList)malloc(sizeof(LNode)); // 产生头结点，并使L指向此头结点
   if(!L) exit(OVERFLOW); // 存储分配失败     
   L->next=NULL; // 指针域为空
 }

 void DestroyList_L(LinkList &L)
 { // 初始条件：线性表L已存在。操作结果：销毁线性表L
   LinkList q;
   while(L)
   { q=L->next;
     free(L);
     L=q;
   }
 }

 void ClearList_L(LinkList L) // 不改变L
 { // 初始条件：线性表L已存在。操作结果：将L重置为空表
   LinkList p,q;
   p=L->next; // p指向第一个结点
   while(p) // 没到表尾
   { q=p->next;
     free(p);
     p=q;
   }
   L->next=NULL; // 头结点指针域为空
 }

 int ListLength_L(LinkList L)
 { // 初始条件：线性表L已存在。操作结果：返回L中数据元素个数
   int i=0;
   LinkList p=L->next; // p指向第一个结点
   while(p) // 没到表尾
   { i++;
     p=p->next;
   }
   return i; 
 }

 Status GetElem_L(LinkList L,int i,ElemType &e) // 算法2.8
 { // L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
   LinkList p=L->next; // p指向第一个结点
   int j=1; // j为计数器
   while(p&&j<i) // 顺指针向后查找，直到p指向第i个元素或p为空
   { p=p->next;
     j++;
   }
   if(!p||j>i) // 第i个元素不存在
     return ERROR;
   e=p->data; // 取第i个元素
   return OK;
 } 

 Status ListInsert_L(LinkList L,int i,ElemType e) // 算法2.9。不改变L
 { // 在带头结点的单链线性表L中第i个位置之前插入元素e
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) // 寻找第i-1个结点
   { p=p->next;
     j++;
   }
   if(!p||j>i-1)  return ERROR; // i小于1或者大于表长    
   s=(LinkList)malloc(sizeof(LNode)); // 生成新结点
   s->data=e; // 插入L中
   s->next=p->next;
   p->next=s;
   return OK;
 }

 Status ListDelete_L(LinkList L,int i,ElemType &e) // 算法2.10。不改变L
 { // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) // 寻找第i个结点，并令p指向其前驱
   { p=p->next;
     j++;
   }
   if(!p->next||j>i-1)  return ERROR;   // 删除位置不合理    
   q=p->next; // 删除并释放结点
   p->next=q->next;
   e=q->data;
   free(q);
   return OK;
 }

 void ListTraverse_L(LinkList L,void(*vi)(ElemType))
 // vi的形参类型为ElemType，与bo2-1.cpp中相应函数的形参类型ElemType&不同
 { // 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()
   LinkList p=L->next;
   while(p)
   { vi(p->data);
     p=p->next;
   }
   printf("\n");
 } 
 

 void main()
 { LinkList L;    ElemType e;   Status i;   int j,k;
   InitList_L(L);
   for(j=1;j<=5;j++)  i=ListInsert_L(L,1,j);
   printf("在L的表头依次插入1～5后：L=");
   ListTraverse_L(L,print); // 依次对元素调用print()，输出元素的值 
   ClearList_L(L);
   printf("清空L后：L=");
   ListTraverse_L(L,print); 
   for(j=1;j<=10;j++)  ListInsert_L(L,j,j);
   printf("在L的表尾依次插入1～10后：L=");
   ListTraverse_L(L,print);
   GetElem_L(L,5,e);
   printf("第5个元素的值为：%d\n",e);  
   k=ListLength_L(L); // k为表长   
   for(j=k+1;j>=k;j--)
   { i=ListDelete_L(L,j,e); // 删除第j个数据
     if(i==ERROR)  printf("删除第%d个元素失败\n",j);
     else printf("删除第%d个元素成功，其值为：%d\n",j,e);
   }
   printf("依次输出L的元素：");
   ListTraverse_L(L,print);
   DestroyList_L(L);
   printf("销毁L后：L=%u\n",L);
 }