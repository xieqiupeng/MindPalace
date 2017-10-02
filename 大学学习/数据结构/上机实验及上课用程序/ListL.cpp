  //ListL.cpp
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
 typedef int ElemType;

 typedef struct LNode   // ���Ա�ĵ�����洢�ṹ
 { ElemType  data;
   LNode *next;
 }LNode,*LinkList; 

 void print(ElemType c)
 {   printf("%d ",c);
 }

//����ͷ���ĵ�����Ļ�������,�����㷨2.8,�㷨2.9,�㷨2.10
 void InitList_L(LinkList &L)
 { // �������������һ���յ����Ա�L
   L=(LinkList)malloc(sizeof(LNode)); // ����ͷ��㣬��ʹLָ���ͷ���
   if(!L) exit(OVERFLOW); // �洢����ʧ��     
   L->next=NULL; // ָ����Ϊ��
 }

 void DestroyList_L(LinkList &L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L
   LinkList q;
   while(L)
   { q=L->next;
     free(L);
     L=q;
   }
 }

 void ClearList_L(LinkList L) // ���ı�L
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p,q;
   p=L->next; // pָ���һ�����
   while(p) // û����β
   { q=p->next;
     free(p);
     p=q;
   }
   L->next=NULL; // ͷ���ָ����Ϊ��
 }

 int ListLength_L(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
   int i=0;
   LinkList p=L->next; // pָ���һ�����
   while(p) // û����β
   { i++;
     p=p->next;
   }
   return i; 
 }

 Status GetElem_L(LinkList L,int i,ElemType &e) // �㷨2.8
 { // LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
   LinkList p=L->next; // pָ���һ�����
   int j=1; // jΪ������
   while(p&&j<i) // ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
   { p=p->next;
     j++;
   }
   if(!p||j>i) // ��i��Ԫ�ز�����
     return ERROR;
   e=p->data; // ȡ��i��Ԫ��
   return OK;
 } 

 Status ListInsert_L(LinkList L,int i,ElemType e) // �㷨2.9�����ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) // Ѱ�ҵ�i-1�����
   { p=p->next;
     j++;
   }
   if(!p||j>i-1)  return ERROR; // iС��1���ߴ��ڱ�    
   s=(LinkList)malloc(sizeof(LNode)); // �����½��
   s->data=e; // ����L��
   s->next=p->next;
   p->next=s;
   return OK;
 }

 Status ListDelete_L(LinkList L,int i,ElemType &e) // �㷨2.10�����ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) // Ѱ�ҵ�i����㣬����pָ����ǰ��
   { p=p->next;
     j++;
   }
   if(!p->next||j>i-1)  return ERROR;   // ɾ��λ�ò�����    
   q=p->next; // ɾ�����ͷŽ��
   p->next=q->next;
   e=q->data;
   free(q);
   return OK;
 }

 void ListTraverse_L(LinkList L,void(*vi)(ElemType))
 // vi���β�����ΪElemType����bo2-1.cpp����Ӧ�������β�����ElemType&��ͬ
 { // ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()
   LinkList p=L->next;
   while(p)
   { vi(p->data);
     p=p->next;
   }
   printf("\n");
 } 
 

 void main()
 { LinkList L;    ElemType e;   Status i;   int j,k;
   InitList_L(L);
   for(j=1;j<=5;j++)  i=ListInsert_L(L,1,j);
   printf("��L�ı�ͷ���β���1��5��L=");
   ListTraverse_L(L,print); // ���ζ�Ԫ�ص���print()�����Ԫ�ص�ֵ 
   ClearList_L(L);
   printf("���L��L=");
   ListTraverse_L(L,print); 
   for(j=1;j<=10;j++)  ListInsert_L(L,j,j);
   printf("��L�ı�β���β���1��10��L=");
   ListTraverse_L(L,print);
   GetElem_L(L,5,e);
   printf("��5��Ԫ�ص�ֵΪ��%d\n",e);  
   k=ListLength_L(L); // kΪ��   
   for(j=k+1;j>=k;j--)
   { i=ListDelete_L(L,j,e); // ɾ����j������
     if(i==ERROR)  printf("ɾ����%d��Ԫ��ʧ��\n",j);
     else printf("ɾ����%d��Ԫ�سɹ�����ֵΪ��%d\n",j,e);
   }
   printf("�������L��Ԫ�أ�");
   ListTraverse_L(L,print);
   DestroyList_L(L);
   printf("����L��L=%u\n",L);
 }