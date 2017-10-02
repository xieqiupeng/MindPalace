// Evaluate.cpp ���ʽ��ֵ(�����ֵ��0��9֮�䣬�м����������ֵ��-128��127֮��)���㷨3.4
 #include<string.h> 
 #include<malloc.h> // malloc()��
 #include<stdio.h> // EOF,NULL 
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0 
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
 typedef char SElemType; // ջԪ��Ϊ�ַ���
  
 #define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
 #define STACK_INCREMENT 2 // �洢�ռ��������
 struct SqStack  // ˳��ջ
 { SElemType *base; 
   SElemType *top; 
   int stacksize; 
 };

 // ˳��ջ�Ļ�������(5��)
 void InitStack(SqStack &S)
 { // ����һ����ջS
   if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
     exit(OVERFLOW); // �洢����ʧ��
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
 }
 
 Status StackEmpty(SqStack S)
 { // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 } 

 Status GetTop(SqStack S,SElemType &e)
 { // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
   if(S.top>S.base)
   {
     e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 void Push(SqStack &S,SElemType e)
 { // ����Ԫ��eΪ�µ�ջ��Ԫ��
   if(S.top-S.base>=S.stacksize) // ջ����׷�Ӵ洢�ռ�
   {
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
     if(!S.base)
       exit(OVERFLOW); // �洢����ʧ��
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

// ���ݽ̲ı�3.1���ж�t1��t2�����ŵ����ȹ�ϵ('#'��'\n'����)
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
                printf("���Ų�ƥ��\n");
                exit(ERROR);
              }
              else
                f='<'; // t1<t2
              break;
     case ')':switch(t1)
              {
                case '(':f='='; // t1=t2
                         break;
                case'\n':printf("ȱ��������\n");
                         exit(ERROR);
                         default :f='>'; // t1>t2
              }
              break;
     case'\n':switch(t1)
              {
                case'\n':f='='; // t1=t2
                         break;
                case'(' :printf("ȱ��������\n");
                         exit(ERROR);
                default :f='>'; // t1>t2
              }
   }
   return f;
 }

 Status In(SElemType c)  // �ж�c�Ƿ�Ϊ7�������֮һ
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
 { // ����������a theta b������������
   switch(theta)
   { case'+':return a+b;
     case'-':return a-b;
     case'*':return a*b;
   }
   return a/b;
 }


// �㷨3.4. �������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ�����иĶ�
 SElemType EvaluateExpression() 
 { SqStack OPTR,OPND;
   SElemType a,b,c,x;
   InitStack(OPTR); // ��ʼ�������ջOPTR��������ջOPND
   InitStack(OPND);
   Push(OPTR,'\n'); // �����з�ѹ�������ջOPTR��ջ��(��)
   c=getchar(); // �ɼ��̶���1���ַ���c
   GetTop(OPTR,x); // �������ջOPTR��ջ��Ԫ�ظ���x
   while(c!='\n'||x!='\n') // c��x�����ǻ��з�
   {   if(In(c)) // c��7�������֮һ
       switch(Precede(x,c)) // �ж�x��c������Ȩ
       {
         case'<' :Push(OPTR,c); // ջ��Ԫ��x������Ȩ�ͣ���ջc
                  c=getchar();  // �ɼ��̶�����һ���ַ���c
                  break;
         case'=' :Pop(OPTR,x); // x='('��c=')'���������'('��x(�����ӵ�)
                  c=getchar(); // �ɼ��̶�����һ���ַ���c(�ӵ�')')
                  break;
         case'>' :Pop(OPTR,x); // ջ��Ԫ��x������Ȩ�ߣ����������ջOPTR��ջ��Ԫ�ظ�x(��)
                  Pop(OPND,b); // ���ε���������ջOPND��ջ��Ԫ�ظ�b��a
                  Pop(OPND,a);
                  Push(OPND,Operate(a,x,b)); // ������a x b��������������������ջ
       }
     else if(c>='0'&&c<='9') // c�ǲ�����
     {
       Push(OPND,c-48); // ���ò�������ֵ(����ASCII��)ѹ��������ջOPND
       c=getchar(); // �ɼ��̶�����һ���ַ���c
     }
     else // c�ǷǷ��ַ�
     {
       printf("���ַǷ��ַ�\n");
       exit(ERROR);
     }
     GetTop(OPTR,x); // �������ջOPTR��ջ��Ԫ�ظ���x
   }
   Pop(OPND,x); // ����������ջOPND��ջ��Ԫ��(������)��x(�Ĵ˴�)
   if(!StackEmpty(OPND)) // ������ջOPND����(�����ջOPTR��ʣ'\n')
   {
     printf("���ʽ����ȷ\n");
     exit(ERROR);
   }
   return x;
 }

 void main()
 {
   printf("�������������ʽ(�����ֵҪ��0��9֮�䡢�м�����ֵ����������-128��127֮��)\n");
   printf("%d\n",EvaluateExpression()); // ����ֵ(8λ2���ƣ�1���ֽ�)�����͸�ʽ���
 }
