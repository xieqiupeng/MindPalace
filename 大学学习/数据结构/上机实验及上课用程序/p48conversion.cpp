 // p48conversion.cpp ����ת������ 
 #include<string.h> 
 #include<malloc.h> // malloc()�� 
 #include<stdio.h> // EOF(=^Z��F6),NULL 
 #include<math.h> // floor(),ceil(),abs(),OVERFLOW
 #include<process.h> // exit()
 #include<iostream.h> 
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 #define N 8 // �����ת���Ľ���N(2��9)
 typedef int SElemType; // ����ջԪ������Ϊ���� 
 
 // ջ��˳��洢��ʾ
 #define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
 #define STACK_INCREMENT 2 // �洢�ռ��������
 struct SqStack
 { SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
   SElemType *top; // ջ��ָ��
   int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
 }; 

 // ˳��ջ�Ļ�������
 void InitStack(SqStack &S)
 { // ����һ����ջS
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // �洢����ʧ��
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }

 Status StackEmpty(SqStack S)
 { // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
   if(S.top==S.base)    return TRUE;
   else    return FALSE;
 }

 void Push(SqStack &S,SElemType e)
 { // ����Ԫ��eΪ�µ�ջ��Ԫ��
   if(S.top-S.base>=S.stacksize) // ջ����׷�Ӵ洢�ռ�
   { S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)   exit(OVERFLOW); // �洢����ʧ��
     S.top=S.base+S.stacksize;
     S.stacksize+=STACK_INCREMENT;
   }
   *(S.top)++=e;
 }

 Status Pop(SqStack &S,SElemType &e)
 { // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(S.top==S.base)   return ERROR;
   e=*--S.top;
   return OK;
 }

 void conversion() // (�̲�P48�㷨3.1)
 { // �������������һ���Ǹ�10������������ӡ��������ֵ��N������
   SqStack s;
   unsigned n; // �Ǹ�����
   SElemType e;
   InitStack(s); // ��ʼ��ջ
   cout<<"��10��������nת��Ϊ8�������������룺n (>=0) ="<<ends;
   cin>>n; // ����Ǹ�ʮ��������n
   while(n) // ��n������0
   { Push(s,n%N); // ��ջn����N������(N���Ƶĵ�λ)
     n=n/N;
   }
   while(!StackEmpty(s)) // ��ջ����
   { Pop(s,e); // ����ջ��Ԫ���Ҹ�ֵ��e
     cout<<e; // ���e
   }
   cout<<"\n";
 }

 void main()
 {   conversion();
 }

 
 /*���н����
   ��10��������nת��Ϊ8�������������룺n (>=0) = 1348 
   2504

       */