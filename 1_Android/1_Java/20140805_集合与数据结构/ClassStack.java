import java.util.Stack;

/**
 * ջStack
 * @author ��ͼ��
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
		
		//pushѹջ
		//push��stack�ķ�����add��List�ķ��������Ƽ�ʹ�á�
		stack.push("two");
		stack.push("three");
		stack.push("four");
		
		//pop����
		//ȡ������
//		while(!stack.empty()){
//			Object object = stack.pop();
//			System.out.println(object);
//		}
		
		//peek͵��
		//�鿴�鿴�������󣬲��Ƴ�
//		Object object = stack.peek();
//		System.out.println(object);
		
		//search����������˳��Ϊ��ջ����ջ��
		int a = stack.search("three");
		int b = stack.search("two");
		int c = stack.search("one");
		int d = stack.search("t");
		int e = stack.search("four");
		System.out.println(a+" "+b+" "+c+" "+d+" "+e);
	}
}
