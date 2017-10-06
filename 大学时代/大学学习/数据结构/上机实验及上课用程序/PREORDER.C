 #include "stdio.h"
typedef struct BiTree
{char data;
 struct BiTree *lchild,*rchild;
}BiTree;
BiTree *CreateBiTree();
void PreOrderTraverse(BiTree *bt);

main()
{BiTree *bt;
 bt=CreateBiTree();
 printf("\n");
 PreOrderTraverse(bt);
 printf("\n");
}

BiTree *CreateBiTree()
{BiTree *bt;
 char ch;
 ch=getchar();
 putchar(ch);
 if(ch=='#')bt=0;
 else{bt=(BiTree *)malloc(sizeof(BiTree));
 bt->data=ch;
 bt->lchild=CreateBiTree();
 bt->rchild=CreateBiTree();
 }
 return(bt);
}
void PreOrderTraverse(BiTree *bt)
{if(bt)
 {printf("[%c]",bt->data);
  PreOrderTraverse(bt->lchild);
  PreOrderTraverse(bt->rchild);
 }
}

