import java.util.LinkedList;
import java.util.Queue;

/**
 * Queue���У��ӿ�
 * �Ƚ��ȳ�������ʵ����LinkedList
 * ��Ӧ�����鷽����ǰһ�鲻�ܲ������ܳ��쳣����һ�鲻�ܲ����᷵��false��
 * ��ӣ� ���ӣ��鿴
 * @author ��ͼ��
 * @since20140805
 */
public class ClassList {

	public static void main(String[] args) {
		Queue queue = new LinkedList();
		queue.add("one");
		queue.add("two");
		queue.add("three");

		// offer����add������ֵ
		// ���ز���ɹ���ʧ��
		boolean b = queue.offer("four");
		System.out.println(b);

		// element��ȡ����peek
		Object object = null;
		object = queue.element();
		System.out.println(object);

		//poll����remove����
		while (!queue.isEmpty()) {
			object = queue.poll();
			System.out.println(object);
		}
	}
}