// P123-3.cpp ������������,ʹ֮������Ҫ��Сд��ĸ��д�ڴ�����ĸ,��֮

#include <iostream.h>
#define OK
void main(void)
{	//unsigned long ln,lc=256,k=1,lk;
	//double dn=0.1298;
	char cc='z';

	cout<<"������һ��ĸ:";
	//cin>>cc;
	#ifdef OK
	if(cc>64&&cc<91) { cc+=32; cout<<cc; }
	#else
	if(cc>96&&cc<123) { cc-=32; cout<<cc; }
	#endif
	
	cout<<endl;
//*/
}
