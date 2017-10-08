import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * �ֽ���ԭ����
 * @author ��ͼ��
 *����isread����int����ȡchar��תΪbyte
 *ԭ����󷵻�-1�������ֽڣ�
 */
public class ClassInputStream {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		InputStream is = null;
		try {
			//���ļ�
			is = new FileInputStream("Practice.txt");
			//���Գ���
			int len = is.available();
			System.out.println(len);
//			����ת���ֽ�
//			for (int i = 0; i < bytes.length; i++) {
//				bytes[i] = (byte) is.read();
//			}
			//����ת��Ϊ�ֽ����顣
			byte[] bytes = new byte[len];
			//is.read(bytes);
			is.read(bytes,2,len-2);
			//�ֽ�����תΪ�ַ���
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
