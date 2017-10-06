/*
 *  funtion.h
 *  101_data_manage
 *
 *  Created by л���� on 11-4-9.
 *  Copyright 2010 . All rights reserved.
 *
 */

#include <iostream.h>
using namespace std;

static int count_of_data=0;
static float sum=0;//数据总合

enum situation{stay,calltoout};//未被叫　与　被叫　两种状态

class Data
{
public:
	float content;//数据内容
	Data *next;
	situation call;//被叫状态
	void print();
	Data();//无参数构造函数，指向自身
	Data(class Data *next_point);//指向next_point
	Data(class Data *next_point,float i);//指向next_point且数据内容为i
};

bool check(int up,int down,int input);//检查input是否在up与down之间

Data *data_point(struct Data *head,int i);//返回特定位置类的指针

void Data::print()
{
	cout << content << endl;
}

Data::Data()
{
	count_of_data++;
	next = this;
}

Data::Data(Data *next_point)
{
	count_of_data++;
	next = next_point;
	cout << "输入数据" <<endl;
	cin >> content;
	sum+=content;
}

Data::Data(Data *next_point,float i)
{
	count_of_data++;
	next=next_point;
	content=i;
	sum+=content;
}

bool check(int up,int down,int input)
{
	return (input>=up && input<=down)?true:false;
}


Data *data_point(Data *head,int i)
{
	Data *temp=head;	
	if (i==0) {
		i=count_of_data;
	}
	while (--i!=0) {
		temp=temp->next;
	}
	return temp;
}