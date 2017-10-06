
// 三角形形状判定程序

import java.io.*;

public class Triangle
{
    public static final int Not_a_Triangle = 0;
    public static final int Scalene = 1;
    public static final int Isosceles = 2;
    public static final int Equilateral = 3;

    // 根据三边长度获取三角形形状
    public int getTriangleType(int a, int b, int c)
    {
        // 注意下面 int 到 long 的转换，如果不转换，那么对于 a + b <= c
        // 这样的逻辑表达式，当 a 和 b 的取值接近系统中 int 数据类型的极
        // 大值时，表达式将溢出，逻辑运算的结果与预期不符
        long al = a, bl = b, cl = c;

        // 使用“两条边之和大于第三边”的定理进行三角形合法性判定，这一
        // 方法同样适用于输入值中包含 0 或负数的情况。但此判定必须在等边
        // 和等腰判定之前
        if (al + bl <= cl || bl + cl <= al || cl + al <= bl)
            return Not_a_Triangle;
        else if ( a == b && b == c)
            return Equilateral;
        else if ( a == b || b == c || c == a)
            return Isosceles;
        else
            return Scalene;
    }

    // 从标准输入中读入一个整数。注意此方法中利用 Java 的异常处理机制
    // 保证输入的内容必须是整数；如果输入内容中包含非法字符，则此方法
    // 自动提示重新输入
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
                System.out.print("输入的不是整数，请重新输入。");
                continue;
            }
            catch (IOException ex)
            {
                System.out.print("输入时发生系统异常，请重新输入。");
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
        System.out.println("请输入三角形的三条边长度");

        a = triangle.getInteger(in, "a = ? ");
        b = triangle.getInteger(in, "b = ? ");
        c = triangle.getInteger(in, "c = ? ");

        switch(triangle.getTriangleType(a, b, c))
        {
        case Not_a_Triangle:
            System.out.println("输入参数非法");
            break;
        case Scalene:
            System.out.println("不等边三角形");
            break;
        case Isosceles:
            System.out.println("等腰三角形");
            break;
        case Equilateral:
            System.out.println("等边三角形");
            break;
        }
    }
}

