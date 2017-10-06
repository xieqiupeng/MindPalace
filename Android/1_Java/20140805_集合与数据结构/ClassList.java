import java.util.LinkedList;
import java.util.Queue;

/**
 * Queue队列，接口
 * 先进先出，常用实现类LinkedList
 * 对应有两组方法，前一组不能操作会跑出异常，后一组不能操作会返回false。
 * 入队， 出队，查看
 * @author 构图者
 * @since20140805
 */
public class ClassList {

	public static void main(String[] args) {
		Queue queue = new LinkedList();
		queue.add("one");
		queue.add("two");
		queue.add("three");

		// offer等于add，返回值
		// 返回插入成功或失败
		boolean b = queue.offer("four");
		System.out.println(b);

		// element获取等于peek
		Object object = null;
		object = queue.element();
		System.out.println(object);

		//poll等于remove出队
		while (!queue.isEmpty()) {
			object = queue.poll();
			System.out.println(object);
		}
	}
}