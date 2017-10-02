import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 
 * @author 构图者
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
		
		//交换指定列表指定位置元素。
//		Collections.swap(list, 0, 3);
		//排序
//		Collections.sort(list);
		//统计个数
		int a = Collections.frequency(list, "one");
		System.out.println(a);
		//反转顺序
//		Collections.reverse(list); 
		//替换
		Collections.replaceAll(list, "four", "ten");
		
		for (int i = 0; i < list.size(); i++) {
			Object object = list.get(i);
			System.out.println(object);
		}
	}
}
