 //countleafn.cpp 统计二叉树中叶子结点的个数
 
 #include<malloc.h> 
 #include<stdio.h> 
 typedef struct BiTNode
 {char data;
  struct BiTNode *lchild,*rchild;
 }BiTNode, *BiTree;
 BiTree  CreateBiTree();
 void InOrderTraverse(BiTree  bt);
 void  countleaf(BiTree  bt);
 int n=0;

void main()
 { BiTree  bt;
  bt=CreateBiTree();
  printf("\n");
  printf("The init bitree is: ");
  InOrderTraverse(bt);
  printf("\n");
  countleaf(bt);
  printf("The leafs are:   %d ",n);
  printf("\n");
 }

 BiTree  CreateBiTree()
 {BiTree  bt;
  char ch;
  ch=getchar();
  putchar(ch);
  if(ch=='#')bt=0;
  else{bt=(BiTree  )malloc(sizeof(BiTNode));
       bt->data=ch;
       bt->lchild=CreateBiTree();
       bt->rchild=CreateBiTree();
  }
  return(bt);
 }

 void InOrderTraverse(BiTree  bt)
 {if(bt)
  {InOrderTraverse(bt->lchild);
   printf("[%c]",bt->data);
   InOrderTraverse(bt->rchild);
  }
 }

 void countleaf(BiTree  bt)
 {if(bt){if((!bt->lchild)&&(!bt->rchild)) n=n+1;
	 countleaf(bt->lchild);
	 countleaf(bt->rchild);
	}
  }

