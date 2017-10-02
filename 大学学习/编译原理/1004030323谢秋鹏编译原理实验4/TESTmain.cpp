//主程序
#include <locale>
#include <iostream>
#include <fstream>
using namespace std;
extern int TESTscan();
extern int TESTparse();
char Scanin[300],Scanout[300]; //用于接收输入输出文件名

void main(){
	int es=0;
	if (es==0) es=TESTscan();//调词法分析
    if (es>0) cout<<"词法分析有错,编译停止!";
	else cout<<"词法分析成功!\n";
	if (es==0) 
	{		
  		es=TESTparse();	//调语法分析
		if (es==0) 	cout<<"语法分析成功!\n";
		else	cout<<"语法分析错误!\n";
	}
}
