// Evaluate.cpp 表达式求值(输入的值在0～9之间，中间结果和输出的值在-128～127之间)，算法3.4
 #include<string.h> 
 #include<malloc.h> // malloc()等
 #include<stdio.h> // EOF,NULL 
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0 
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
 typedef char SElemType; // 栈元素为字符型
  
 #define STACK_INIT_SIZE 10 // 存储空间初始分配量
 #define STACK_INCREMENT 2 // 存储空间分配增量
 struct SqStack  // 顺序栈
 { SElemType *base; 
   SElemType *top; 
   int stacksize; 
 };

 // 顺序栈的基本操作(5个)
 void InitStack(SqStack &S)
 { // 构造一个空栈S
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // 存储分配失败
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }
 
 Status StackEmpty(SqStack S)
 { // 若栈S为空栈，则返回TRUE，否则返回FALSE
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 } 

 Status GetTop(SqStack S,SElemType &e)
 { // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
   if(S.top>S.base)
   {
     e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 void Push(SqStack &S,SElemType e)
 { // 插入元素e为新的栈顶元素
   if(S.top-S.base>=S.stacksize) // 栈满，追加存储空间
   {
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)
       exit(OVERFLOW); // 存储分配失败
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

// 根据教材表3.1，判断t1，t2两符号的优先关系('#'用'\n'代替)
 char Precede(SElemType t1,SElemType t2)
 { char f;
   switch(t2)
   { case '+':
     case '-':if(t1=='('||t1=='\n')
                f='<'; // t1<t2
              else
                f='>'; // t1>t2
              break;
     case '*':
     case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>'; // t1>t2
              else
                f='<'; // t1<t2
              break;
     case '(':if(t1==')')
              {
                printf("括号不匹配\n");
                exit(ERROR);
              }
              else
                f='<'; // t1<t2
              break;
     case ')':switch(t1)
              {
                case '(':f='='; // t1=t2
                         break;
                case'\n':printf("缺乏左括号\n");
                         exit(ERROR);
                         default :f='>'; // t1>t2
              }
              break;
     case'\n':switch(t1)
              {
                case'\n':f='='; // t1=t2
                         break;
                case'(' :printf("缺乏右括号\n");
                         exit(ERROR);
                default :f='>'; // t1>t2
              }
   }
   return f;
 }

 Status In(SElemType c)  // 判断c是否为7种运算符之一
 {   switch(c)
   { case'+' :
     case'-' :
     case'*' :
     case'/' :
     case'(' :
     case')' :
     case'\n':return TRUE;
     default :return FALSE;
   }
 }

 SElemType Operate(SElemType a,SElemType theta,SElemType b)
 { // 做四则运算a theta b，返回运算结果
   switch(theta)
   { case'+':return a+b;
     case'-':return a-b;
     case'*':return a*b;
   }
   return a/b;
 }


// 算法3.4. 算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈，略有改动
 SElemType EvaluateExpression() 
 { SqStack OPTR,OPND;
   SElemType a,b,c,x;
   InitStack(OPTR); // 初始化运算符栈OPTR和运算数栈OPND
   InitStack(OPND);
   Push(OPTR,'\n'); // 将换行符压入运算符栈OPTR的栈底(改)
   c=getchar(); // 由键盘读入1个字符到c
   GetTop(OPTR,x); // 将运算符栈OPTR的栈顶元素赋给x
   while(c!='\n'||x!='\n') // c和x不都是换行符
   {   if(In(c)) // c是7种运算符之一
       switch(Precede(x,c)) // 判断x和c的优先权
       {
         case'<' :Push(OPTR,c); // 栈顶元素x的优先权低，入栈c
                  c=getchar();  // 由键盘读入下一个字符到c
                  break;
         case'=' :Pop(OPTR,x); // x='('且c=')'情况，弹出'('给x(后又扔掉)
                  c=getchar(); // 由键盘读入下一个字符到c(扔掉')')
                  break;
         case'>' :Pop(OPTR,x); // 栈顶元素x的优先权高，弹出运算符栈OPTR的栈顶元素给x(改)
                  Pop(OPND,b); // 依次弹出运算数栈OPND的栈顶元素给b，a
                  Pop(OPND,a);
                  Push(OPND,Operate(a,x,b)); // 做运算a x b，并将运算结果入运算数栈
       }
     else if(c>='0'&&c<='9') // c是操作数
     {
       Push(OPND,c-48); // 将该操作数的值(不是ASCII码)压入运算数栈OPND
       c=getchar(); // 由键盘读入下一个字符到c
     }
     else // c是非法字符
     {
       printf("出现非法字符\n");
       exit(ERROR);
     }
     GetTop(OPTR,x); // 将运算符栈OPTR的栈顶元素赋给x
   }
   Pop(OPND,x); // 弹出运算数栈OPND的栈顶元素(运算结果)给x(改此处)
   if(!StackEmpty(OPND)) // 运算数栈OPND不空(运算符栈OPTR仅剩'\n')
   {
     printf("表达式不正确\n");
     exit(ERROR);
   }
   return x;
 }

 void main()
 {
   printf("请输入算术表达式(输入的值要在0～9之间、中间运算值和输出结果在-128～127之间)\n");
   printf("%d\n",EvaluateExpression()); // 返回值(8位2进制，1个字节)按整型格式输出
 }
