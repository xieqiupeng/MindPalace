 // p61LinkQueue.cpp ���е���ʽ�洢
 #include<string.h> 
 #include<malloc.h> // malloc()�� 
 #include<stdio.h> // EOF(=^Z��F6),NULL 
 #include<math.h> // floor(),ceil(),abs(),OVERFLOW
 #include<process.h> // exit()
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 typedef int QlemType; 
 
 typedef int QElemType;
 //�������У������е���ʽ�洢�ṹ
 typedef struct QNode
 { QElemType data;
   QNode *next;
 }*QueuePtr;
 struct LinkQueue
 { QueuePtr front,rear; // ��ͷ����βָ��
 };

// �����еĻ�������
 void InitQueue(LinkQueue &Q)
 { // ����һ���ն���Q
   if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
     exit(OVERFLOW);
   Q.front->next=NULL;
 }

 void DestroyQueue(LinkQueue &Q)
 { // ���ٶ���Q(���ۿշ����)
   while(Q.front)
   {
     Q.rear=Q.front->next;
     free(Q.front);
     Q.front=Q.rear;
   }
 }
 void EnQueue(LinkQueue &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   QueuePtr p;
   if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // �洢����ʧ��
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   Q.rear->next=p;
   Q.rear=p;
 }

 Status DeQueue(LinkQueue &Q,QElemType &e)
 { // �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
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
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
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
   printf("�ɹ��ع�����һ���ն���!\n");   
   EnQueue(q,-5);
   EnQueue(q,5);
   EnQueue(q,10);  
   printf("����3��Ԫ��(-5,5,10)��,���е�Ԫ������Ϊ��");
   QueueTraverse(q,visit);
   DeQueue(q,d);
   printf("ɾ���˶�ͷԪ��%d\n",d);   
   DestroyQueue(q);
   printf("���ٶ��к�,q.front=%u q.rear=%u\n",q.front, q.rear);
 }