 //Bin-search.cpp 实现折半查找算法9.2
 #include<stdio.h> 
 #include<stdlib.h> 
 #define OK 1
 #define ERROR 0 
 typedef int Status; 

 #define N 11 // 数据元素个数
 typedef int KeyType; 
 struct ElemType // 数据元素类型
 { KeyType key; // 仅有关键字域
 };
 
// 对两个数值型关键字的比较约定如下
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

 //静态查找表的顺序存储结构
 struct SSTable
 { ElemType *elem; 
   int length; 
 };

// 静态查找表(有序表)的基本操作(6个)，包括算法9.2
 void Creat_Seq(SSTable &ST,ElemType r[],int n)
 { // 操作结果：由含n个数据元素的数组r构造静态顺序查找表ST
   int i;
   ST.elem=(ElemType*)calloc(n+1,sizeof(ElemType)); // 动态生成n+1个数据元素空间(0号单元不用)
   if(!ST.elem)   exit(ERROR);
   for(i=1;i<=n;i++) ST.elem[i]=r[i-1]; // 将数组r的值依次赋给ST
   ST.length=n;
 }

 void Ascend(SSTable &ST) // 重建静态查找表为按关键字非降序排序
 { int i,j,k;
   for(i=1;i<ST.length;i++)
   { k=i;
     ST.elem[0]=ST.elem[i]; // 待比较值存[0]单元
     for(j=i+1;j<=ST.length;j++)
       if LT(ST.elem[j].key,ST.elem[0].key)
       { k=j;
         ST.elem[0]=ST.elem[j];
       }
     if(k!=i) // 有更小的值则交换
     { ST.elem[k]=ST.elem[i];
       ST.elem[i]=ST.elem[0];
     }
   }
 }

 void Creat_Ord(SSTable &ST,ElemType r[],int n)
 { // 操作结果：由含n个数据元素的数组r构造按关键字非降序查找表ST
   Creat_Seq(ST,r,n); // 建立无序的查找表ST
   Ascend(ST); // 将无序的查找表ST重建为按关键字非降序查找表
 }

Status Destroy(SSTable &ST)
 { // 初始条件：静态查找表ST存在。操作结果：销毁表ST
   free(ST.elem);
   ST.elem=NULL;
   ST.length=0;
   return OK;
 }

 int Search_Bin(SSTable ST,KeyType key)
 { // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则返回
   // 该元素在表中的位置，否则返回0。算法9.2
   int low,high,mid;
   low=1; // 置区间初值
   high=ST.length;
   while(low<=high)
   { mid=(low+high)/2;
     if EQ(key,ST.elem[mid].key)  return mid;  // 找到待查元素       
     else if LT(key,ST.elem[mid].key)  high=mid-1; // 继续在前半区间进行查找
     else low=mid+1; // 继续在后半区间进行查找
   }
   return 0; // 顺序表中不存在待查元素
 }

 void Traverse(SSTable ST,void(*Visit)(ElemType))
 { // 初始条件：静态查找表ST存在，Visit()是对元素操作的应用函数
   // 操作结果：按顺序对ST的每个元素调用函数Visit()一次且仅一次
   ElemType *p;
   int i;
   p=++ST.elem; // p指向第一个元素
   for(i=1;i<=ST.length;i++)   Visit(*p++);
 }

 void print(ElemType c) // Traverse()调用的函数
 { printf("%d ",c.key);
 }

 void main()
 { SSTable st;
   int i;
   KeyType s;
   ElemType r[N]={5,13,19,21,37,56,64,75,80,88,92}; // 数据元素(以教科书P219的数据为例)
   Creat_Ord(st,r,N); // 由全局数组产生非降序静态查找表st
   Traverse(st,print); // 顺序输出非降序静态查找表st
   printf("\n");
   printf("请输入待查找值的关键字: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); // 折半查找有序表
   if(i)  printf("%d 是第%d个记录的关键字\n",st.elem[i].key,i);
   else  printf("没找到\n");
   Destroy(st);
 }
