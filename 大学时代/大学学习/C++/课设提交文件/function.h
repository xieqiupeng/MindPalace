#include <iostream.h>
#include <string.h>
#include <iomanip.h>


float a[15]={3,1,5,2.2,4.2,100,6.6,100,8.1,10,9,15,28,100,1};     //��Ҫ���в���������a����ֵ
int len=sizeof(a)/sizeof(3.5f);                   //��������a�ĳ���
float b[sizeof(a)/sizeof(3.5f)+1];                /*��������b�����ڽ���"��ָ��λ�ò�������"�Ĳ���*/
int &k=len;          //k��һ�����ñ���
int i=0,j;           //����ȫ�ֱ��� 
int choice;
float m;
float *q=a;          //ָ���ʹ�á���ָ��qָ������a��ʵ�ֶ�����Ԫ�صĲ���



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


	


void operation::welcome()               //�ú�����������û���ӭ���� 
{
	cout<<"                        -------------------------------------\n";
	cout<<"                        *                                   *\n";
	cout<<"                               ��ӭ�������ݹ���ϵͳ          \n";
	cout<<"                        *                                   *\n";
	cout<<"                        -------------------------------------\n";
	cout<<endl;
    cout<<"��ѡ�����Ĳ���:\n";
	cout<<"               1.��ָ��λ�ò���1������\n";
	cout<<"               2.����ƽ����\n";
	cout<<"               3.�������������С������λ��\n";
	cout<<"               4.����������������Ƿ����\n";
	cout<<"               5.��ʾ��������\n";
	cout<<"               6.�����ݴ洢˳���1��ʼ�������������������˳��������ʣ�������±�";
	cout<<"               7.�˳�\n";
}
	

void operation::cut_in()                             // ѡ�����1:  ���ڸ����û�����������ݲ��������Ļ��
{       
        int n;
		bool back;     //����ִ���û�ѡ�񳬽�ʱ�ķ������²���
	    float cut;
        while(back)
        {
    	   cout<<"���������ݲ���λ��n(���뵽��n�͵�n+1�������м�)��Ҫ�������\n";
           cin>>n;
           if(n>0&&n<len)
		   {   
               cin>>cut;
               for(;i<n;i++)
	              b[i]=a[i];
	           b[i]=cut;
	           for(int j=n;j<k;j++)       //ʹ�����ñ���   
	              b[j+1]=a[j];
               cout<<"�Ķ�������Ϊ:";
	           for(int p=0;p<=len;p++)
      	          cout<<b[p]<<setw(5);
			    back=false;
		   }
           else 
		   {
               cout<<"�Բ���ѡ�񳬽磬������ѡ��"<<endl<<endl;                //���û�ѡ�񳬽������ʾ��������ѡ��
               back=true;
		   } 
        }
}


float operation::                                                                                               /*ѡ�����2:  �ݹ麯����ʹ�á�ͨ��ʹ�õݹ麯����������a����Ԫ�صĺ͡�*/
{
	if(x==0) return a[0];
	x--;
	return sum_(x)+a[x+1];
}




float operation::average()                               /*ѡ�����3:  ����Ƕ�׵�ʹ�á��ڸú�����Ƕ�׵�����sum_(int x)���������ڼ�������a������Ԫ�ص�ƽ��ֵ*/           
{
	return sum_(len)/len;
}




void operation::max()                                         // ѡ�����4:  �����ҳ�����a����������λ��                             
{                                                          //��֧����ʾ������ͬ�������λ��
	   int count_m=0;
	   int count_max=0;
	   cout<<"�������ǵ�";
       for(m=*q++;q<a+len;q++)         //ʹ��"ָ���±귨"ָ������a��Ԫ��        
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
       cout<<"����";
}



void operation::min()                                     // ѡ�����4:  �����ҳ�����a����С������λ��                          
{                                                          //��֧����ʾ������ͬ����С��λ��
       int count_m=0;
	   int count_min=0;
	   m=q[0];
       cout<<"��С�����ǵ�";
       for(int c=1;c<len;c++)
	      if(m>q[c])  m=*(q+c);                       //ʹ��"ָ���±귨"��ʾ����a��Ԫ��
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
       cout<<"����";    
}


void operation::exit()                           // ѡ�����5:  ���ݼ�����������������Ƿ����                            
{                                     
     int count_exit=0;                //֧�ֲ���������ͬ�����ݵ�λ��
	 int count_exit_2=0;
	 float d;
	 cout<<"������Ҫ���ҵ���:";
     cin>>d;
     for(i=0;i<len+1;i++)
        if(d==a[i]) break;
     if(i==len+1) cout<<"û�в��ҵ���";
	 else
	 {
        cout<<"���ڵ�λ��Ϊ��";
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
        cout<<"����"<<endl;
     }
}



  
 //�ú�������Ĭ�ϲ��� e                                               
void operation::count_choice(int e=0)             /* ѡ�����6:  �����û���ѡ����б������������ʣ�µ��������ǵ��±�*/
{
      int d;
      bool back;                       //����ִ���û�ѡ�񳬽�ʱ�ķ������²���
	  while(back)
      {
		  cout<<"��ѡ������ֹͣ(2~9֮���һ����Ȼ��)\n";
          cin>>d;
          if(d>=2&&d<10)
		  {
             for(;i<d;i++)
                cout<<i+1<<setw(2);
             cout<<endl;
             cout<<"����������ʣ�µ���Ϊ:"<<endl;
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
              cout<<"�Բ���ѡ�񳬽磬������ѡ��"<<endl;                   //���û�ѡ�񳬽������ʾ��������ѡ��
              back=true;  
		  }   
	  }
}