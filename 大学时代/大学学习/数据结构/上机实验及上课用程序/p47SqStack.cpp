  // p47SqStack.cpp  ջ��˳��洢
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

 typedef int SElemType; // ����ջԪ������

 // ջ��˳��洢��ʾ
 #define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
 #define STACK_INCREMENT 2 // �洢�ռ��������
 struct SqStack
 { SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
   SElemType *top; // ջ��ָ��
   int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
 }; // ˳��ջ

 
 // ˳��ջ�Ļ�������
 void InitStack(SqStack &S)
 { // ����һ����ջS
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // �洢����ʧ��
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }

 Status GetTop(SqStack S,SElemType &e)
 { // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
   if(S.top>S.base)   { e=*(S.top-1);     return OK;   }
   else     return ERROR;
 }

 void Push(SqStack &S,SElemType e)
 { // ����Ԫ��eΪ�µ�ջ��Ԫ��
   if(S.top-S.base>=S.stacksize) // ջ����׷�Ӵ洢�ռ�
   {
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)   exit(OVERFLOW); // �洢����ʧ��
     S.top=S.base+S.stacksize;
     S.stacksize+=STACK_INCREMENT;
   }
   *(S.top)++=e;
 }

 Status Pop(SqStack &S,SElemType &e)
 { // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(S.top==S.base)
     return ERROR;
   e=*--S.top;
   return OK;
 }

void StackTraverse(SqStack S,void(*visit)(SElemType))
 { // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()
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
   printf("ջ��Ԫ������Ϊ��");
   StackTraverse(s,visit);
   Pop(s,e);
   printf("������ջ��Ԫ��Ϊ e=%d\n",e);   
   GetTop(s,e);   
   printf("ȡ��ջ��Ԫ��Ϊ e=%d \n",e);     
 }
