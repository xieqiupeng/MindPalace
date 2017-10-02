// huffman.cpp ����������롣ʵ�ֽ̲�P147�㷨6.12
 #include<string.h> 
 #include<malloc.h> // malloc()�� 
 #include<stdio.h> // EOF(=^Z��F6),NULL 
 #include<math.h> // floor(),ceil(),abs(),OVERFLOW
 #include<process.h> // exit()
 #include<limits.h> // INT_MAX��UINT_MAX��
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 typedef int Status; 
 typedef int Boolean; 

// ���������͹���������Ĵ洢��ʾ
 typedef struct
 { unsigned int weight;
   unsigned int parent,lchild,rchild;
 }HTNode,*HuffmanTree; // ��̬��������洢��������
 typedef char **HuffmanCode; // ��̬��������洢�����������
  
 int min(HuffmanTree t,int i)
 { // ����i�������Ȩֵ��С�����ĸ������ţ�����select()����
   int j,f;
   unsigned int k=UINT_MAX; // ȡkΪ��С�ڿ��ܵ�ֵ(�޷����������ֵ)
   for(j=1;j<=i;j++)
     if(t[j].weight<k&&t[j].parent==0) // t[j]�����ĸ����
       k=t[j].weight,f=j;
   t[f].parent=1; // ��ѡ�еĸ�����˫�׸�1�������2�β��Ҹý��
   return f;
 }

 void select(HuffmanTree t,int i,int &s1,int &s2)
 { // ��i�������ѡ��2��Ȩֵ��С�����ĸ������ţ�s1Ϊ�������С���Ǹ�
   int j;
   s1=min(t,i);
   s2=min(t,i);
   if(s1>s2){j=s1; s1=s2; s2=j;}
 }

// �㷨6.12
 void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n) 
 { // w���n���ַ���Ȩֵ(��>0)�������������HT�������n���ַ��Ĺ���������HC
   int m,i,s1,s2,start;
   unsigned c,f;
   HuffmanTree p;
   char *cd;
   if(n<=1) return;
   m=2*n-1;
   HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); // 0�ŵ�Ԫδ��
   for(p=HT+1,i=1;i<=n;++i,++p,++w)
   { (*p).weight=*w;
     (*p).parent=0;
     (*p).lchild=0;
     (*p).rchild=0;
   }
   for(;i<=m;++i,++p)   (*p).parent=0;
   for(i=n+1;i<=m;++i) // ����������
   { // ��HT[1��i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
     select(HT,i-1,s1,s2);
     HT[s1].parent=HT[s2].parent=i;
     HT[i].lchild=s1;
     HT[i].rchild=s2;
     HT[i].weight=HT[s1].weight+HT[s2].weight;
   }
   // ��Ҷ�ӵ���������ÿ���ַ��Ĺ���������
   HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
   // ����n���ַ������ͷָ������([0]����)
   cd=(char*)malloc(n*sizeof(char)); // ���������Ĺ����ռ�
   cd[n-1]='\0'; // ���������
   for(i=1;i<=n;i++)
   { // ����ַ������������
     start=n-1; // ���������λ��
     for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
     // ��Ҷ�ӵ������������
       if(HT[f].lchild==c) cd[--start]='0';
       else cd[--start]='1';
     HC[i]=(char*)malloc((n-start)*sizeof(char));
     // Ϊ��i���ַ��������ռ�
     strcpy(HC[i],&cd[start]); // ��cd���Ʊ���(��)��HC
   }
   free(cd); // �ͷŹ����ռ�
 }

 void main()
 { HuffmanTree HT;
   HuffmanCode HC;
   int *w,n,i;
   printf("������Ȩֵ���ܸ���(>1): ");
   scanf("%d",&n);
   w=(int*)malloc(n*sizeof(int));
   printf("����������%d��Ȩֵ(������Ȩֵ֮���ÿո�ָ�):\n",n);
   for(i=0;i<=n-1;i++)  scanf("%d",w+i);
   HuffmanCoding(HT,HC,w,n);
   for(i=1;i<=n;i++)  puts(HC[i]);
 }
