#include<iostream.h>
#include<stdio.h>
#define max 100
void creatkey(int *&Akey,int *&Bkey,int &keynum)
{
	cout<<"��������Կ��λ����10λ���ڣ���"<<endl;
	cin>>keynum;
	cout<<"��ָ����������ԿΪ��"<<endl;
	for(int i=0;i<keynum;i++)
		cout<<i+1<<" ";
	cout<<endl;
	cout<<"��ָ��������Կ��һ���û���"<<endl;
	for(int j=0;j<keynum;j++)
	{
		cin>>Akey[j];Bkey[Akey[j]-1]=j+1;
	}
	cout<<"�����Ӧ����Կ�����û�Ϊ��"<<endl;
	for(int k=0;k<keynum;k++)
		cout<<Bkey[k]<<" ";
	cout<<endl;
}
void gettruechar(char *&inchar,char *&truechar,int charnum,int &truenum)
{
	truenum=0;
	for(int i=0;i<charnum;i++) {if(inchar[i]!=' ') {truechar[truenum]=inchar[i];truenum++;}}
}
void Encrypt(char *&inchar,char *&outchar,char *&truechar,int *&Akey,int *&Bkey,int charnum,int keynum,int truenum,int choice)
{
	int temp=0,temp1=0,temp2=0;
	if(choice==1)
	{
		while(temp<(truenum/keynum))
		{
			if(inchar[temp1]==' ') {outchar[temp1]=' ';temp1++;}
			else
			{
				outchar[temp1]=truechar[temp*keynum+Akey[temp2%keynum]-1];
				if((temp2%keynum)==(keynum-1)) temp++;
				temp2++;temp1++;
			}
		}
		for(int i=temp1;i<charnum;i++) outchar[i]=inchar[i];
	}
	if(choice==0)
	{
		while(temp<(truenum/keynum))
		{
			if(inchar[temp1]==' ') {outchar[temp1]=' ';temp1++;}
			else
			{
				outchar[temp1]=truechar[temp*keynum+Bkey[temp2%keynum]-1];
				if((temp2%keynum)==(keynum-1)) temp++;
				temp2++;temp1++;
			}
		}
		for(int i=temp1;i<charnum;i++) outchar[i]=inchar[i];
	}
}
void main()
{
	char *inchar=new char[max];char *outchar=new char[max];char *out_in=new char[max];
	char *truechar=new char[max];int *Akey=new int[10];int *Bkey=new int[10];int truenum,keynum,charnum=-1;
	cout<<"******************�ŵ��������ơ����û�����***********************"<<endl;
	creatkey(Akey,Bkey,keynum);
    cout<<"���������Ĵ�����/��ʾ������"<<endl;
	do
	{
	    charnum++;
		inchar[charnum]=getchar();
	}while(inchar[charnum]!='/');
	gettruechar(inchar,truechar,charnum,truenum);
	cout<<"���ļ��ܺ������Ϊ��"<<endl;
	Encrypt(inchar,outchar,truechar,Akey,Bkey,charnum,keynum,truenum,1);
	for(int i=0;i<charnum;i++)
	{
		if(outchar[i]!=' ')
		cout<<outchar[i];
	}
	cout<<endl;
    cout<<"���Ľ��ܺ������Ϊ��"<<endl;
	gettruechar(outchar,truechar,charnum,truenum);
    Encrypt(outchar,out_in,truechar,Akey,Bkey,charnum,keynum,truenum,0);
    for(int j=0;j<charnum;j++)
		cout<<out_in[j];
	cout<<endl;
}