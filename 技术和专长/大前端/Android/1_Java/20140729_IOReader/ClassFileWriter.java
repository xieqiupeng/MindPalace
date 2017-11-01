import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class ClassFileWriter {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		//���鸴��
		String src = "������ɽ����"+"�ƺ��纣����"+"����ǧ��Ŀ��"+"����һ��¥��";
		System.out.println(src.length());
		char[] buffer = new char[src.length()];
		src.getChars(0, src.length(), buffer, 0);
		System.out.println("buffer:"+buffer);
		System.out.println(buffer);
		
		//ÿ��һ������
		FileWriter fw = new FileWriter("file1.txt");
		for (int i = 0; i < buffer.length; i+=2) {
			fw.write(buffer[i]);
		}
		fw.close();
		//��¼ȫ��
		FileWriter f1 = new FileWriter("file2.txt");
		f1.write(buffer);
		f1.close();
		//���һ��
		FileWriter f2 = new FileWriter("file3.txt");
		f2.write(buffer, buffer.length- buffer.length/4, buffer.length/4);
		f2.close();
		
		//��������
		FileReader fr = null;
		BufferedReader br;
		for (int i = 0; i < 3; i+=1) {
			fr = new FileReader("file" +(i+1)+".txt");
			br = new BufferedReader(fr);
			String s;
			while ((s= br.readLine())!=null) {
				System.out.println(s);
			}
		}
		fr.close();
	}

}
