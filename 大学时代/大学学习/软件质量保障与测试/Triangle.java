
// ��������״�ж�����

import java.io.*;

public class Triangle
{
    public static final int Not_a_Triangle = 0;
    public static final int Scalene = 1;
    public static final int Isosceles = 2;
    public static final int Equilateral = 3;

    // �������߳��Ȼ�ȡ��������״
    public int getTriangleType(int a, int b, int c)
    {
        // ע������ int �� long ��ת���������ת������ô���� a + b <= c
        // �������߼����ʽ���� a �� b ��ȡֵ�ӽ�ϵͳ�� int �������͵ļ�
        // ��ֵʱ�����ʽ��������߼�����Ľ����Ԥ�ڲ���
        long al = a, bl = b, cl = c;

        // ʹ�á�������֮�ʹ��ڵ����ߡ��Ķ�����������κϷ����ж�����һ
        // ����ͬ������������ֵ�а��� 0 ����������������ж������ڵȱ�
        // �͵����ж�֮ǰ
        if (al + bl <= cl || bl + cl <= al || cl + al <= bl)
            return Not_a_Triangle;
        else if ( a == b && b == c)
            return Equilateral;
        else if ( a == b || b == c || c == a)
            return Isosceles;
        else
            return Scalene;
    }

    // �ӱ�׼�����ж���һ��������ע��˷��������� Java ���쳣�������
    // ��֤��������ݱ�����������������������а����Ƿ��ַ�����˷���
    // �Զ���ʾ��������
    public int getInteger(BufferedReader in, String msg)
    {
        int ret;
        while(true)
        {
            try
            {
                System.out.print(msg);
                String s = in.readLine();
                ret = Integer.parseInt(s);
            }
            catch (NumberFormatException ex)
            {
                System.out.print("����Ĳ������������������롣");
                continue;
            }
            catch (IOException ex)
            {
                System.out.print("����ʱ����ϵͳ�쳣�����������롣");
                continue;
            }
            return ret;
        }
    }

    public static void main(String[] args)
    {
        Triangle triangle = new Triangle();
        int a, b, c;

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("�����������ε������߳���");

        a = triangle.getInteger(in, "a = ? ");
        b = triangle.getInteger(in, "b = ? ");
        c = triangle.getInteger(in, "c = ? ");

        switch(triangle.getTriangleType(a, b, c))
        {
        case Not_a_Triangle:
            System.out.println("��������Ƿ�");
            break;
        case Scalene:
            System.out.println("���ȱ�������");
            break;
        case Isosceles:
            System.out.println("����������");
            break;
        case Equilateral:
            System.out.println("�ȱ�������");
            break;
        }
    }
}

