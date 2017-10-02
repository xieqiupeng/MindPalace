// P147-4.cpp 21人围一圈,报到5的倍数离开,一直报下去直到剩一人.求此人编号

#include <iostream.h>
void main(void)
{	int i1[120];	//存放编号
	int ik=1;		//存放是否到第五个数
	int ia=0;		//指向剩下人数存放数组的头下标
	int ib=21;		//指向剩下人数存放数组的尾下标
	int ic=21;		//存入还剩下几个人
	
	//cout<<"请输入一字母:";
	for(ic=0;ic<21;ic++) i1[ic]=ic+1;
	do
	{	if(ik!=5)
		{	i1[ib++]=i1[ia++];
			ik++;
		}
		else
		{	ik=1;
			ia++;
			ic--;
		}
	}while(ic>1);
	cout<<"最后剩下的编号为: "<<i1[--ib]<<endl;
}
