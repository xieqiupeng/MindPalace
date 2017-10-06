#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int Elemtype;
typedef struct Cnode
{
	Elemtype data;
	struct Cnode *next;
}CNode;


struct Cnode* Creat_clist(CNode*clist,int n)
{
	CNode *p,*q;
	int i;
	clist=NULL;
	for(i=n;i>=1;i--)
	{
		p=(CNode*)malloc(sizeof(CNode));
		if(!p)   exit(OVERFLOW);    //�ڴ����ʧ��
		p->data=i;
		p->next=clist;
		clist=p;
		if(i==n)
			q=p;       //��qָ���������һ���ڵ�
	}
     q->next=clist;   //����ѭ������
	 return clist;    //clist��Ϊָ���һ���ڵ��ָ��

}

Status Kingmonkey(CNode *clist,int m)
{
	CNode *p,*q,*l;
	p=clist;
	int i;
	
	do
	{
		for(i=1;i<m-1;i++)
		{ p=p->next; }
		q=p->next;      //q�ڵ�ΪҪɾ���Ľڵ�

		p->next=q->next;
		p=p->next;
		printf("���Ҫɾ���Ľڵ㣺%d \n",q->data);
		free(q);
		m--;
		i=1;
		if(m==1&&p->next!=p)
		{

			m=13;
		}
	}while(p!=p->next);
	printf("�����ǣ�%d \n",p->data);
	return OK;
}

void main()
{
	int qua,out;
	printf("�����Ⱥ��������\n");
	scanf("%d",&qua);
	printf("������̭�������\n");
	scanf("%d",&out);
	CNode *monkey;    
	monkey=NULL;
	monkey=Creat_clist(monkey,qua);   //������Ⱥ��ѭ������
	Kingmonkey(monkey,out);
}
