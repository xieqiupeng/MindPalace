import java.util.Arrays;
import java.util.Scanner;

public class changeNumber {
	public static void main(String[] args) {
		Scanner cin= new Scanner(System.in);
		int[] a = new int[10];
		int p;
		for (int i = 0; i < 10; i++) {
			System.out.println("请输入第"+i+"个数字");
			a[i] = cin.nextInt();
			System.out.println(Arrays.toString(a));
		}
		System.out.println(Arrays.toString(a));
		for (int i = 0; i < 5; i++) {
			p = a[i];
			a[i] = a[9-i];
			a[9-i] = p;
		}
		System.out.println(Arrays.toString(a));
	}
}