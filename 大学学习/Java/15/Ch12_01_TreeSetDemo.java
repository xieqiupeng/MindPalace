import java.util.*;
/**
 * TreeSet是可以自动排序的
 * @author 构图者
 */
public class Ch12_01_TreeSetDemo 
{
	public static void main(String[] args)
	{
		TreeSet ts = new TreeSet();
		ts.add("C");
		ts.add("A");
		ts.add("B");
		ts.add("E");
		ts.add("F");
		ts.add("D");
		ts.add("0");
		System.out.println(ts);
	}
}