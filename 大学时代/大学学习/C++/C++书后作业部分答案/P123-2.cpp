// P123-2.cpp ����һС��,��ӡ����С���Ķ������ַ���

#include <iostream.h>
void main(void)
{	unsigned long ln,lc=256,k=1,lk;
	double dn=0.1298;

	cout<<"������һС��:";
	//cin>>dn;
	
	cout<<"\n   ������ƽ��Ϊ:";
	
	for(k=1;k<19;k++)
	{	dn=dn*2;
		ln=(long)dn;
		if(ln>0) cout<<'1';
		else cout<<'0';
	}
	cout<<endl;
//*/
}
