// P147-1.cpp ������������һ��

#include <iostream.h>
void main(void)
{	int i1[11]={-65,-12,-9,0,10,12,54,63,98,123};		//�������
	int ik=1;		//����Ƿ񵽵������
	int ia=0;		//ָ��ʣ��������������ͷ�±�
	int ib=11;		//ָ��ʣ��������������β�±�
	int ic=21;		//���뻹ʣ�¼�����
	
	//cout<<"������һ����:";
	cin>>ik;
	ic=(ia+ib)/2;
	//for(ic=0;ic<21;ic++) i1[ic]=ic+1;
	do
	{	if(i1[ic]>ik)
		{	ib=ic;
			ic=(ia+ib)/2;
			break;
		}
		else
		{	ia=ic;
			ic=(ia+ib)/2;
			break;
		}
	}while(ic>1);
	cout<<"���ʣ�µı��Ϊ: "<<i1[--ib]<<endl;
}
