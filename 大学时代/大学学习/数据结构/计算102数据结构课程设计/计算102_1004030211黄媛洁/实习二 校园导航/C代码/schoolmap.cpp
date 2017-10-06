#include<string.h> 
#include<malloc.h> 
#include<stdio.h> 
#include<math.h> 
#include<process.h>
#include<limits.h> 
#define TRUE 1
#define FALSE 0 
#define INFINITY INT_MAX  // ���������ֵ�����
#define MAX_VERTEX_NUM 20  // ��󶥵����

typedef struct ArcCell{  //���Ķ��壨·����
	int adj;  //·����Ȩֵ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct VertexType{  //���㶨�壨���㣩
	char name[MAX_VERTEX_NUM];  //��������
	char daihao[MAX_VERTEX_NUM];  //�������
}VertexType;

typedef struct MGraph{  //ͼ�Ķ���
	VertexType vexs[MAX_VERTEX_NUM];  //�洢�����һά����
	AdjMatrix arcs;  //�洢�ڽӾ���Ķ�ά����
	int vexnum,arcnum;  //ͼ�Ķ�����������
}MGraph;

void Init(MGraph &G)  //��ʼ���ڽӾ���
{
	G.vexnum=10;  //������
	G.arcnum=12;  //����
	strcpy(G.vexs[0].name,"������");   //��ʼ������
	strcpy(G.vexs[0].daihao,"A");
	strcpy(G.vexs[1].name,"ѧ��ʳ��");
	strcpy(G.vexs[1].daihao,"B");
	strcpy(G.vexs[2].name,"ѧ�������");
	strcpy(G.vexs[2].daihao,"C");
	strcpy(G.vexs[3].name,"�Ŀ�ʵ������");
	strcpy(G.vexs[3].daihao,"D");
	strcpy(G.vexs[4].name,"������");
	strcpy(G.vexs[4].daihao,"E");
	strcpy(G.vexs[5].name,"�����");
	strcpy(G.vexs[5].daihao,"F");
	strcpy(G.vexs[6].name,"��¥");
	strcpy(G.vexs[6].daihao,"G");
	strcpy(G.vexs[7].name,"ͼ���");
	strcpy(G.vexs[7].daihao,"H");
	strcpy(G.vexs[8].name,"�ٳ�");
	strcpy(G.vexs[8].daihao,"I");
	strcpy(G.vexs[9].name,"��֪�㳡");
	strcpy(G.vexs[9].daihao,"J");
	int i,j;
	for(i=0;i<G.vexnum;i++)    //��ʼ���ڽӾ���
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j].adj=INFINITY;
	 G.arcs[0][1].adj=G.arcs[1][0].adj=400;  //�����ڽӾ���
	 G.arcs[1][2].adj=G.arcs[2][1].adj=420;
	 G.arcs[1][3].adj=G.arcs[3][1].adj=610;
	 G.arcs[1][4].adj=G.arcs[4][1].adj=300;
	 G.arcs[2][4].adj=G.arcs[4][2].adj=360;
	 G.arcs[2][6].adj=G.arcs[6][2].adj=400;
	 G.arcs[3][6].adj=G.arcs[6][3].adj=400;
	 G.arcs[5][6].adj=G.arcs[6][5].adj=410;
	 G.arcs[5][8].adj=G.arcs[8][5].adj=390;
	 G.arcs[6][7].adj=G.arcs[7][6].adj=260;
	 G.arcs[6][8].adj=G.arcs[8][6].adj=500;
	 G.arcs[7][9].adj=G.arcs[9][7].adj=560;
}

