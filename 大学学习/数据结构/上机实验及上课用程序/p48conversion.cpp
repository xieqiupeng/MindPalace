 // p48conversion.cpp 数字转换程序 
 #include<string.h> 
 #include<malloc.h> // malloc()等 
 #include<stdio.h> // EOF(=^Z或F6),NULL 
 #include<math.h> // floor(),ceil(),abs(),OVERFLOW
 #include<process.h> // exit()
 #include<iostream.h> 
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 #define N 8 // 定义待转换的进制N(2～9)
 typedef int SElemType; // 定义栈元素类型为整型 
 
 // 栈的顺序存储表示
 #define STACK_INIT_SIZE 10 // 存储空间初始分配量
 #define STACK_INCREMENT 2 // 存储空间分配增量
 struct SqStack
 { SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
   SElemType *top; // 栈顶指针
   int stacksize; // 当前已分配的存储空间，以元素为单位
 }; 

 // 顺序栈的基本操作
 void InitStack(SqStack &S)
 { // 构造一个空栈S
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // 存储分配失败
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }

 Status StackEmpty(SqStack S)
 { // 若栈S为空栈，则返回TRUE，否则返回FALSE
   if(S.top==S.base)    return TRUE;
   else    return FALSE;
 }

 void Push(SqStack &S,SElemType e)
 { // 插入元素e为新的栈顶元素
   if(S.top-S.base>=S.stacksize) // 栈满，追加存储空间
   { S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)   exit(OVERFLOW); // 存储分配失败
     S.top=S.base+S.stacksize;
     S.stacksize+=STACK_INCREMENT;
   }
   *(S.top)++=e;
 }

 Status Pop(SqStack &S,SElemType &e)
 { // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
   if(S.top==S.base)   return ERROR;
   e=*--S.top;
   return OK;
 }

 void conversion() // (教材P48算法3.1)
 { // 对于输入的任意一个非负10进制整数，打印输出与其等值的N进制数
   SqStack s;
   unsigned n; // 非负整数
   SElemType e;
   InitStack(s); // 初始化栈
   cout<<"将10进制整数n转换为8进制数，请输入：n (>=0) ="<<ends;
   cin>>n; // 输入非负十进制整数n
   while(n) // 当n不等于0
   { Push(s,n%N); // 入栈n除以N的余数(N进制的低位)
     n=n/N;
   }
   while(!StackEmpty(s)) // 当栈不空
   { Pop(s,e); // 弹出栈顶元素且赋值给e
     cout<<e; // 输出e
   }
   cout<<"\n";
 }

 void main()
 {   conversion();
 }

 
 /*运行结果：
   将10进制整数n转换为8进制数，请输入：n (>=0) = 1348 
   2504

       */