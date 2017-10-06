//#include <stdio.h>
//#include <ctype.h>
//#include <conio.h>
#include <locale>
#include <iostream>
#include <fstream>
using namespace std;
int TESTparse();
int program();
int compound_Stat();
int statement();
int expression_stat();
int expression();
int bool_expr();
int additive_expr();
int term();
int factor();
int if_stat();
int while_stat();
int for_stat();
int write_stat();
int read_stat();
int declaration_stat();
int declaration_list();
int statement_list();
int compound_stat();

int do_stat();

char token[20],token1[100];//token保存单词符号，token1保存单词值
extern char Scanout[300]; //保存词法分析输出文件名
ifstream fp;
char ch;

//语法分析程序
int TESTparse()
{
	int es=0;
	fp.open(Scanout);
	if(!fp.is_open())
	{  
      cout<<"\n打开%s错误!\n"<<Scanout<<endl;
	  es=10;
	}
	
	if (es==0) es=program();
	cout<<"=====语法分析结果!======\n";
	switch(es)
	{
		case 0: cout<<"语法分析成功!\n";break;	
		case 1: cout<<"缺少{!\n";break;
		case 2: cout<<"缺少}!\n";break;
		case 3: cout<<"缺少标识符!\n";break;
		case 4: cout<<"少分号!\n";break;
		case 5: cout<<"缺少(!\n";break;
		case 6: cout<<"缺少)!\n";break;
		case 7: cout<<"缺少操作数!\n";break;
		case 8:cout<<"变量重复定义!\n";break;
		case 9:cout<<"变量未声明!\n";break;
		case 10: cout<<"打开文件 %s失败!\n",Scanout;break;
	}
	fp.close();
	return(es);
}
//<程序>::={<声明序列><语句序列>}
//program::={<declaration_list><statement_list>}
int program()
{ 
   int es=0;
  
	fp>>token>>token1;
   
	cout<<token<<"\t"<<token1<<endl;
   if(strcmp(token,"{"))//判断是否'{'
   {
	   es=1;
	   return(es);
   }
   fp>>token>>token1;
   
   cout<<token<<"\t"<<token1<<endl;
   es=declaration_list();
   if (es>0) return(es);
   es=statement_list();
   if (es>0) return(es);
   if(strcmp(token,"}"))//判断是否'}'
   {
	   es=2;
	   return(es);
   }
   return(es);
}
//<声明序列>::=<声明序列><声明语句>|<声明语句>
//<declaration_list>::=
//<declaration_list><declaration_stat>|<declaration_stat>
//该成<declaration_list>::={<declaration_stat>}
int declaration_list()
{
	int es=0;
	while (strcmp(token,"int")==0)
	{
		es=declaration_stat();
		if (es>0) return(es);
	}
	return(es);
}
//<声明语句> ::=int <变量>；
//<declaration_stat>::=int ID;
int declaration_stat()
{
	int es=0;      
    fp>>token>>token1;   
	cout<<token<<"\t"<<token1<<endl;
	
	if (strcmp(token,"ID"))	return(es=3);  //不是标识符
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	if (strcmp(token,";") )	return(es=4);		
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	return(es);
}
//<语句序列>::=<语句序列><语句>|<语句>
//<statement_list>::=<statement_list><statement>|<statement>
//改成<statement_list>::={<statement>}
int statement_list()
{
	int es=0;
	while (strcmp(token,"}"))
	{
		es=statement();
		if (es>0) return(es);
	}
	return(es);
}
//<语句>::=<if语句>|<while语句>|<for语句>|<read语句>
//         |<write语句>|<复合语句>|<表达式语句>
//<statement>::= <if_stat>|<while_stat>|<for_stat>
//               |<compound_stat> |<expression_stat>

int statement()
{
	int es=0;
	if (es==0 && strcmp(token,"if")==0) es=if_stat();//<IF语句>
	if (es==0 && strcmp(token,"while")==0) es=while_stat();//<while语句>
	if (es==0 && strcmp(token,"for")==0) es=for_stat();//<for语句>
	if (es==0 && strcmp(token,"do")==0) es=do_stat();//<do-while语句> 
	if (es==0 && strcmp(token,"read")==0) es=read_stat();//<read语句>
	if (es==0 && strcmp(token,"write")==0) es=write_stat();//<write语句>
	if (es==0 && strcmp(token,"{")==0) es=compound_stat();//<复合语句>
	if (es==0 && (strcmp(token,"ID")==0||strcmp(token,"NUM")==0||strcmp(token,"(")==0)) es=expression_stat();//<表达式语句>
	return(es);
}
//<IF 语句>::= if (<表达式>) <语句 > [else <语句 >]
//<IF_stat>::= if (<expr>) <statement > [else < statement >]

int if_stat(){
	int es=0;  //if
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	if (strcmp(token,"(")) 	return(es=5);  //少左括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //少右括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement(); 
	if (es>0) return(es);
	if (strcmp(token,"else")==0)//else部分处理
	{  
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=statement(); 
	    if (es>0) return(es);
	}
	return(es);
}

