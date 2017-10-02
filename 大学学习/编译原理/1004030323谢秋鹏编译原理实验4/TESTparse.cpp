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

char token[20],token1[100];//token���浥�ʷ��ţ�token1���浥��ֵ
extern char Scanout[300]; //����ʷ���������ļ���
ifstream fp;
char ch;

//�﷨��������
int TESTparse()
{
	int es=0;
	fp.open(Scanout);
	if(!fp.is_open())
	{  
      cout<<"\n��%s����!\n"<<Scanout<<endl;
	  es=10;
	}
	
	if (es==0) es=program();
	cout<<"=====�﷨�������!======\n";
	switch(es)
	{
		case 0: cout<<"�﷨�����ɹ�!\n";break;	
		case 1: cout<<"ȱ��{!\n";break;
		case 2: cout<<"ȱ��}!\n";break;
		case 3: cout<<"ȱ�ٱ�ʶ��!\n";break;
		case 4: cout<<"�ٷֺ�!\n";break;
		case 5: cout<<"ȱ��(!\n";break;
		case 6: cout<<"ȱ��)!\n";break;
		case 7: cout<<"ȱ�ٲ�����!\n";break;
		case 8:cout<<"�����ظ�����!\n";break;
		case 9:cout<<"����δ����!\n";break;
		case 10: cout<<"���ļ� %sʧ��!\n",Scanout;break;
	}
	fp.close();
	return(es);
}
//<����>::={<��������><�������>}
//program::={<declaration_list><statement_list>}
int program()
{ 
   int es=0;
  
	fp>>token>>token1;
   
	cout<<token<<"\t"<<token1<<endl;
   if(strcmp(token,"{"))//�ж��Ƿ�'{'
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
   if(strcmp(token,"}"))//�ж��Ƿ�'}'
   {
	   es=2;
	   return(es);
   }
   return(es);
}
//<��������>::=<��������><�������>|<�������>
//<declaration_list>::=
//<declaration_list><declaration_stat>|<declaration_stat>
//�ó�<declaration_list>::={<declaration_stat>}
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
//<�������> ::=int <����>��
//<declaration_stat>::=int ID;
int declaration_stat()
{
	int es=0;      
    fp>>token>>token1;   
	cout<<token<<"\t"<<token1<<endl;
	
	if (strcmp(token,"ID"))	return(es=3);  //���Ǳ�ʶ��
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	if (strcmp(token,";") )	return(es=4);		
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	return(es);
}
//<�������>::=<�������><���>|<���>
//<statement_list>::=<statement_list><statement>|<statement>
//�ĳ�<statement_list>::={<statement>}
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
//<���>::=<if���>|<while���>|<for���>|<read���>
//         |<write���>|<�������>|<���ʽ���>
//<statement>::= <if_stat>|<while_stat>|<for_stat>
//               |<compound_stat> |<expression_stat>

int statement()
{
	int es=0;
	if (es==0 && strcmp(token,"if")==0) es=if_stat();//<IF���>
	if (es==0 && strcmp(token,"while")==0) es=while_stat();//<while���>
	if (es==0 && strcmp(token,"for")==0) es=for_stat();//<for���>
	if (es==0 && strcmp(token,"do")==0) es=do_stat();//<do-while���> 
	if (es==0 && strcmp(token,"read")==0) es=read_stat();//<read���>
	if (es==0 && strcmp(token,"write")==0) es=write_stat();//<write���>
	if (es==0 && strcmp(token,"{")==0) es=compound_stat();//<�������>
	if (es==0 && (strcmp(token,"ID")==0||strcmp(token,"NUM")==0||strcmp(token,"(")==0)) es=expression_stat();//<���ʽ���>
	return(es);
}
//<IF ���>::= if (<���ʽ>) <��� > [else <��� >]
//<IF_stat>::= if (<expr>) <statement > [else < statement >]

