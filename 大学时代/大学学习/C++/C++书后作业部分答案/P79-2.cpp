// P79-2.cpp 乒乓球比赛赛手名单

#include <iostream.h>
void main(void)
{	char cm1, cm2;
	cout<<"请输入甲队赛手代号(A或B或C):"<<endl ;
	cin>>cm1;
	cout<<"请输入乙队赛手代号(X或Y或Z):"<<endl ;
	cin>>cm2;
	cout<<"抽签结果:\n";
	switch (cm1)
	{	case 'A':
			switch(cm2)
			{	case 'X': cout<<"A:X, B:Z, C:Y"<<endl; break;
				case 'Y': cout<<"无效,重抽签! 因为Y只能与C比赛."<<endl; break;
				case 'Z': cout<<"A:Z, B:X, C:Y"<<endl;
			} break;
		case 'B':
			switch(cm2)
			{	case 'X': cout<<"A:Z, B:X, C:Y"<<endl; break;
				case 'Y': cout<<"无效,重抽签! 因为Y只能与C比赛."<<endl; break;
				case 'Z': cout<<"A:X, B:Z, C:Y"<<endl;
			}break;
		case 'C':
			switch(cm2)
			{	case 'X': cout<<"无效,重抽签! 因为Y只能与C比赛."<<endl; break;
				case 'Y': cout<<"A:X, B:Z, C:Y"<<endl; break;
				case 'Z': cout<<"无效,重抽签! 因为Y只能与C比赛."<<endl;
			}
	}
	cout<<"抽签结束!\n";
}
