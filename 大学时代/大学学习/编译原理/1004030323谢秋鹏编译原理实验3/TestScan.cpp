
#include <locale>
#include <iostream>
#include <fstream>
using namespace std;

//���涨�屣����Ϊ�򻯳���ʹ���ַ�ָ�����鱣�����б����֡�
//��������ӱ����֣��ɼ�����ӣ����޸ı�������Ŀ
#define keywordSum  8
char *keyword[keywordSum]={ "if","else","for","while","do","int","read","write"};
//���涨�崿���ֽ��������Ҫ�����
char singleword[50]="+-*(){};,:";
//���涨��˫�ֽ�������ַ�
char doubleword[10]="><=!";
extern char Scanin[300], Scanout[300]; //���ڽ�����������ļ���,��TEST_main.c�ж���
ifstream fileread;
ofstream filewrite; 
//extern FILE *fileread,*filewrite; //����ָ����������ļ���ָ��,��TEST_main.c�ж���
int TESTscan()//�ʷ���������
{
   char ch,token[40]; //chΪÿ�ζ�����ַ���token���ڱ���ʶ����ĵ���
   int es=0,j,n; //es������룬0��ʾû�д���j,nΪ��ʱ������������ϵ���ʱ���±��
   cout<<"������Դ�����ļ���������·������";
   cin>>Scanin;
   cout<<"������ʷ���������ļ���������·������";
   cin>>Scanout;
   cout<<Scanin<<"\n";
	cout<<Scanout<<"\n";
	

   fileread.open(Scanin);
   if (!fileread.is_open()) //�ж������ļ����Ƿ���ȷ
   {
      cout<<"\n�򿪴ʷ����������ļ�����!\n";
      return(1);//�����ļ������ش������1
   }
  
   
   filewrite.open(Scanout);
   if  (!filewrite.is_open())  //�ж�����ļ����Ƿ���ȷ
   {
      cout<<"\n�����ʷ���������ļ�����!\n";
      return(2); //����ļ������ش������2
   }
    
   fileread.get(ch);//ch=getc(fileread);
   cout<<ch<<"\n";
   
   while(fileread.good())//ch!=EOF)
   {
      while ((ch==' '||ch=='\n'||ch=='\r'||ch=='\t')&&fileread.good())
	  {
		  fileread.get(ch);//���ļ��ж�һ���ַ�
		  
	  }
	  if (!fileread.good()) break;
      if (isalpha(ch))   //�������ĸ������б�ʶ������
      {
		 token[0]=ch; j=1;
		 fileread.get(ch);//���ļ��ж�һ���ַ�
		 cout<<ch<<"\n";
		 while(isalnum(ch))  //�������ĸ��������ϱ�ʶ��������������ʶ����Ͻ���
		 {
			token[j++]=ch;  //��ϵı�ʶ��������token��
			fileread.get(ch);//ch=getc(fileread);  //����һ���ַ�
			cout<<ch<<"\n";
		 }
		 token[j]='\0';  //��ʶ����Ͻ���	 
		 //�鱣����
		 n=0;
		 while ((n<keywordSum) && strcmp(token,keyword[n])) n++;
		 if (n>=keywordSum)  //���Ǳ����֣������ʶ��
			filewrite<<"ID"<<" \t"<<token<<"\n";  //�����ʶ������
		else//�Ǳ����֣����������
			filewrite<<token<<" \t"<<token<<"\n";  //��������ַ���
	  } else if (isdigit(ch))//���ִ���
      {
		 token[0]=ch; j=1;
		 fileread.get(ch);//����һ���ַ�
		 cout<<ch<<"\n";
		 while (isdigit(ch))  //�����������������������������������Ͻ���
		 {
			token[j++]=ch;  //�������������token��
			fileread.get(ch);//����һ���ַ�
			cout<<ch<<"\n";
		 }
		 token[j]='\0';  //������Ͻ���		 
		 filewrite<<"NUM"<<" \t"<<token<<"\n";  //�����������
      } else if (strchr(singleword,ch)>0)  //���ַ�����
      {
		 token[0]=ch; token[1]='\0';
		 fileread.get(ch);//ch=getc(fileread);//����һ�������Ա�ʶ����һ������
		 cout<<ch<<"\n";
		 filewrite<<token<<" \t"<<token<<"\n";  //������ֽ������
      }else if (strchr(doubleword,ch)>0)  //˫�ֽ������
      {
		 token[0]=ch;
		 fileread.get(ch);//����һ���ַ��ж��Ƿ�Ϊ˫�ֽ��
		 cout<<ch<<"\n";
		 if (ch=='=')  //�����=�����˫�ֽ��
		 {
			token[1]=ch;token[2]='\0';  //���˫�ֽ������
		   	fileread.get(ch);//����һ�������Ա�ʶ����һ������
			cout<<ch<<"\n";
		 } else//����=��Ϊ���ֽ��
			token[1]='\0';
		 filewrite<<token<<" \t"<<token<<"\n";  //�������˫�ֽ������
      } else if (ch=='/')  //ע�ʹ���
      {
		 fileread.get(ch);//����һ���ַ�
		 cout<<ch<<"\n";
		 if (ch=='*')  //�����*����ʼ����ע��
		 {  char ch1;
			fileread.get(ch1);//ch=getc(fileread);  //����һ���ַ�
			do
			{  ch=ch1;fileread.get(ch1);}  //ɾ��ע��
			while ((ch!='*' || ch1!='/')&&ch1!=EOF);  //ֱ������ע�ͽ��������ļ�β
			fileread.get(ch);//����һ�������Ա�ʶ����һ������
			cout<<ch<<"\n";
		 } else  //����*�����ֽ��/
		 {
			 token[0]='/'; token[1]='\0';
			 filewrite<<token<<" \t"<<token<<"\n";  //������ֽ��/
		 }
	  } else//������
	  {
		 token[0]=ch;token[1]='\0';
		 fileread.get(ch);//����һ�������Ա�ʶ����һ������
		 cout<<ch<<"\n";
		 es=3;  //���ô������
		 filewrite<<"ERROR"<<" \t"<<token<<"\n";  //����������
      }
   }
	fileread.close();//�ر���������ļ�
	filewrite.close();
	return(es);  //����������
}
