 // p61LinkQueue.cpp 队列的链式存储
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
 typedef int QlemType; 
 
 typedef int QElemType;
 //单链队列－－队列的链式存储结构
 typedef struct QNode
 { QElemType data;
   QNode *next;
 }*QueuePtr;
 struct LinkQueue
 { QueuePtr front,rear; // 队头、队尾指针
 };

// 链队列的基本操作
 void InitQueue(LinkQueue &Q)
 { // 构造一个空队列Q
   if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
     exit(OVERFLOW);
   Q.front->next=NULL;
 }

 void DestroyQueue(LinkQueue &Q)
 { // 销毁队列Q(无论空否均可)
   while(Q.front)
   {
     Q.rear=Q.front->next;
     free(Q.front);
     Q.front=Q.rear;
   }
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

 void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
 { // 从队头到队尾依次对队列Q中每个元素调用函数vi()
   QueuePtr p;
   p=Q.front->next;
   while(p)
   { vi(p->data);
     p=p->next;
   }
   printf("\n");
 }

 void visit(QElemType i)
 { printf("%d ",i);
 }

 void main()
 { QElemType d;
   LinkQueue q;
   InitQueue(q);
   printf("成功地构造了一个空队列!\n");   
   EnQueue(q,-5);
   EnQueue(q,5);
   EnQueue(q,10);  
   printf("插入3个元素(-5,5,10)后,队列的元素依次为：");
   QueueTraverse(q,visit);
   DeQueue(q,d);
   printf("删除了队头元素%d\n",d);   
   DestroyQueue(q);
   printf("销毁队列后,q.front=%u q.rear=%u\n",q.front, q.rear);
 }