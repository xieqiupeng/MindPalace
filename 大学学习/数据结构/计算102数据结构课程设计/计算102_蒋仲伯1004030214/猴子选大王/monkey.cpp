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
		if(!p)   exit(OVERFLOW);    //内存分配失败
		p->data=i;
		p->next=clist;
		clist=p;
		if(i==n)
			q=p;       //用q指向链表最后一个节点
	}
     q->next=clist;   //构成循环链表
	 return clist;    //clist即为指向第一个节点的指针

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
		q=p->next;      //q节点为要删除的节点

		p->next=q->next;
		p=p->next;
		printf("输出要删除的节点：%d \n",q->data);
		free(q);
		m--;
		i=1;
		if(m==1&&p->next!=p)
		{

			m=13;
		}
	}while(p!=p->next);
	printf("猴王是：%d \n",p->data);
	return OK;
}

void main()
{
	int qua,out;
	printf("输入猴群的数量：\n");
	scanf("%d",&qua);
	printf("输入淘汰猴的数：\n");
	scanf("%d",&out);
	CNode *monkey;    
	monkey=NULL;
	monkey=Creat_clist(monkey,qua);   //建立猴群的循环链表
	Kingmonkey(monkey,out);
}
