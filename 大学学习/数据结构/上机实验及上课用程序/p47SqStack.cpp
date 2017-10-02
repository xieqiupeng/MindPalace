  // p47SqStack.cpp  栈的顺序存储
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

 typedef int SElemType; // 定义栈元素类型

 // 栈的顺序存储表示
 #define STACK_INIT_SIZE 10 // 存储空间初始分配量
 #define STACK_INCREMENT 2 // 存储空间分配增量
 struct SqStack
 { SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
   SElemType *top; // 栈顶指针
   int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈

 
 // 顺序栈的基本操作
 void InitStack(SqStack &S)
 { // 构造一个空栈S
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // 存储分配失败
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }

 Status GetTop(SqStack S,SElemType &e)
 { // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
   if(S.top>S.base)   { e=*(S.top-1);     return OK;   }
   else     return ERROR;
 }

 void Push(SqStack &S,SElemType e)
 { // 插入元素e为新的栈顶元素
   if(S.top-S.base>=S.stacksize) // 栈满，追加存储空间
   {
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)   exit(OVERFLOW); // 存储分配失败
     S.top=S.base+S.stacksize;
     S.stacksize+=STACK_INCREMENT;
   }
   *(S.top)++=e;
 }

 Status Pop(SqStack &S,SElemType &e)
 { // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
   if(S.top==S.base)
     return ERROR;
   e=*--S.top;
   return OK;
 }

void StackTraverse(SqStack S,void(*visit)(SElemType))
 { // 从栈底到栈顶依次对栈中每个元素调用函数visit()
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
 }

void visit(SElemType c)
 {   printf("%d ",c);
 }

 void main()
 { int i;   SqStack s;   SElemType e;
   InitStack(s);
   for(i=1;i<=10;i++)  Push(s,i);
   printf("栈中元素依次为：");
   StackTraverse(s,visit);
   Pop(s,e);
   printf("弹出的栈顶元素为 e=%d\n",e);   
   GetTop(s,e);   
   printf("取的栈顶元素为 e=%d \n",e);     
 }
