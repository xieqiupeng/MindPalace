#include<string.h> 
#include<malloc.h> 
#include<stdio.h> 
#include<math.h> 
#include<process.h>
#include<limits.h> 
#define TRUE 1
#define FALSE 0 
#define INFINITY INT_MAX  // 用整型最大值代替∞
#define MAX_VERTEX_NUM 20  // 最大顶点个数

typedef struct ArcCell{  //弧的定义（路径）
	int adj;  //路径的权值
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct VertexType{  //顶点定义（景点）
	char name[MAX_VERTEX_NUM];  //景点名称
	char daihao[MAX_VERTEX_NUM];  //景点代号
}VertexType;

typedef struct MGraph{  //图的定义
	VertexType vexs[MAX_VERTEX_NUM];  //存储顶点的一维数组
	AdjMatrix arcs;  //存储邻接矩阵的二维数组
	int vexnum,arcnum;  //图的顶点数，弧数
}MGraph;

void Init(MGraph &G)  //初始化邻接矩阵
{
	G.vexnum=10;  //顶点数
	G.arcnum=12;  //弧数
	strcpy(G.vexs[0].name,"宿舍区");   //初始化顶点
	strcpy(G.vexs[0].daihao,"A");
	strcpy(G.vexs[1].name,"学生食堂");
	strcpy(G.vexs[1].daihao,"B");
	strcpy(G.vexs[2].name,"学生活动中心");
	strcpy(G.vexs[2].daihao,"C");
	strcpy(G.vexs[3].name,"文科实践中心");
	strcpy(G.vexs[3].daihao,"D");
	strcpy(G.vexs[4].name,"宿舍区");
	strcpy(G.vexs[4].daihao,"E");
	strcpy(G.vexs[5].name,"文体馆");
	strcpy(G.vexs[5].daihao,"F");
	strcpy(G.vexs[6].name,"钟楼");
	strcpy(G.vexs[6].daihao,"G");
	strcpy(G.vexs[7].name,"图书馆");
	strcpy(G.vexs[7].daihao,"H");
	strcpy(G.vexs[8].name,"操场");
	strcpy(G.vexs[8].daihao,"I");
	strcpy(G.vexs[9].name,"求知广场");
	strcpy(G.vexs[9].daihao,"J");
	int i,j;
	for(i=0;i<G.vexnum;i++)    //初始化邻接矩阵
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j].adj=INFINITY;
	 G.arcs[0][1].adj=G.arcs[1][0].adj=400;  //构造邻接矩阵
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
		// 初始化flag，flag[v] 表示是否v0到v的最短路径已找到,1表示找到，0表示没有
		flag[v] = 0 ; 
		// path[v] 表示v0到v的最短路径中,v之前的那个顶点
		path[v] = v0 ;
		// 初始化最小路径长度为邻接矩阵中权值
		lowcost[v] = G.arcs[v0][v].adj;
	}
	lowcost[v0] = 0 ;
	flag[v0]  = 1 ;    // 初始化v0加入到S
	for(k = 1 ; k < G.vexnum ; k++)
	{
		min = INFINITY ;
		for(v = 0 ; v < G.vexnum ; v++)
			if((lowcost[v] < min) && (!flag[v])) // 在 V-S 中找到下一条最短路径
			{
			min = lowcost[v] ;
			w = v ;
			}
        flag[w] = 1 ;          // v0-->w 为下一条最短路径,w加入到S
		for(i = 0 ; i < G.vexnum ; i++)
			if(((min + G.arcs[w][i].adj)< lowcost[i] )&&(!flag[i]))
			{
				lowcost[i] = min + G.arcs[w][i].adj ;
				path[i] = w ;      // 如果满足if, i 的前驱结点变化为w
			}
		}
}

void PrintShortestPath(int v0, int path[], int lowcost[],int vexnum)
{
  // 由于path[]数组的递推性，先知道路径末端节点
  // 因此利用堆栈特性先保存后面顶点，最后后入先出输出路径
 
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
      printf("%c 到 %c 不存在路径\n\n", a, b);
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
    printf("%c 到 %c 的最短路径:\n", a, b) ;
    top = -1 ;       // 堆栈初始化
    v = i ;
    while(v != v0)
    {
      top++ ;      // path[v]入栈
      stack[top] = path[v];
      v =  path[v];
    }
    while(top != -1)
    {         // 路径节点出栈，打印
      printf("V%d->", stack[top]) ;
      top--;
    }
    printf("V%d\n", i) ;  // 目的顶点未入栈 ，单独打印
    printf("最小距离: %d\n\n", lowcost[i]) ;
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