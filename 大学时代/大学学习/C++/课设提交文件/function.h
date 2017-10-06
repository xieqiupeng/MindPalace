#include <iostream.h>
#include <string.h>
#include <iomanip.h>


float a[15]={3,1,5,2.2,4.2,100,6.6,100,8.1,10,9,15,28,100,1};     //对要进行操作的数组a赋初值
int len=sizeof(a)/sizeof(3.5f);                   //计算数组a的长度
float b[sizeof(a)/sizeof(3.5f)+1];                /*定义数组b，用于进行"在指定位置插入数据"的操作*/
int &k=len;          //k是一个引用变量
int i=0,j;           //定义全局变量 
int choice;
float m;
float *q=a;          //指针的使用。用指针q指向数组a，实现对数组元素的操作



class operation{
public:
 	void welcome();
	void cut_in();
	float sum_(int);
	float average();
	void max();
	void min();
	void exit();
	void count_choice(int);
};


	


void operation::welcome()               //该函数用于输出用户欢迎界面 
{
	cout<<"                        -------------------------------------\n";
	cout<<"                        *                                   *\n";
	cout<<"                               欢迎进入数据管理系统          \n";
	cout<<"                        *                                   *\n";
	cout<<"                        -------------------------------------\n";
	cout<<endl;
    cout<<"请选择您的操作:\n";
	cout<<"               1.在指定位置插入1个数据\n";
	cout<<"               2.计算平均数\n";
	cout<<"               3.查找最大数和最小数所在位置\n";
	cout<<"               4.根据输入的数查找是否存在\n";
	cout<<"               5.显示所有数据\n";
	cout<<"               6.按数据存储顺序从1开始报数，报到给定数的退出，求最后剩下数及下标";
	cout<<"               7.退出\n";
}
	

void operation::cut_in()                             // 选择操作1:  用于根据用户需求插入数据并输出在屏幕上
{       
        int n;
		bool back;     //用于执行用户选择超界时的返回重新操作
	    float cut;
        while(back)
        {
    	   cout<<"请输入数据插入位置n(插入到第n和第n+1个数据中间)和要插入的数\n";
           cin>>n;
           if(n>0&&n<len)
		   {   
               cin>>cut;
               for(;i<n;i++)
	              b[i]=a[i];
	           b[i]=cut;
	           for(int j=n;j<k;j++)       //使用引用变量   
	              b[j+1]=a[j];
               cout<<"改动后数据为:";
	           for(int p=0;p<=len;p++)
      	          cout<<b[p]<<setw(5);
			    back=false;
		   }
           else 
		   {
               cout<<"对不起，选择超界，请重新选择。"<<endl<<endl;                //对用户选择超界进行提示，并重新选择
               back=true;
		   } 
        }
}


float operation::                                                                                               /*选择操作2:  递归函数的使用。通过使用递归函数计算数组a所有元素的和。*/
{
	if(x==0) return a[0];
	x--;
	return sum_(x)+a[x+1];
}




float operation::average()                               /*选择操作3:  函数嵌套的使用。在该函数中嵌套调用了sum_(int x)函数，用于计算数组a中所有元素的平均值*/           
{
	return sum_(len)/len;
}




void operation::max()                                         // 选择操作4:  用于找出数组a中最大的数的位置                             
{                                                          //并支持显示几个相同的最大数位置
	   int count_m=0;
	   int count_max=0;
	   cout<<"最大的数是第";
       for(m=*q++;q<a+len;q++)         //使用"指针下标法"指向数组a的元素        
	      if(m<*q)  m=*q;
	   q=a;
	   for(;q<a+len;q++)
		  if(*q==m) count_m++;
       q=a;
	   for(;q<a+len;q++)
		  if(*q==m)	  
		  {
              if(count_max<count_m-1)
			  {
				  cout<<q-a+1<<',';
				  count_max++;
              }
			  else cout<<q-a+1;
		  }	                                                                                                               
       cout<<"个。";
}



void operation::min()                                     // 选择操作4:  用于找出数组a中最小的数的位置                          
{                                                          //并支持显示几个相同的最小数位置
       int count_m=0;
	   int count_min=0;
	   m=q[0];
       cout<<"最小的数是第";
       for(int c=1;c<len;c++)
	      if(m>q[c])  m=*(q+c);                       //使用"指针下标法"表示数组a的元素
       q=a;
       for(c=1;c<len;c++)
          if(m==*(q+c)) count_m++;
	   q=a;	  
	   for(c=1;c<len;c++)
          if(m==*(q+c))		 
		  {
			    if(count_min<count_m-1)
				{
					cout<<c+1<<',';
					count_min++;
                }
			    else cout<<c+1;
		  }    
       cout<<"个。";    
}


void operation::exit()                           // 选择操作5:  根据键盘输入的数，查找是否存在                            
{                                     
     int count_exit=0;                //支持查找数个相同的数据的位置
	 int count_exit_2=0;
	 float d;
	 cout<<"请输入要查找的数:";
     cin>>d;
     for(i=0;i<len+1;i++)
        if(d==a[i]) break;
     if(i==len+1) cout<<"没有查找到。";
	 else
	 {
        cout<<"所在的位置为第";
        for(i=0;i<len+1;i++)
           if(d==a[i])  count_exit++;
        for(i=0;i<len+1;i++)
           if(d==a[i])
		   {
			    if(count_exit_2<count_exit-1)
				{
					cout<<i+1<<',';
					count_exit_2++;
                }
			    else cout<<i+1;
		   }    	   
        cout<<"个。"<<endl;
     }
}



  
 //该函数带有默认参数 e                                               
void operation::count_choice(int e=0)             /* 选择操作6:  根据用户的选择进行报数操作并输出剩下的数和它们的下标*/
{
      int d;
      bool back;                       //用于执行用户选择超界时的返回重新操作
	  while(back)
      {
		  cout<<"请选择在哪停止(2~9之间的一个自然数)\n";
          cin>>d;
          if(d>=2&&d<10)
		  {
             for(;i<d;i++)
                cout<<i+1<<setw(2);
             cout<<endl;
             cout<<"报数结束，剩下的数为:"<<endl;
             for(i=d;i<len;i++,e++)
			 {
                 cout<<"a["<<i<<"]="<<a[i]<<setw(10);
                 if(e%3==0)
                 cout<<endl;
             }
			 back=false;
		  }	
		  
          else 
		  {
              cout<<"对不起，选择超界，请重新选择。"<<endl;                   //对用户选择超界进行提示，并重新选择
              back=true;  
		  }   
	  }
}