void ShortestPath_DIJ(MGraph G,int v0,int path[], int lowcost[])
{ 
	int flag[MAX_VERTEX_NUM],i,k,v,w;
	unsigned int min;
	for(v=0;v<G.vexnum;v++)
	{
		// ��ʼ��flag��flag[v] ��ʾ�Ƿ�v0��v�����·�����ҵ�,1��ʾ�ҵ���0��ʾû��
		flag[v] = 0 ; 
		// path[v] ��ʾv0��v�����·����,v֮ǰ���Ǹ�����
		path[v] = v0 ;
		// ��ʼ����С·������Ϊ�ڽӾ�����Ȩֵ
		lowcost[v] = G.arcs[v0][v].adj;
	}
	lowcost[v0] = 0 ;
	flag[v0]  = 1 ;    // ��ʼ��v0���뵽S
	for(k = 1 ; k < G.vexnum ; k++)
	{
		min = INFINITY ;
		for(v = 0 ; v < G.vexnum ; v++)
			if((lowcost[v] < min) && (!flag[v])) // �� V-S ���ҵ���һ�����·��
			{
			min = lowcost[v] ;
			w = v ;
			}
        flag[w] = 1 ;          // v0-->w Ϊ��һ�����·��,w���뵽S
		for(i = 0 ; i < G.vexnum ; i++)
			if(((min + G.arcs[w][i].adj)< lowcost[i] )&&(!flag[i]))
			{
				lowcost[i] = min + G.arcs[w][i].adj ;
				path[i] = w ;      // �������if, i ��ǰ�����仯Ϊw
			}
		}
}

void PrintShortestPath(int v0, int path[], int lowcost[],int vexnum)
{
  // ����path[]����ĵ����ԣ���֪��·��ĩ�˽ڵ�
  // ������ö�ջ�����ȱ�����涥�㣬�������ȳ����·��
 
  int stack[MAX_VERTEX_NUM] ;  
  int top  ;
  int i, v ;
  char a,b;
 
  for(i = 0 ; i < vexnum ; i++)
  {
    if(lowcost[i] == INFINITY)
    {
		switch(v0)
		{
		case 0:a='A';break;
		case 1:a='B';break;
		case 2:a='C';break;
		case 3:a='D';break;
		case 4:a='E';break;
		case 5:a='F';break;
		case 6:a='G';break;
		case 7:a='H';break;
		case 8:a='I';break;
		case 9:a='J';break;
		}
		switch(i)
		{
		case 0:b='A';break;
		case 1:b='B';break;
		case 2:b='C';break;
		case 3:b='D';break;
		case 4:b='E';break;
		case 5:b='F';break;
		case 6:b='G';break;
		case 7:b='H';break;
		case 8:b='I';break;
		case 9:b='J';break;
		}
      printf("%c �� %c ������·��\n\n", a, b);
      continue ;
    }
    if(i == v0) continue ;
  		switch(v0)
		{
		case 0:a='A';break;
		case 1:a='B';break;
		case 2:a='C';break;
		case 3:a='D';break;
		case 4:a='E';break;
		case 5:a='F';break;
		case 6:a='G';break;
		case 7:a='H';break;
		case 8:a='I';break;
		case 9:a='J';break;
		}
		switch(i)
		{
		case 0:b='A';break;
		case 1:b='B';break;
		case 2:b='C';break;
		case 3:b='D';break;
		case 4:b='E';break;
		case 5:b='F';break;
		case 6:b='G';break;
		case 7:b='H';break;
		case 8:b='I';break;
		case 9:b='J';break;
		}
    printf("%c �� %c �����·��:\n", a, b) ;
    top = -1 ;       // ��ջ��ʼ��
    v = i ;
    while(v != v0)
    {
      top++ ;      // path[v]��ջ
      stack[top] = path[v];
      v =  path[v];
    }
    while(top != -1)
    {         // ·���ڵ��ջ����ӡ
      printf("V%d->", stack[top]) ;
      top--;
    }
    printf("V%d\n", i) ;  // Ŀ�Ķ���δ��ջ ��������ӡ
    printf("��С����: %d\n\n", lowcost[i]) ;
  }
}

void main()
{
	MGraph g;
	Init(g);
	int path[MAX_VERTEX_NUM] ;
	int lowcost[MAX_VERTEX_NUM] ;
	ShortestPath_DIJ(g, 0, path, lowcost) ;
	PrintShortestPath(0, path, lowcost, g.vexnum) ;

}