#include <iostream.h>
#include <string.h>
#include <stdio.h>
#define max 100
void Encrypt( char *&inchar,char *&outchar,int key,int a,int num)
{
	if((a==1)&&(inchar[0]!='/'))
	{
		for(int i=0;i<num;i++)
		{
			outchar[i]=(char)((int)inchar[i]+key)%256;
		}
	}
	if((a==0)&&(inchar[0]!='/'))
	{
		for(int i=0;i<num;i++)	
		{
			outchar[i]=(char)((int)inchar[i]-key+256)%256;
		}
	}
}
void main()
{
	char *inin=new char[max],*ouou=new char[max],*outout=new char[max];int key,c=-1;
	cout<<"*****************�ŵ��������ơ�����λ����*******************"<<endl;
	cout<<"��������Կ(1--256)֮���������"<<endl;
	cin>>key;
	cout<<"���������Ĳ���/��ʾ������"<<endl;
    do
	{
		c++;
		inin[c]=getchar();
	}while(inin[c]!='/');
    cout<<"���ļ��ܺ������Ϊ��"<<endl;
    Encrypt(inin,ouou, key,1,c);
	for(int j1=0;j1<c;j1++) { cout<<ouou[j1];}
	cout<<endl;
	cout<<"���Ľ��ܺ������Ϊ��"<<endl;
    Encrypt(ouou,outout, key,0,c);
	for(int j2=0;j2<c;j2++) cout<<outout[j2];
	cout<<endl;

}
