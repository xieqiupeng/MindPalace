// P123-1.cpp 将5进制数转换成10进制和7进制数

#include <iostream.h>
void main(void)
{	long ln5=232, ln10=0, ln7[20], lc=0,k=1;
	cout<<"请输入大于0的5进制正数:"<<endl ;
	//cin>>ln5;
	
	cout<<"\n  5进制数 "<<ln5<<" 转换成10进制数为:";
	while(ln5>0)
	{	lc=(ln5%5)*k;
		ln10+=lc;
		k=k*5;
		ln5=ln5/10;
	}
	cout<<ln10;	
//*
	k=0;
	while(ln10>0)
	{	ln7[k++]=ln10%7;
		ln10=ln10/7;
	}
	
	cout<<",  转换成7进制数为:";
	k--;
	for(;k>=0;k--)
	{ cout<<ln7[k];
	}
	cout<<endl;
//*/
}
