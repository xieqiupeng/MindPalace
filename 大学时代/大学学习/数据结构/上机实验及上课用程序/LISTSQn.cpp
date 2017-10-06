 //顺序表的插入算法

 #include "stdio.h"
 #include "stdlib.h"
 #define LIST_INIT_SIZE 100
 #define LISTINCREMENT  10
 #define OVERFLOW       -2
 #define ERROR          0
 #define OK             1
 typedef struct{
       int *elem;
       int length;
       int listsize;
 }SqList;
 
 void printSq(SqList *L)
 {int *pi,i;
  pi=L->elem;
  for(i=1;i<=L->length;i++,pi++)
   {printf("Elem[%2d]=%2d;",i,*pi);
    if(i%5==0) printf("\n");
   }
 }

 SqList *ListInsert_Sq(SqList *L,int i,int e)
 {int *q,*p,*newbase;
  if(i<1||i>L->length+1) return  ERROR;
  if(L->length>=L->listsize)
  { newbase=(int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));
    if(!newbase) exit(OVERFLOW);
    L->elem=newbase;
    L->listsize+=LISTINCREMENT;
  }
  q=&(L->elem[i-1]);
  for(p=&(L->elem[L->length-1]);p>=q;--p) *(p+1)=*p;
  *q=e;
  ++L->length;
  return(L);
 } 

 SqList *InitList_Sq()
 { SqList *L;
   L=(SqList *)malloc(sizeof(SqList));
   L->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
   if(!L->elem) exit(OVERFLOW);
   L->length=0;
   L->listsize=LIST_INIT_SIZE;
   return(L);
 }
 
 int main()
 {int *pi,i;
  SqList Lrec,*Lp;
  Lp=&Lrec;
  Lp=InitList_Sq();
  pi=Lp->elem;
  for(i=0;i<30;i++,pi++)
    *pi=i+1;
  Lp->length=30;
  printf("\nBEGIN i=%d\n",i);
  printSq(Lp);
  Lp=ListInsert_Sq(Lp,15,100);
  printf("\nIns_Number! i=15\n");
  printSq(Lp);
  printf("\n");
  return 0;
 }
 