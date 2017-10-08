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
		
		//数组复制
		String src = "白日依山尽，"+"黄河如海流，"+"欲穷千里目，"+"更上一层楼。";
		System.out.println(src.length());
		char[] buffer = new char[src.length()];
		src.getChars(0, src.length(), buffer, 0);
		System.out.println("buffer:"+buffer);
		System.out.println(buffer);
		
		//每隔一个文字
		FileWriter fw = new FileWriter("file1.txt");
		for (int i = 0; i < buffer.length; i+=2) {
			fw.write(buffer[i]);
		}
		fw.close();
		//记录全部
		FileWriter f1 = new FileWriter("file2.txt");
		f1.write(buffer);
		f1.close();
		//最后一句
		FileWriter f2 = new FileWriter("file3.txt");
		f2.write(buffer, buffer.length- buffer.length/4, buffer.length/4);
		f2.close();
		
		//读出数据
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
