
                               /*���ݹ���ϵͳ*/


#include <iostream.h>                  
#include <string.h>
#include <iomanip.h>
#include "function.h"                             /*ʹ���ļ�����ָ��������ļ�function.h,���ļ����ڴ�Ÿó������������飬������ָ�룬�Զ��庯����*/



int main()
{        
    operation func;
	func.welcome();                                    //��������û���ӭ����
    
	char if_run;
	do{
	     cout<<endl;
		 cout<<"�밴ѡ���(1-7):  ";              //��ʾ�û�ѡ�����  
	     cin>>choice;
		 cout<<endl;
	     switch(choice)
		 {
	             case 1:    func.cut_in();break;
	             case 2:    cout<<"ƽ��ֵΪ"<<func.average(); break;
	             case 3:    {
                                    func.max();
									cout<<'\t';
									q=a;
				                    func.min();
                             } break;
	             case 4:    func.exit(); break;
		         case 5:    {
	                            cout<<"��������Ϊ��"<<endl;
					            for(i=0;i<len;i++)
	                               cout<<a[i]<<'\t';
							} break;
	             case 6:    func.count_choice(); break;
                 case 7:    return 0;
                 default: cout<<"������ѡ��"<<endl;                       //���û�ѡ�񳬽������ʾ
		 }
         cout<<endl;
         cout<<"Do you want to continue?('Y' or 'N' )\n";                    //��ʾ�û�ѡ���Ƿ�������г���
		 cin>>if_run;
	   }
	 while(if_run=='Y'||if_run=='y');                                        /*�û�ѡ����жϣ�������Y��y��������У�����������������*/
     return 0;
}
