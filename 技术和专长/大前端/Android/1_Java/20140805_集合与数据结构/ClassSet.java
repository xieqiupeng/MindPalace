import java.util.HashSet;
import java.util.Iterator;
import java.util.Random;
import java.util.Set;

/**
 * Set�ӿڵ�ʵ����HashSet
 * ͨ����������Iterator�����Բ鿴���������е�Ԫ�ء�
 * @author ��ͼ��
 *
 */
public class ClassSet {
	public static void main(String[] args) {
		Set set;
		set = new HashSet();
		set.add("one");
		set.add("two");
		set.add("three");
		set.add("four");
		Random random = new Random(System.currentTimeMillis());
		while(set.size()<10){
			int a = random.nextInt(100);
			String str = Integer.toString(a);
			set.add(str);	
		}
		Iterator iterator = set.iterator();
		while(iterator.hasNext()){
			Object object = iterator.next();
			System.out.println(object);
		}
	}
}