import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class ClassFileReader {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		FileReader fr = new FileReader("Practice.java");
		BufferedReader br = new BufferedReader(fr);
		
		//sΪһ���ַ���������Ϊ�յ�ʱ�򣬴�ӡȻ����ת����һ�С�
		String s = br.readLine();
		while (s != null){
			System.out.println(s);
			s = br.readLine();
		};
		
		fr.close();
	}
}
