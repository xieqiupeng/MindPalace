import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * 介绍了InetAddress类的三种方法
 * 
 * @author 构图者
 * 
 */
public class InetAddressMethod {

	/**
	 * @param args
	 * @throws UnknownHostException
	 */
	public static void main(String[] args) throws UnknownHostException {
		// 获得本机的地址
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
