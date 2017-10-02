 //BubbleSort.cpp 调用起泡排序(程序见教材P15) 
 #include<stdio.h>  
 #define TRUE 1
 #define FALSE 0 
 typedef int Status;  
 #define N 8

 void bubble_sort(int a[],int n)// 将a中整数序列重新排列成自小至大有序的整数序列(起泡排序)
 { int i,j,temp;
   Status change;
   for(i=n-1,change=TRUE;i>1&&change;--i)
   { change=FALSE;
     for(j=0;j<i;++j)
         if(a[j]>a[j+1])
		 { temp=a[j];  a[j]=a[j+1]; a[j+1]=temp; change=TRUE;
		 }
   }
 }

 void print(int r[],int n)
 { int i;
   for(i=0;i<n;i++) printf("%d ",r[i]);
   printf("\n");
 }

 void main()
 { int d[N]={49,38,65,97,76,13,27,49};
   printf("起泡排序前:\n");
   print(d,N);
   bubble_sort(d,N);
   printf("起泡排序后:\n");
   print(d,N);
 }
