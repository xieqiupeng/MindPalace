import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * ������InetAddress������ַ���
 * 
 * @author ��ͼ��
 * 
 */
public class InetAddressMethod {

	/**
	 * @param args
	 * @throws UnknownHostException
	 */
	public static void main(String[] args) throws UnknownHostException {
		// ��ñ����ĵ�ַ
		InetAddress address = InetAddress.getLocalHost();
		System.out.println(address);
		address = InetAddress.getByName("sohu.com");
		System.out.println(address);
		InetAddress[] sw = InetAddress.getAllByName("www.sohu.com");
		for (int i = 0; i < sw.length; i++) {
			System.out.println(sw[i]);
		}
	}
}
