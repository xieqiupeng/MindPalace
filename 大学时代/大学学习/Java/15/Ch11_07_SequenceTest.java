import java.io.*;
public class Ch11_07_SequenceTest
{
	public static void main(String[] args)
	{
		FileInputStream fs1, fs2;
		String s;
		try
		{
			//try
			//{
				fs1 = new FileInputStream("text1");
				fs2 = new FileInputStream("text2");
			//}
			SequenceInputStream s1 = new SequenceInputStream(fs1, fs2);
			DataInputStream s2 = new DataInputStream(s1);
			while((s=s2.readLine())!= null)
				System.out.println(s);
		}
		catch(FileNotFoundException e)
		{
			System.err.println("File not found or permission denied");
			System.exit(-1);
		}
		catch(IOException e)
		{
			System.out.println("Error : " + e);
			System.exit(-2);
		}

	}

}
