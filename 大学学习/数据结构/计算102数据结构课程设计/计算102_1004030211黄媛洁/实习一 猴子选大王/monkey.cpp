#include<stdio.h>
#include<malloc.h>

typedef struct LNode  //����ͷ���
{
	int  num;
	struct LNode *next;
}LNode, *LinkList;

LinkList InitList(LinkList L,int n)  //��ʼ��ѭ������
{   
	LinkList p,q;
	int i;
	L = (LinkList)malloc(sizeof(LNode)); //ͷ���  
    L->num = 1;    //һ�ź���
    q=L;
	for(i = 2; i <= n; i++)  //�Ӷ��ź��ӿ�ʼ���ɽ��
    {      
        p = (LinkList)malloc(sizeof(LNode));      
        p->num = i;
		q->next=p;
		q=p;
    }      
    q->next = L;   //ʹ����ѭ������
	return L;
}
void ListDelete_L(LinkList L,int n)
{
 LinkList p,q;
 int j=1;    //jΪ������
 p=L;
 
 while(p->next!=p)   //p->next=pʱ��ֻʣһ����㡣
 {
  while(j!=n-1) //��j=n-1ʱӦ�ý��ý�����һ�����ɾ��������j!=n-1ʱ��Ӧ��ָ������ƣ�ͬʱ��������һ
  {
   p=p->next;
   j++;      
  }
  q=p->next;  //q��Ϊ���㵽�ĺ���
  p->next=q->next;  //ɾ��q���
printf("��%d�ź����뿪\n",q->num); 
  free(q);//�ͷ�
j=0;     //���������㣬���¿�ʼ����
}
 printf("���Ӵ���Ϊ%d��",p->num);//��ʱ�Ľ����Ǵ���
 free(p);
}

void main()
{
LinkList L=NULL;
 int n,m,e=0;
 printf("��������Ӹ���m:");
 scanf("%d",&m);
 printf("������nֵ:");
scanf("%d",&n);
while(m<n)
{
	printf("���Ӹ���mӦ�ô���n������������\n");
	printf("��������Ӹ���m:");
	scanf("%d",&m);
	printf("������nֵ:");
	scanf("%d",&n);
}
L=InitList(L,m);
printf("���е�˳��Ϊ:\n");
  ListDelete_L( L,n);
}