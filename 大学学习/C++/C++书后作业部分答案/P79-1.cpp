// P79-1.cpp 判断某年某月某日是当年的第几天

#include <iostream.h>
void main(void)
{	int year=2000, month=12, day=24, sum=0;
	int date[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	/*
	cout<<"please input the year number:"<<endl ;
	cin>>year;
	cout<<"please input the month number:"<<endl ;
	cin>>month;
	cout<<"please input the day number:"<<endl ;
	cin>>day;
	*/
	//* 方法一
	switch (month)
	{	case 1:	sum=0; break;
		case 2:	sum=sum+31; break;
		case 3:	sum=sum+59; break;
		case 4:	sum=sum+90; break;
		case 5:	sum=sum+120; break;
		case 6:	sum=sum+151; break;
		case 7:	sum=181; break;
		case 8:	sum=212; break;
		case 9:	sum=243; break;
		case 10:	sum=273; break;
		case 11:	sum=304; break;
		case 12:	sum=334;
		//default: day=-1;
	}
	sum=sum+day;
	if(year%4==0){ sum=sum+1;}
		cout<<year<<"年"<<month<<"月"<<day<<"日是这年的第"<<sum<<"天! \n";
	//*/
	//方法二
	switch (month)
	{	case 1:	sum=date[month-1]+day; break;
		case 2:	sum=date[month-1]+day; break;
		case 3:	sum=date[month-1]+day; break;
		case 4:	sum=date[month-1]+day; break;
		case 5:	sum=date[month-1]+day; break;
		case 6:	sum=date[month-1]+day; break;
		case 7:	sum=date[month-1]+day; break;
		case 8:	sum=date[month-1]+day; break;
		case 9:	sum=date[month-1]+day; break;
		case 10:	sum=date[month-1]+day; break;
		case 11:	sum=date[month-1]+day; break;
		case 12:	sum=date[month-1]+day; break;
		//default: day=-1;
	}
	if(year%4==0){ sum=sum+1;}
	//year%400!=0
	cout<<year<<"年"<<month<<"月"<<day<<"日是这年的第"<<sum<<"天! \n";
}
