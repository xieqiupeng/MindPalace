 //Bin-search.cpp ʵ���۰�����㷨9.2
 #include<stdio.h> 
 #include<stdlib.h> 
 #define OK 1
 #define ERROR 0 
 typedef int Status; 

 #define N 11 // ����Ԫ�ظ���
 typedef int KeyType; 
 struct ElemType // ����Ԫ������
 { KeyType key; // ���йؼ�����
 };
 
// ��������ֵ�͹ؼ��ֵıȽ�Լ������
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))

 //��̬���ұ��˳��洢�ṹ
 struct SSTable
 { ElemType *elem; 
   int length; 
 };

// ��̬���ұ�(�����)�Ļ�������(6��)�������㷨9.2
 void Creat_Seq(SSTable &ST,ElemType r[],int n)
 { // ����������ɺ�n������Ԫ�ص�����r���쾲̬˳����ұ�ST
   int i;
   ST.elem=(ElemType*)calloc(n+1,sizeof(ElemType)); // ��̬����n+1������Ԫ�ؿռ�(0�ŵ�Ԫ����)
   if(!ST.elem)   exit(ERROR);
   for(i=1;i<=n;i++) ST.elem[i]=r[i-1]; // ������r��ֵ���θ���ST
   ST.length=n;
 }

 void Ascend(SSTable &ST) // �ؽ���̬���ұ�Ϊ���ؼ��ַǽ�������
 { int i,j,k;
   for(i=1;i<ST.length;i++)
   { k=i;
     ST.elem[0]=ST.elem[i]; // ���Ƚ�ֵ��[0]��Ԫ
     for(j=i+1;j<=ST.length;j++)
       if LT(ST.elem[j].key,ST.elem[0].key)
       { k=j;
         ST.elem[0]=ST.elem[j];
       }
     if(k!=i) // �и�С��ֵ�򽻻�
     { ST.elem[k]=ST.elem[i];
       ST.elem[i]=ST.elem[0];
     }
   }
 }

 void Creat_Ord(SSTable &ST,ElemType r[],int n)
 { // ����������ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST
   Creat_Seq(ST,r,n); // ��������Ĳ��ұ�ST
   Ascend(ST); // ������Ĳ��ұ�ST�ؽ�Ϊ���ؼ��ַǽ�����ұ�
 }

Status Destroy(SSTable &ST)
 { // ��ʼ��������̬���ұ�ST���ڡ�������������ٱ�ST
   free(ST.elem);
   ST.elem=NULL;
   ST.length=0;
   return OK;
 }

 int Search_Bin(SSTable ST,KeyType key)
 { // �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ����򷵻�
   // ��Ԫ���ڱ��е�λ�ã����򷵻�0���㷨9.2
   int low,high,mid;
   low=1; // �������ֵ
   high=ST.length;
   while(low<=high)
   { mid=(low+high)/2;
     if EQ(key,ST.elem[mid].key)  return mid;  // �ҵ�����Ԫ��       
     else if LT(key,ST.elem[mid].key)  high=mid-1; // ������ǰ��������в���
     else low=mid+1; // �����ں��������в���
   }
   return 0; // ˳����в����ڴ���Ԫ��
 }

 void Traverse(SSTable ST,void(*Visit)(ElemType))
 { // ��ʼ��������̬���ұ�ST���ڣ�Visit()�Ƕ�Ԫ�ز�����Ӧ�ú���
   // �����������˳���ST��ÿ��Ԫ�ص��ú���Visit()һ���ҽ�һ��
   ElemType *p;
   int i;
   p=++ST.elem; // pָ���һ��Ԫ��
   for(i=1;i<=ST.length;i++)   Visit(*p++);
 }

 void print(ElemType c) // Traverse()���õĺ���
 { printf("%d ",c.key);
 }

 void main()
 { SSTable st;
   int i;
   KeyType s;
   ElemType r[N]={5,13,19,21,37,56,64,75,80,88,92}; // ����Ԫ��(�Խ̿���P219������Ϊ��)
   Creat_Ord(st,r,N); // ��ȫ����������ǽ���̬���ұ�st
   Traverse(st,print); // ˳������ǽ���̬���ұ�st
   printf("\n");
   printf("�����������ֵ�Ĺؼ���: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); // �۰���������
   if(i)  printf("%d �ǵ�%d����¼�Ĺؼ���\n",st.elem[i].key,i);
   else  printf("û�ҵ�\n");
   Destroy(st);
 }