int do_stat()
{
	int label1,label2;
	int es=0;  //do
	label1=labelp++;//用label11记住要转向的标号
	fobj<<"        BRF LABEL"<<label1<<endl;//输出无条件转移指令
	fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement(); 
	if (es>0) return(es);
	fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"while")==0)//while部分处理
	{  
		fp>>token>>token1;
    	cout<<token<<"\t"<<token1<<endl;
	    if (strcmp(token,"(")) 
		   return(es=5);  //少左括号
        fp>>token>>token1;
    	cout<<token<<"\t"<<token1;
	    es=expression();
        if (es>0) 
		   return(es);
   	    if (strcmp(token,")"))  
		  return(es=6); //少右括号
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=statement(); 
	    if (es>0) 
			return(es);
	}
	else
    	return(es=8);
	label2=labelp++;//用label12记住要转向的标号
    fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
	return(es);
}

//<while语句>::=while(<表达式>) <语句>
//<while_stat>::= while (<expr >) < statement >
int while_stat()
{
	int es=0;  
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"("))  return(es=5);  //少左括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //少右括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement();
	return(es);
}

//<for语句>::=for(<表达式>;<表达式>;<表达式>) <语句 >
//<for_stat>::= for(<expr>,<expr>,<expr>)<statement>
int for_stat()
{
	int es=0;  
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"("))  return(es=5);  //少左括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";")) 	return(es=4);  //少分号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";"))  return(es=4);  //少分号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //少右括号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement();
	return(es);
	
}
//<write_语句>::=write <表达式>;
//<write_stat>::=write <expression>;
int write_stat()
{
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";"))  return(es=4);  //少分号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	return(es);
}
//<read_语句>::=read <变量>;
//<read_stat>::=read ID;
int read_stat()
{
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"ID"))  return(es=3);  //少标识符
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,";"))  return(es=4);  //少分号
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	return(es);
}
//<复合语句>::={<语句序列>} 
//<compound_stat>::={<statement_list>} 
int compound_stat(){   //复合语句函数
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement_list();
	return(es);
}



//<表达式语句>::=<<表达式>;|;
//<expression_stat>::=<expression>;|;
int expression_stat()
{
	int es=0;
	if (strcmp(token,";")==0) 
	{
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		return(es);
	}
	es=expression();
	if (es>0) return(es);
	if (es==0 && strcmp(token,";")==0) 
	{
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		return(es);
	} else
	{
		es=4;
		return(es);//少分号
	}
}
//<表达式>::=<标识符>=<布尔表达式>|<布尔表达式>
//<expr>::=ID=<bool_expr>|<bool_expr>

int expression()
{
	int es=0,readPos;
	char token2[20],token3[100];
	cout<<"expression  "<<token<<endl;
	if (strcmp(token,"ID")==0)
	{   
		readPos=fp.tellg();  //记录文件位置
		cout<<"readPos"<<readPos<<'\n';
		fp>>token2>>token3;
		//fp.get(token2,100,' ');fp.get(token3,100,'\n');fp.get(ch);
		cout<<token2<<"\t"<<token3<<endl;
		
		if (es>0) return(es);
		if (strcmp(token2,"=")==0)  //'='
		{
			fp>>token>>token1;
			cout<<token<<"\t"<<token1<<endl;
			es=bool_expr();
		} else 
		{
			fp.seekg(readPos);//若非'='则文件指针回到'='前的标识符
			cout<<token<<"\t"<<token1<<endl;
			es=bool_expr();
			if (es>0) return(es);
		}
	}else es=bool_expr();
	
	return(es);
}

//<布尔表达式>::=<算术表达式>|<算术表达式>(>|<|>=|<=|==|!=)<算术表达式>
//<bool_expr>::=<additive_expr>
//           |< additive_expr >(>|<|>=|<=|==|!=)< additive_expr >

int bool_expr()
{
	int es=0;
	es=additive_expr();
	if(es>0) return(es);
	if (strcmp(token,">")==0 || strcmp(token,">=")==0
	   ||strcmp(token,"<")==0||strcmp(token,"<=")==0
	   ||strcmp(token,"==")==0||strcmp(token,"!=")==0)
	{
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=additive_expr();
		if(es>0) return(es);
	}
	return(es);
}
//<算术表达式>::=<项>{(+|-)<项>}
//<additive_expr>::=<term>{(+|-)< term >} 
int additive_expr()
{
	int es=0;
	es=term();
	if(es>0) return(es);
	while (strcmp(token,"+")==0 || strcmp(token,"-")==0)
	{
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=term();
		if(es>0) return(es);
	}
	return(es);
}
//<项>::=<因子>{(*|/)<因子>}
//< term >::=<factor>{(*| /)< factor >} 
int term()
{
	int es=0;
	es=factor();
	if(es>0) return(es);
	while (strcmp(token,"*")==0 || strcmp(token,"/")==0)
	{
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=factor();
		if(es>0) return(es);
	}
	return(es);
}
//<因子>::=(<算术表达式>)|<标识符>|<无符号整数>
//< factor >::=(<additive_expr>)| ID|NUM

int factor()
{
	int es=0;
	
	if (strcmp(token,"(")==0)  
	{
		fp>>token>>token1;			
		cout<<token<<"\t"<<token1<<endl;
		es=expression();
		if (es>0) return(es);
		if (strcmp(token,")"))  return(es=6); //少右括号
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
	} else
	{
		
		if (strcmp(token,"ID")==0||strcmp(token,"NUM")==0)
		{
			fp>>token>>token1;
			cout<<token<<"\t"<<token1<<endl;
			return(es);
		} else
		{
			es=7;//缺少操作数
			return(es);
		}
	}
	return(es);
}