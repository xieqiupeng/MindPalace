// P123-2.cpp 输入一小数,打印出该小数的二进制字符串

#include <iostream.h>
void main(void)
{	unsigned long ln,lc=256,k=1,lk;
	double dn=0.1298;

	cout<<"请输入一小数:";
	//cin>>dn;
	
	cout<<"\n   其二进制结果为:";
	
	for(k=1;k<19;k++)
	{	dn=dn*2;
		ln=(long)dn;
		if(ln>0) cout<<'1';
		else cout<<'0';
	}
	cout<<endl;
//*/
}
