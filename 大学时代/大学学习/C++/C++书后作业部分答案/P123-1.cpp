// P123-1.cpp ��5������ת����10���ƺ�7������

#include <iostream.h>
void main(void)
{	long ln5=232, ln10=0, ln7[20], lc=0,k=1;
	cout<<"���������0��5��������:"<<endl ;
	//cin>>ln5;
	
	cout<<"\n  5������ "<<ln5<<" ת����10������Ϊ:";
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
	
	cout<<",  ת����7������Ϊ:";
	k--;
	for(;k>=0;k--)
	{ cout<<ln7[k];
	}
	cout<<endl;
//*/
}
