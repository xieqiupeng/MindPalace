// P79-3.cpp ������Ϸ

#include <iostream.h>
void main(void)
{	long lg=89, lc, lm, k=1;
	cout<<"������²������:"<<endl ;
	cin>>lc;
	lm=lc-lg;
	if(lm>0) lm=1;
	else if(lm<0) lm=-1;

	while(k<10)
	{	switch (lm)
		{	case -1: cout<<"С��, �ز�"<<endl; break;
			case 0:  cout<<"��ϲ,�¶���!"<<endl; goto EXIT;
			case 1:  cout<<"����, �ز�"<<endl;
		}
		k++;
		if(k==10) goto EXIT;
		cout<<"������²������:"<<endl ;
		cin>>lc;
		lm=lc-lg;
		if(lm>0) lm=1;
		else if(lm<0) lm=-1;
	}
	EXIT: cout<<"��Ϸ����,������: "<<lg<<". ��ӭ����!\n";
}
