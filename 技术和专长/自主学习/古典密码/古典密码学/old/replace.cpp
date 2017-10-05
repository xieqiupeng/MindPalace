#include<iostream.h>
#include<stdio.h>
#define max 100
struct usekey
{
	char ch;
	int flag;
}
void creatkey(usekey *&inchar,char *&outchar,int num)
{
	int j=-1,temp=0;
	for(int n=num;n<(num+256);n++)
	{
		inchar[n].ch=(char)temp;
		inchar[n].flag=0;
		temp++;
	}
	for(int i=0;i<(num+256);i++)
	{
		if(inchar[i].flag==0)
		{
			for(int k=i+1;k<(num+256);k++)
			{
				if(inchar[i].ch==inchar[k].ch)
					inchar[k].flag=1;
			}
			j++;outchar[j]=inchar[i].ch;
			inchar[i].flag=1;
		}
	}
}
void Encrypt(char * &intext,char * &outtext,char * &textkey,int choice,int num)
{
	if(choice==1)
	{
		for(int i=0;i<num;i++)
		{
	        for(int j=0;j<256;j++)
			{
				if((char)j==intext[i]) {outtext[i]=textkey[j];break;}
			}

		}
	}
		if(choice==0)
	{
		for(int k=0;k<num;k++)
		{
	       for(int p=0;p<256;p++)
		   {
			   if(textkey[p]==intext[k]) {outtext[k]=(char)p;}
		   }
		}
	}
}
void main()
{
	usekey *initkey=new usekey[max];char *key=new char[256];char *ou_in=new char[max];
	char *inchar=new char[max];char *outchar=new char[max];char temp;int x=-1,y=-1;
	cout<<"*****************古典密码体制——替换密码********************"<<endl;
	cout<<"请输入密钥串并以/结束："<<endl;
	do
	{
		temp=getchar();
		if((temp)!=' ') {x++;initkey[x].ch=temp;initkey[x].flag=0;}
	}while(initkey[x].ch!='/');
	creatkey(initkey,key,x);
	cout<<"请输入明文串并以/结束"<<endl;
	do
	{
		y++;inchar[y]=getchar();
	}while(inchar[y]!='/');
	cout<<"明文被加密后的密文为："<<endl;
	Encrypt(inchar,outchar,key,1,y);
	for(int m=1;m<y;m++)
	cout<<outchar[m];
	cout<<endl;
	cout<<"密文被解密后的明文为："<<endl;
   	Encrypt(outchar,ou_in,key,0,y);
    for(int n=1;n<y;n++)
		cout<<ou_in[n];
	cout<<endl;

}
