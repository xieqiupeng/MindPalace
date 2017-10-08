import java.util.Stack;

/**
 * 栈Stack
 * @author 构图者
 *
 */
public class ClassStack {
	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args){
		Stack stack = new Stack();
		stack.add("one");
		
		//push压栈
		//push是stack的方法，add是List的方法，不推荐使用。
		stack.push("two");
		stack.push("three");
		stack.push("four");
		
		//pop跳出
		//取出对象
//		while(!stack.empty()){
//			Object object = stack.pop();
//			System.out.println(object);
//		}
		
		//peek偷看
		//查看查看顶部对象，不移除
//		Object object = stack.peek();
//		System.out.println(object);
		
		//search方法的搜索顺序为从栈顶到栈底
		int a = stack.search("three");
		int b = stack.search("two");
		int c = stack.search("one");
		int d = stack.search("t");
		int e = stack.search("four");
		System.out.println(a+" "+b+" "+c+" "+d+" "+e);
	}
}
