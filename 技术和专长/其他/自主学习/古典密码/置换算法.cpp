#include <iostream>
#include <cstring>
using namespace std;
void encrypt()
{
	char str[100];
	char str1[100];
	char a[100];
	cout<<"������������Կ��"<<endl;
    cin.get();
	//�������壬ÿ������������ǰ�����
    cin.get(str,100);
    cout<<"�������������ģ�"<<endl;
    cin.get();
    cin.get(a,100);
    int len=strlen(str);
    char b[100][100];
    char c[100][100];
    char d[100][100];
    int j=0;
    int t=0;
    int j1;
    int t1;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
		{
			b[j][t]=a[i];
			c[j][t]=a[i];
			t++;
			if(t>=len)
			{
				t=0;
				j++;
			}
			j1=j;
			t1=t;
		}
		else
		{
			cout<<"CRYPT_ERROR";
		};
    }
	cout<<"CRYPT_OK\n";
    strcpy(str1,str);
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(str1[j]>str1[j+1])
            {
                char ch=str1[j];
                str1[j]=str1[j+1];
                str1[j+1]=ch;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(str[i]==str1[j])
            {
               for(int x=0;x<j1;x++)
               {
                   c[x][i]=b[x][j];
               }
        }
    }
    }
    for(i=0;i<j1;i++)
    {
        strcpy(d[i],c[i]);
    }
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(str[i]==str1[j])
            {
               for(int x=0;x<j1;x++)
               {
                   d[x][i]=c[x][j];
               }
        }
    }
    }
    cout<<"���û��㷨�������Ϊ��"<<endl;
    for(i=0;i<len;i++)
    {
        for(int j=0;j<j1;j++)
        cout<<d[j][i]<<" ";
    }
}
void decrypt()

{
    char str[100];
    char str1[100];
    char a[100];
    cout<<"������������Կ��"<<endl;
    cin.get();
    cin.get(str,100);
    cout<<"�������������ģ�"<<endl;
    cin.get();
    cin.get(a,100);
    int len=strlen(str);
    int len1=strlen(a);
    int le=len1/len;
    char b[100][100];
    char c[100][100];
    char d[100][100];
    int j=0;
    int t=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
		{
			b[j][t]=a[i];
			c[j][t]=a[i];
			j++;
			if(j>=le)
			{
				j=0;
				t++;
			}
		}
		else
		{
			cout<<"CRYPT_ERROR";
		};
    }
	cout<<"CRYPT_OK\n";
    strcpy(str1,str);
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(str1[j]>str1[j+1])
            {
                char ch=str1[j];
                str1[j]=str1[j+1];
                str1[j+1]=ch;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(str[i]==str1[j])
            {
               for(int x=0;x<le;x++)
               {
                   c[x][i]=b[x][j];
               }
        }
    }
    }
    for(i=0;i<le;i++)
    {
        strcpy(d[i],c[i]);
    }
    for(i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(str[i]==str1[j])
            {
               for(int x=0;x<le;x++)
               {
                   d[x][i]=c[x][j];
               }
        }
    }
    }
    cout<<"���û��㷨���ܺ������Ϊ��"<<endl;
    for(i=0;i<le;i++)
    {
        for(int j=0;j<len;j++)
        cout<<d[i][j]<<" ";
    }
}
int main()
{

    int choice;
    cout<<"����������ѡ��:"<<endl;
    cout<<"1.����;2.����;"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            break;
    }
	int i;
	cout<<"\n��������س�������";
	cin>>i;
    return 0;
}
