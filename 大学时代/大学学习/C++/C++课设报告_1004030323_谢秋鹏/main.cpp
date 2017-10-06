#include <iostream>
#include "funtion.h"
using namespace std;

int main (void)//本程序用环状链表完成
{
	int get,i;
	//初始化，9个数据
	Data *head=new Data;
	for (i=1; i<10; i++) {
		data_point(head, i)->next = new Data(head,i);
	}
	do {	
		cout << endl;
		cout << "			----------------------------------------" << endl;	
		cout << "			*                                      *" << endl;	
		cout << "						欢迎进入数据管理系统           " << endl;	
		cout << "			*                                      *" << endl;	
		cout << "			----------------------------------------" << endl;
		cout << "请选择您的操作" <<  endl;
		cout << "			1. 在指定位置插入1个数据" << endl;
		cout << "			2. 计算平均数" << endl;
		cout << "			3. 查找最大数和最小数所在位置" << endl;
		cout << "			4. 根据输入的数查找是否存在" << endl;
		cout << "			5. 显示所有数据" << endl;
		cout << "			6. 按数据存储顺序从1开始报数，报到给定数" << endl;
		cout << "			   的退出，求最后剩下的数及下标" << endl;
		cout << "			7.退出" << endl;
		cout << "请选择按键(1-7)" << endl;
		
		if (cin>>get,!check(1, 7, get)) {
			cout  << "输入错误！";
		}
		else
		{
			switch (get) {
				case 1:
				{
					cout << "插入位置(1-" << count_of_data+1 << ")" << endl;
					int insert_position;
					
					if (cin>>insert_position,check(1, count_of_data+1,insert_position)) {
						data_point(head,insert_position-1)->next=new Data(data_point(head,insert_position));
						if (insert_position == 1) {//在位置1插入数据时，头指针指向插入的新类
							head = data_point(head, count_of_data);
						}
					}
					else {
						cout << "输入错误"  << endl;
					}
					break;
				}
				case 2:
				{
					cout<<"平均数为: "<<sum/count_of_data<< endl;
				}
					break;
				case 3:
				{
					float max=head->content,min=head->content;
					
					for (i=2;i<=count_of_data;++i) {
						max=(data_point(head,i)->content>max)?data_point(head,i)->content:max;
						min=(data_point(head,i)->content<min)?data_point(head,i)->content:min;
					}
					for (i=1; i<=count_of_data; ++i) {
						if (data_point(head,i)->content==max) {
							cout<<"最大数在位置: "<<i<<endl;
						}
						if (data_point(head,i)->content==min) {
							cout<<"最小数在位置: "<<i<<endl;
						}
					}
				}
					break;
				case 4:
				{
					float find;
					int number_find=0;
					cout << "输入要查找的数字:" << endl;
					cin >> find;
					for (i=1;i<=count_of_data;i++){
						if(data_point(head, i)->content==find){
							cout<<"位置为: "<<i<<endl;
							++number_find;
						}
					}
					if (!number_find) {
						cout<<"没有查找到!"<<endl;
					}
				}
					
					break;
				case 5:
				{
					for (i=1; i <= count_of_data; ++i) {
						cout<<"位置"<<i<<": ";
						data_point(head, i)->print();
					}
					break;
				}
				case 6:
				{
					int rest=count_of_data;
					int num,flag=0;
					
					cout << "输入报号数字(2-9): "  << endl;
					if (cin>>num,!check(2,9,num)) {
						cout << "输入错误！"<<endl;
						break;
					}
					for(i=1; i<=count_of_data; ++i)
					{
						data_point(head, i)->call=stay;
					}
					i=1;
					while(rest!=1)
					{
						if(data_point(head,i)->call==stay)
						{
							flag++;
							if(flag == num)
							{
								data_point(head,i)->call=calltoout;
								rest--;	
								flag=0;
							}
						}
						i=(i==count_of_data)?1:i+1;
					}
					i=1;
					while(data_point(head,i++)->call==calltoout);
					cout<<"剩余数据为";
					data_point(head,i-1)->print();
					cout<<"下标为"<<i-1<<endl;
				}
					break;
				case 7:
					return 0;
			}
		}
	} while(true);
}