// P147-4.cpp 21��ΧһȦ,����5�ı����뿪,һֱ����ȥֱ��ʣһ��.����˱��

#include <iostream.h>
void main(void)
{	int i1[120];	//��ű��
	int ik=1;		//����Ƿ񵽵������
	int ia=0;		//ָ��ʣ��������������ͷ�±�
	int ib=21;		//ָ��ʣ��������������β�±�
	int ic=21;		//���뻹ʣ�¼�����
	
	//cout<<"������һ��ĸ:";
	for(ic=0;ic<21;ic++) i1[ic]=ic+1;
	do
	{	if(ik!=5)
		{	i1[ib++]=i1[ia++];
			ik++;
		}
		else
		{	ik=1;
			ia++;
			ic--;
		}
	}while(ic>1);
	cout<<"���ʣ�µı��Ϊ: "<<i1[--ib]<<endl;
}
