import java.util.*;
/**
 * TreeMap
 * @author 构图者
 *
 */
public class Ch12_02_ExampleTreeMap
{
	Map calendar = new TreeMap();
	//构造方法
	public Ch12_02_ExampleTreeMap(String d[], String i[])
	{
		for(int x=0; x<d.length; x++)
		{
			//这是直接给map赋值，用两个数组分别赋值给key和value。
			calendar.put(d[x],i[x]);
		}
	}
	public static void main(String[] args)
	{
		String[] dates = {"01/01/01", "03/05/01", "02/04/01"};
		String[] items = {"New Years", "Birthday", "Anniversity"};
		Ch12_02_ExampleTreeMap example = new Ch12_02_ExampleTreeMap(dates, items);
		System.out.println("map=" + example.calendar);
		//entrySet方法，包含的映射关系的 Set 视图
		Set mappings = example.calendar.entrySet();
		System.out.println("Object\t\t\t\tkey\t\tvalue");
		//这是把for循环当while来用
		for(Iterator i=mappings.iterator(); i.hasNext();)
		{
			Map.Entry me = (Map.Entry)i.next();
			Object objectK = me.getKey();
			Object objectV = me.getValue();
			System.out.print(me + "\t");
			System.out.print(objectK + "\t");
			System.out.println(objectV);
		}
	}

}
