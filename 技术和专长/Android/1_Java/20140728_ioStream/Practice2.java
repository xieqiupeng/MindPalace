import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * 
 */

/**
 * @author 构图者
 * 
 */
public class Practice {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int i;
		FileInputStream fin;
		FileOutputStream fout;
		//读取文件内容
		try {
			fin = new FileInputStream("text.txt");
		} catch (FileNotFoundException e) {
			System.out.println("无此文件");
			return;
		}
		//open output file
		try {
			fout = new FileOutputStream("text1.txt");
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			return;
		}
		
		//copy file 
		try {
			do {
				i = fin.read();
				if (i != -1) {
					fout.write(i);
				}
			} while (i != -1);
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		fin.close();
		fout.close();
	}
}
