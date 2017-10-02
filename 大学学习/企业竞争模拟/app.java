import java.util.Scanner;
public class app
{
//a application
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		System.out.println("请输入本期机器的数量macno");
		int macno=cin.nextInt();
		//输入机器数量
		System.out.println("请输入期初人数wno");
		double wno=cin.nextDouble();
		//输入期初人数
		double wmax=wno*9/8-(int)(wno*0.03);
		//可用人数最大值 = 期初人数  - 解雇人数 + 起初人数 × 50% × 1/4 
		double b;
		double a;
		for (a=1;a<0.5*wmax*26/9;a++)
		//穷举a：从1～交点
		{
			if (a<(1248*0.5*wmax-1040*macno)/192)
			//机器曲线最大值
			{
				b=(520*macno-120*a)/240;
			}
			else
			//人力曲线最大值
			{
				b=(520*0.5*wmax-180*a)/200;
			}
			double x;
			x=(180*a+200*(int)b)/520;
			//求需求人数
			System.out.println("a为"+a+"的情况下，b为"+(float)b+"。         a,b的比例为"+(float)(a/b)+"         b为"+(int)b+"的情况下一班正人数x为"+(int)x);
		}
	}
}
