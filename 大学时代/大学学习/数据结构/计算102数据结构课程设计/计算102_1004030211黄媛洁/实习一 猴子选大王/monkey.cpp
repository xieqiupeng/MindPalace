#include<stdio.h>
#include<malloc.h>

typedef struct LNode  //定义头结点
{
	int  num;
	struct LNode *next;
}LNode, *LinkList;

LinkList InitList(LinkList L,int n)  //初始化循环链表
{   
	LinkList p,q;
	int i;
	L = (LinkList)malloc(sizeof(LNode)); //头结点  
    L->num = 1;    //一号猴子
    q=L;
	for(i = 2; i <= n; i++)  //从二号猴子开始生成结点
    {      
        p = (LinkList)malloc(sizeof(LNode));      
        p->num = i;
		q->next=p;
		q=p;
    }      
    q->next = L;   //使链表循环起来
	return L;
}
void ListDelete_L(LinkList L,int n)
{
 LinkList p,q;
 int j=1;    //j为计数器
 p=L;
 
 while(p->next!=p)   //p->next=p时是只剩一个结点。
 {
  while(j!=n-1) //当j=n-1时应该将该结点的下一个结点删除。当就j!=n-1时就应该指针向后移，同时计数器加一
  {
   p=p->next;
   j++;      
  }
  q=p->next;  //q即为被点到的猴子
  p->next=q->next;  //删除q结点
printf("第%d号猴子离开\n",q->num); 
  free(q);//释放
j=0;     //计数器清零，重新开始计数
}
 printf("猴子大王为%d号",p->num);//此时的结点就是大王
 free(p);
}

void main()
{
LinkList L=NULL;
 int n,m,e=0;
 printf("请输入猴子个数m:");
 scanf("%d",&m);
 printf("请输入n值:");
scanf("%d",&n);
while(m<n)
{
	printf("猴子个数m应该大于n，请重新输入\n");
	printf("请输入猴子个数m:");
	scanf("%d",&m);
	printf("请输入n值:");
	scanf("%d",&n);
}
L=InitList(L,m);
printf("出列的顺序为:\n");
  ListDelete_L( L,n);
}