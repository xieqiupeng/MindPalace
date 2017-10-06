
                               /*数据管理系统*/


#include <iostream.h>                  
#include <string.h>
#include <iomanip.h>
#include "function.h"                             /*使用文件包含指令包含进文件function.h,该文件用于存放该程序中所有数组，变量，指针，自定义函数。*/



int main()
{        
    operation func;
	func.welcome();                                    //首先输出用户欢迎界面
    
	char if_run;
	do{
	     cout<<endl;
		 cout<<"请按选择键(1-7):  ";              //提示用户选择操作  
	     cin>>choice;
		 cout<<endl;
	     switch(choice)
		 {
	             case 1:    func.cut_in();break;
	             case 2:    cout<<"平均值为"<<func.average(); break;
	             case 3:    {
                                    func.max();
									cout<<'\t';
									q=a;
				                    func.min();
                             } break;
	             case 4:    func.exit(); break;
		         case 5:    {
	                            cout<<"所有数据为："<<endl;
					            for(i=0;i<len;i++)
	                               cout<<a[i]<<'\t';
							} break;
	             case 6:    func.count_choice(); break;
                 case 7:    return 0;
                 default: cout<<"请重新选择！"<<endl;                       //对用户选择超界进行提示
		 }
         cout<<endl;
         cout<<"Do you want to continue?('Y' or 'N' )\n";                    //提示用户选择是否继续运行程序
		 cin>>if_run;
	   }
	 while(if_run=='Y'||if_run=='y');                                        /*用户选择的判断，若输入Y或y则继续运行，否则正常结束程序*/
     return 0;
}
