// P79-2.cpp ƹ���������������

#include <iostream.h>
void main(void)
{	char cm1, cm2;
	cout<<"������׶����ִ���(A��B��C):"<<endl ;
	cin>>cm1;
	cout<<"�������Ҷ����ִ���(X��Y��Z):"<<endl ;
	cin>>cm2;
	cout<<"��ǩ���:\n";
	switch (cm1)
	{	case 'A':
			switch(cm2)
			{	case 'X': cout<<"A:X, B:Z, C:Y"<<endl; break;
				case 'Y': cout<<"��Ч,�س�ǩ! ��ΪYֻ����C����."<<endl; break;
				case 'Z': cout<<"A:Z, B:X, C:Y"<<endl;
			} break;
		case 'B':
			switch(cm2)
			{	case 'X': cout<<"A:Z, B:X, C:Y"<<endl; break;
				case 'Y': cout<<"��Ч,�س�ǩ! ��ΪYֻ����C����."<<endl; break;
				case 'Z': cout<<"A:X, B:Z, C:Y"<<endl;
			}break;
		case 'C':
			switch(cm2)
			{	case 'X': cout<<"��Ч,�س�ǩ! ��ΪYֻ����C����."<<endl; break;
				case 'Y': cout<<"A:X, B:Z, C:Y"<<endl; break;
				case 'Z': cout<<"��Ч,�س�ǩ! ��ΪYֻ����C����."<<endl;
			}
	}
	cout<<"��ǩ����!\n";
}
