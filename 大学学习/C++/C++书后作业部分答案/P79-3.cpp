// P79-3.cpp 猜数游戏

#include <iostream.h>
void main(void)
{	long lg=89, lc, lm, k=1;
	cout<<"请输入猜测的数字:"<<endl ;
	cin>>lc;
	lm=lc-lg;
	if(lm>0) lm=1;
	else if(lm<0) lm=-1;

	while(k<10)
	{	switch (lm)
		{	case -1: cout<<"小了, 重猜"<<endl; break;
			case 0:  cout<<"恭喜,猜对了!"<<endl; goto EXIT;
			case 1:  cout<<"大了, 重猜"<<endl;
		}
		k++;
		if(k==10) goto EXIT;
		cout<<"请输入猜测的数字:"<<endl ;
		cin>>lc;
		lm=lc-lg;
		if(lm>0) lm=1;
		else if(lm<0) lm=-1;
	}
	EXIT: cout<<"游戏结束,数字是: "<<lg<<". 欢迎再来!\n";
}
