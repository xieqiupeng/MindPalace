#include <iostream.h>
#include <stdio.h>
#define max 100
static char A_Z[26]=
{
	'a','b','c','d','e','f',
    'g','h','i','j','k','l',
	'm','n','o','p','q','r',
	's','t','u','v','w','x',
	'y','z'
};
void creatkey(int *&intkey,int &num)
{
    num=-1;
	char *charkey=new char[27];
	cout<<"******************古典的密码体制——Vigenere密码*********************"<<endl;
	cout<<"请输入密钥字（26个以内的字母组成）并以/表示结束："<<endl;
	do
	{
		num++;cin>>charkey[num];
	}while(charkey[num]!='/');
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<26;j++)
			if(charkey[i]==A_Z[j]) {intkey[i]=j;break;}
	}
}
void Encrypt(char *&inchar,char *&outchar,int *&intkey,int charnum,int keynum,int choice)
{
	int temp=-1;
	if(choice==1)
	{
		for(int i=0;i<charnum;i++)
		{
			if(inchar[i]==' ') {outchar[i]=' ';}
			else
			{
				for(int j=0;j<26;j++)
				{
					if(inchar[i]==A_Z[j]) {outchar[i]=A_Z[(intkey[(++temp)%keynum]+j)%26];}
				}
			}
		}
	}
	if(choice==0)
	{
		for(int i=0;i<charnum;i++)
		{
			if(inchar[i]==' ') {outchar[i]=' ';}
			else
			{
				for(int j=0;j<26;j++)
				{
					if(inchar[i]==A_Z[j]) {outchar[i]=A_Z[(j-intkey[(++temp)%keynum]+26)%26];}
				}
			}
		}
	}
}
void main()
{
	char *inchar=new char [max];char *ouchar=new char [max];char *ou_in=new char [max];
	int chnum=-1,keynum;int *inkey=new int [26];
    creatkey(inkey,keynum);
	cout<<"请输入明文串并以/表示结束："<<endl;
	do
	{
		chnum++;inchar[chnum]=getchar();
	}while(inchar[chnum]!='/');
	cout<<"明文加密后的密文为："<<endl;
	Encrypt(inchar,ouchar,inkey,chnum,keynum,1);
	for(int x=0;x<chnum;x++) {if(ouchar[x]!=' ') cout<<ouchar[x];}
	cout<<endl;
    cout<<"密文解密后的明文为："<<endl;
    Encrypt(ouchar,ou_in,inkey,chnum,keynum,0);
    for(int y=0;y<chnum;y++)
		cout<<ou_in[y];
	cout<<endl;
}