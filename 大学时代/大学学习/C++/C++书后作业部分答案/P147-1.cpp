// P147-1.cpp 插入有序数列一数

#include <iostream.h>
void main(void)
{	int i1[11]={-65,-12,-9,0,10,12,54,63,98,123};		//存放数据
	int ik=1;		//存放是否到第五个数
	int ia=0;		//指向剩下人数存放数组的头下标
	int ib=11;		//指向剩下人数存放数组的尾下标
	int ic=21;		//存入还剩下几个人
	
	//cout<<"请输入一整数:";
	cin>>ik;
	ic=(ia+ib)/2;
	//for(ic=0;ic<21;ic++) i1[ic]=ic+1;
	do
	{	if(i1[ic]>ik)
		{	ib=ic;
			ic=(ia+ib)/2;
			break;
		}
		else
		{	ia=ic;
			ic=(ia+ib)/2;
			break;
		}
	}while(ic>1);
	cout<<"最后剩下的编号为: "<<i1[--ib]<<endl;
}
