
#include <locale>
#include <iostream>
#include <fstream>
using namespace std;

//下面定义保留，为简化程序，使用字符指针数组保存所有保留字。
//如果想增加保留字，可继续添加，并修改保留字数目
#define keywordSum  8
char *keyword[keywordSum]={ "if","else","for","while","do","int","read","write"};
//下面定义纯单分界符，如需要可添加
char singleword[50]="+-*(){};,:";
//下面定义双分界符的首字符
char doubleword[10]="><=!";
extern char Scanin[300], Scanout[300]; //用于接收输入输出文件名,在TEST_main.c中定义
ifstream fileread;
ofstream filewrite; 
//extern FILE *fileread,*filewrite; //用于指向输入输出文件的指针,在TEST_main.c中定义
int TESTscan()//词法分析函数
{
   char ch,token[40]; //ch为每次读入的字符，token用于保存识别出的单词
   int es=0,j,n; //es错误代码，0表示没有错误。j,n为临时变量，控制组合单词时的下标等
   cout<<"请输入源程序文件名（包括路径）：";
   cin>>Scanin;
   cout<<"请输入词法分析输出文件名（包括路径）：";
   cin>>Scanout;
   cout<<Scanin<<"\n";
	cout<<Scanout<<"\n";
	

   fileread.open(Scanin);
   if (!fileread.is_open()) //判断输入文件名是否正确
   {
      cout<<"\n打开词法分析输入文件出错!\n";
      return(1);//输入文件出错返回错误代码1
   }
  
   
   filewrite.open(Scanout);
   if  (!filewrite.is_open())  //判断输出文件名是否正确
   {
      cout<<"\n创建词法分析输出文件出错!\n";
      return(2); //输出文件出错返回错误代码2
   }
    
   fileread.get(ch);//ch=getc(fileread);
   cout<<ch<<"\n";
   
   while(fileread.good())//ch!=EOF)
   {
      while ((ch==' '||ch=='\n'||ch=='\r'||ch=='\t')&&fileread.good())
	  {
		  fileread.get(ch);//从文件中读一个字符
		  
	  }
	  if (!fileread.good()) break;
      if (isalpha(ch))   //如果是字母，则进行标识符处理
      {
		 token[0]=ch; j=1;
		 fileread.get(ch);//从文件中读一个字符
		 cout<<ch<<"\n";
		 while(isalnum(ch))  //如果是字母数字则组合标识符；如果不是则标识符组合结束
		 {
			token[j++]=ch;  //组合的标识符保存在token中
			fileread.get(ch);//ch=getc(fileread);  //读下一个字符
			cout<<ch<<"\n";
		 }
		 token[j]='\0';  //标识符组合结束	 
		 //查保留字
		 n=0;
		 while ((n<keywordSum) && strcmp(token,keyword[n])) n++;
		 if (n>=keywordSum)  //不是保留字，输出标识符
			filewrite<<"ID"<<" \t"<<token<<"\n";  //输出标识符符号
		else//是保留字，输出保留字
			filewrite<<token<<" \t"<<token<<"\n";  //输出保留字符号
	  } else if (isdigit(ch))//数字处理
      {
		 token[0]=ch; j=1;
		 fileread.get(ch);//读下一个字符
		 cout<<ch<<"\n";
		 while (isdigit(ch))  //如果是数字则组合整数；如果不是则整数组合结束
		 {
			token[j++]=ch;  //组合整数保存在token中
			fileread.get(ch);//读下一个字符
			cout<<ch<<"\n";
		 }
		 token[j]='\0';  //整数组合结束		 
		 filewrite<<"NUM"<<" \t"<<token<<"\n";  //输出整数符号
      } else if (strchr(singleword,ch)>0)  //单分符处理
      {
		 token[0]=ch; token[1]='\0';
		 fileread.get(ch);//ch=getc(fileread);//读下一个符号以便识别下一个单词
		 cout<<ch<<"\n";
		 filewrite<<token<<" \t"<<token<<"\n";  //输出单分界符符号
      }else if (strchr(doubleword,ch)>0)  //双分界符处理
      {
		 token[0]=ch;
		 fileread.get(ch);//读下一个字符判断是否为双分界符
		 cout<<ch<<"\n";
		 if (ch=='=')  //如果是=，组合双分界符
		 {
			token[1]=ch;token[2]='\0';  //组合双分界符结束
		   	fileread.get(ch);//读下一个符号以便识别下一个单词
			cout<<ch<<"\n";
		 } else//不是=则为单分界符
			token[1]='\0';
		 filewrite<<token<<" \t"<<token<<"\n";  //输出单或双分界符符号
      } else if (ch=='/')  //注释处理
      {
		 fileread.get(ch);//读下一个字符
		 cout<<ch<<"\n";
		 if (ch=='*')  //如果是*，则开始处理注释
		 {  char ch1;
			fileread.get(ch1);//ch=getc(fileread);  //读下一个字符
			do
			{  ch=ch1;fileread.get(ch1);}  //删除注释
			while ((ch!='*' || ch1!='/')&&ch1!=EOF);  //直到遇到注释结束符或文件尾
			fileread.get(ch);//读下一个符号以便识别下一个单词
			cout<<ch<<"\n";
		 } else  //不是*则处理单分界符/
		 {
			 token[0]='/'; token[1]='\0';
			 filewrite<<token<<" \t"<<token<<"\n";  //输出单分界符/
		 }
	  } else//错误处理
	  {
		 token[0]=ch;token[1]='\0';
		 fileread.get(ch);//读下一个符号以便识别下一个单词
		 cout<<ch<<"\n";
		 es=3;  //设置错误代码
		 filewrite<<"ERROR"<<" \t"<<token<<"\n";  //输出错误符号
      }
   }
	fileread.close();//关闭输入输出文件
	filewrite.close();
	return(es);  //返回主程序
}
