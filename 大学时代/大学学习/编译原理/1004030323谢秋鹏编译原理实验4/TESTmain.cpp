//������
#include <locale>
#include <iostream>
#include <fstream>
using namespace std;
extern int TESTscan();
extern int TESTparse();
char Scanin[300],Scanout[300]; //���ڽ�����������ļ���

void main(){
	int es=0;
	if (es==0) es=TESTscan();//���ʷ�����
    if (es>0) cout<<"�ʷ������д�,����ֹͣ!";
	else cout<<"�ʷ������ɹ�!\n";
	if (es==0) 
	{		
  		es=TESTparse();	//���﷨����
		if (es==0) 	cout<<"�﷨�����ɹ�!\n";
		else	cout<<"�﷨��������!\n";
	}
}
