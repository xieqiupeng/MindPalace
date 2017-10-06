import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * 
 */

/**
 * @author ¹¹Í¼Õß
 * 
 */
public class Practice {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i;
		FileInputStream fin;
		try {
			fin = new FileInputStream("practice.class");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		try {
			do {
				i = fin.read();
				if (i != -1) {
					System.out.println((char) i);
				}
			} while (i != -1);
			fin.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
