import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * 字节流原理讲解
 * @author 构图者
 *问题isread返回int，读取char，转为byte
 *原因，最后返回-1（两个字节）
 */
public class ClassInputStream {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		InputStream is = null;
		try {
			//打开文件
			is = new FileInputStream("Practice.txt");
			//测试长度
			int len = is.available();
			System.out.println(len);
//			单个转化字节
//			for (int i = 0; i < bytes.length; i++) {
//				bytes[i] = (byte) is.read();
//			}
			//把流转化为字节数组。
			byte[] bytes = new byte[len];
			//is.read(bytes);
			is.read(bytes,2,len-2);
			//字节数组转为字符串
			String str = new String(bytes,0,len);
			System.out.println(str);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally{
			if(is != null){
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
	}

}
