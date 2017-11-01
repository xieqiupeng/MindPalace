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
	cout<<"*****************古典密码体制——移位密码*******************"<<endl;
	cout<<"请输入密钥(1--256)之间的整数："<<endl;
	cin>>key;
	cout<<"请输入明文并以/表示结束："<<endl;
    do
	{
		c++;
		inin[c]=getchar();
	}while(inin[c]!='/');
    cout<<"明文加密后的密文为："<<endl;
    Encrypt(inin,ouou, key,1,c);
	for(int j1=0;j1<c;j1++) { cout<<ouou[j1];}
	cout<<endl;
	cout<<"密文解密后的明文为："<<endl;
    Encrypt(ouou,outout, key,0,c);
	for(int j2=0;j2<c;j2++) cout<<outout[j2];
	cout<<endl;

}
