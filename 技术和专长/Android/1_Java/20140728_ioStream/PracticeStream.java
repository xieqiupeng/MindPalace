import java.io.ByteArrayInputStream;
import java.io.IOException;

/**
 * @author ��ͼ��
 * 
 */
public class PracticeStream {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String s = "Welcome to Java World";
		byte b[] = s.getBytes();
		ByteArrayInputStream bais1 = new ByteArrayInputStream(b);
		ByteArrayInputStream bais2 = new ByteArrayInputStream(b, 0, 7);
		System.out.println("�ֽ���1��" + bais1.available());
		System.out.println("�ֽ���2��" + bais2.available());
		bais1.skip(8);

		int c, c1;
		while ((c = bais1.read()) != -1) {
			System.out.print((char) c);
		}
		System.out.println();
		while ((c1 = bais2.read()) != -1) {
			System.out.print((char) c1);
		}
		System.out.println();
		bais1.reset();
		System.out.println("��mark����");
		int j = 0;
		while ((c = bais1.read()) != -1) {
			j++;
			if (j == 20) {
				bais1.mark(j);
			}
			System.out.print((char) c);
		}
		System.out.println("\nʹ��mark����");
		bais1.reset();
		while ((c = bais1.read()) != -1) {
			System.out.print((char) c);
		}
		bais1.close();
		bais2.close();
	}
}