int if_stat(){
	int es=0;  //if
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;;
	if (strcmp(token,"(")) 	return(es=5);  //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement(); 
	if (es>0) return(es);
	if (strcmp(token,"else")==0)//else���ִ���
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
	label1=labelp++;//��label11��סҪת��ı��
	fobj<<"        BRF LABEL"<<label1<<endl;//���������ת��ָ��
	fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement(); 
	if (es>0) return(es);
	fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"while")==0)//while���ִ���
	{  
		fp>>token>>token1;
    	cout<<token<<"\t"<<token1<<endl;
	    if (strcmp(token,"(")) 
		   return(es=5);  //��������
        fp>>token>>token1;
    	cout<<token<<"\t"<<token1;
	    es=expression();
        if (es>0) 
		   return(es);
   	    if (strcmp(token,")"))  
		  return(es=6); //��������
		fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
		es=statement(); 
	    if (es>0) 
			return(es);
	}
	else
    	return(es=8);
	label2=labelp++;//��label12��סҪת��ı��
    fp>>token>>token1;
		cout<<token<<"\t"<<token1<<endl;
	return(es);
}

//<while���>::=while(<���ʽ>) <���>
//<while_stat>::= while (<expr >) < statement >
int while_stat()
{
	int es=0;  
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"("))  return(es=5);  //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement();
	return(es);
}

//<for���>::=for(<���ʽ>;<���ʽ>;<���ʽ>) <��� >
//<for_stat>::= for(<expr>,<expr>,<expr>)<statement>
int for_stat()
{
	int es=0;  
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"("))  return(es=5);  //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";")) 	return(es=4);  //�ٷֺ�
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";"))  return(es=4);  //�ٷֺ�
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,")"))  return(es=6); //��������
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement();
	return(es);
	
}
//<write_���>::=write <���ʽ>;
//<write_stat>::=write <expression>;
int write_stat()
{
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=expression();
	if (es>0) return(es);
	if (strcmp(token,";"))  return(es=4);  //�ٷֺ�
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	return(es);
}
//<read_���>::=read <����>;
//<read_stat>::=read ID;
int read_stat()
{
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,"ID"))  return(es=3);  //�ٱ�ʶ��
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	if (strcmp(token,";"))  return(es=4);  //�ٷֺ�
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	return(es);
}
//<�������>::={<�������>} 
//<compound_stat>::={<statement_list>} 
int compound_stat(){   //������亯��
	int es=0;
    fp>>token>>token1;
	cout<<token<<"\t"<<token1<<endl;
	es=statement_list();
	return(es);
}



//<���ʽ���>::=<<���ʽ>;|;
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
		return(es);//�ٷֺ�
	}
}
//<���ʽ>::=<��ʶ��>=<�������ʽ>|<�������ʽ>
//<expr>::=ID=<bool_expr>|<bool_expr>

int expression()
{
	int es=0,readPos;
	char token2[20],token3[100];
	cout<<"expression  "<<token<<endl;
	if (strcmp(token,"ID")==0)
	{   
		readPos=fp.tellg();  //��¼�ļ�λ��
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
			fp.seekg(readPos);//����'='���ļ�ָ��ص�'='ǰ�ı�ʶ��
			cout<<token<<"\t"<<token1<<endl;
			es=bool_expr();
			if (es>0) return(es);
		}
	}else es=bool_expr();
	
	return(es);
}

//<�������ʽ>::=<�������ʽ>|<�������ʽ>(>|<|>=|<=|==|!=)<�������ʽ>
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
//<�������ʽ>::=<��>{(+|-)<��>}
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
//<��>::=<����>{(*|/)<����>}
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
//<����>::=(<�������ʽ>)|<��ʶ��>|<�޷�������>
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
		if (strcmp(token,")"))  return(es=6); //��������
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
			es=7;//ȱ�ٲ�����
			return(es);
		}
	}
	return(es);
}