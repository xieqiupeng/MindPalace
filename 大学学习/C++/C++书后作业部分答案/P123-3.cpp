// P123-3.cpp 设置条件编译,使之根据需要将小写字母改写在大字字母,或反之

#include <iostream.h>
#define OK
void main(void)
{	//unsigned long ln,lc=256,k=1,lk;
	//double dn=0.1298;
	char cc='z';

	cout<<"请输入一字母:";
	//cin>>cc;
	#ifdef OK
	if(cc>64&&cc<91) { cc+=32; cout<<cc; }
	#else
	if(cc>96&&cc<123) { cc-=32; cout<<cc; }
	#endif
	
	cout<<endl;
//*/
}
