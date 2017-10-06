 // SqQueue.cpp ѭ�����У�ʵ�ֽ̲�P64-P65�Ļ�������
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

 typedef int QElemType; // �������Ԫ������

//���е�˳��洢�ṹ(ѭ������)
 #define MAX_QSIZE 5 // �����г���+1
 struct SqQueue
 { QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
   int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
 };
 
  // ѭ�����еĻ�������(�̲�P64-P65�Ļ�������)
 void InitQueue(SqQueue &Q)
 { // ����һ���ն���Q
   Q.base=(QElemType *)malloc(MAX_QSIZE*sizeof(QElemType));
   if(!Q.base) // �洢����ʧ��
     exit(OVERFLOW);
   Q.front=Q.rear=0;
 }

 int QueueLength(SqQueue Q)
 { // ����Q��Ԫ�ظ����������еĳ���
   return(Q.rear-Q.front+MAX_QSIZE)%MAX_QSIZE;
 }

 Status EnQueue(SqQueue &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   if((Q.rear+1)%MAX_QSIZE==Q.front) // ������
     return ERROR;
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAX_QSIZE;
   return OK;
 }

 Status DeQueue(SqQueue &Q,QElemType &e)
 { // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAX_QSIZE;
   return OK;
 }

 void QueueTraverse(SqQueue Q,void(*visit)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
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
   printf("���������Ͷ���Ԫ��(������%d��),Ԫ�ؼ��ÿո�ָ���-1Ϊ��ǰ������: ",MAX_QSIZE-1);
   do
   { scanf("%d",&d);
     if(d==-1)  break;
     i++;
     EnQueue(Q,d);
   }while(i<MAX_QSIZE-1);
   printf("���г���Ϊ: %d\n",QueueLength(Q));  
   printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAX_QSIZE);
   for(l=1;l<=MAX_QSIZE;l++)
   { DeQueue(Q,d);
     printf("ɾ����Ԫ����%d,������������Ԫ��: ",d);
     scanf("%d",&d);
     EnQueue(Q,d);
   }
   l=QueueLength(Q);
   printf("���ڶ����е�Ԫ��Ϊ:\n");
   QueueTraverse(Q,print);
   printf("�����β������%d��Ԫ��\n",i+MAX_QSIZE);
   if(l-2>0)
     printf("�����ɶ�ͷɾ��%d��Ԫ��: \n",l-2);
   while(QueueLength(Q)>2)
   { DeQueue(Q,d);
     printf("ɾ����Ԫ��ֵΪ%d\n",d);
   }   
 }