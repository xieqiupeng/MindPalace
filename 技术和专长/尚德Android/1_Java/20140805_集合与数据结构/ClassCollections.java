import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 
 * @author ��ͼ��
 *
 */
public class ClassCollections {
	
	/**
	 *
	 */
	public static void main(String[] args) {
		List list = new ArrayList();
		list.add("one");
		list.add("two");
		list.add("three");
		list.add("four");
		
		//����ָ���б�ָ��λ��Ԫ�ء�
//		Collections.swap(list, 0, 3);
		//����
//		Collections.sort(list);
		//ͳ�Ƹ���
		int a = Collections.frequency(list, "one");
		System.out.println(a);
		//��ת˳��
//		Collections.reverse(list); 
		//�滻
		Collections.replaceAll(list, "four", "ten");
		
		for (int i = 0; i < list.size(); i++) {
			Object object = list.get(i);
			System.out.println(object);
		}
	}
}
