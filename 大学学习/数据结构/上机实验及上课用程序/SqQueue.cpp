 // SqQueue.cpp 循环队列，实现教材P64-P65的基本操作
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

 typedef int QElemType; // 定义队列元素类型

//队列的顺序存储结构(循环队列)
 #define MAX_QSIZE 5 // 最大队列长度+1
 struct SqQueue
 { QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针，若队列不空，指向队列头元素
   int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
 };
 
  // 循环队列的基本操作(教材P64-P65的基本操作)
 void InitQueue(SqQueue &Q)
 { // 构造一个空队列Q
   Q.base=(QElemType *)malloc(MAX_QSIZE*sizeof(QElemType));
   if(!Q.base) // 存储分配失败
     exit(OVERFLOW);
   Q.front=Q.rear=0;
 }

 int QueueLength(SqQueue Q)
 { // 返回Q的元素个数，即队列的长度
   return(Q.rear-Q.front+MAX_QSIZE)%MAX_QSIZE;
 }

 Status EnQueue(SqQueue &Q,QElemType e)
 { // 插入元素e为Q的新的队尾元素
   if((Q.rear+1)%MAX_QSIZE==Q.front) // 队列满
     return ERROR;
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAX_QSIZE;
   return OK;
 }

 Status DeQueue(SqQueue &Q,QElemType &e)
 { // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
   if(Q.front==Q.rear) // 队列空
     return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAX_QSIZE;
   return OK;
 }

 void QueueTraverse(SqQueue Q,void(*visit)(QElemType))
 { // 从队头到队尾依次对队列Q中每个元素调用函数vi()
   int i;
   i=Q.front;
   while(i!=Q.rear)
   {
     visit(Q.base[i]);
     i=(i+1)%MAX_QSIZE;
   }
   printf("\n");
 }

 void print(QElemType i)
 { printf("%d ",i);
 }

 void main()
 { int i=0,l;   QElemType d;   SqQueue Q;
   InitQueue(Q);  
   printf("请输入整型队列元素(不超过%d个),元素间用空格分隔，-1为提前结束符: ",MAX_QSIZE-1);
   do
   { scanf("%d",&d);
     if(d==-1)  break;
     i++;
     EnQueue(Q,d);
   }while(i<MAX_QSIZE-1);
   printf("队列长度为: %d\n",QueueLength(Q));  
   printf("连续%d次由队头删除元素,队尾插入元素:\n",MAX_QSIZE);
   for(l=1;l<=MAX_QSIZE;l++)
   { DeQueue(Q,d);
     printf("删除的元素是%d,请输入待插入的元素: ",d);
     scanf("%d",&d);
     EnQueue(Q,d);
   }
   l=QueueLength(Q);
   printf("现在队列中的元素为:\n");
   QueueTraverse(Q,print);
   printf("共向队尾插入了%d个元素\n",i+MAX_QSIZE);
   if(l-2>0)
     printf("现在由队头删除%d个元素: \n",l-2);
   while(QueueLength(Q)>2)
   { DeQueue(Q,d);
     printf("删除的元素值为%d\n",d);
   }   
 }