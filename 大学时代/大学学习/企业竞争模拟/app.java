import java.util.Scanner;
public class app
{
//a application
	public static void main(String args[])
	{
		Scanner cin=new Scanner(System.in);
		System.out.println("�����뱾�ڻ���������macno");
		int macno=cin.nextInt();
		//�����������
		System.out.println("�������ڳ�����wno");
		double wno=cin.nextDouble();
		//�����ڳ�����
		double wmax=wno*9/8-(int)(wno*0.03);
		//�����������ֵ = �ڳ�����  - ������� + ������� �� 50% �� 1/4 
		double b;
		double a;
		for (a=1;a<0.5*wmax*26/9;a++)
		//���a����1������
		{
			if (a<(1248*0.5*wmax-1040*macno)/192)
			//�����������ֵ
			{
				b=(520*macno-120*a)/240;
			}
			else
			//�����������ֵ
			{
				b=(520*0.5*wmax-180*a)/200;
			}
			double x;
			x=(180*a+200*(int)b)/520;
			//����������
			System.out.println("aΪ"+a+"������£�bΪ"+(float)b+"��         a,b�ı���Ϊ"+(float)(a/b)+"         bΪ"+(int)b+"�������һ��������xΪ"+(int)x);
		}
	}
}
