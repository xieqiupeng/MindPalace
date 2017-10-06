import java.util.*;
/**
 * TreeMap
 * @author ��ͼ��
 *
 */
public class Ch12_02_ExampleTreeMap
{
	Map calendar = new TreeMap();
	//���췽��
	public Ch12_02_ExampleTreeMap(String d[], String i[])
	{
		for(int x=0; x<d.length; x++)
		{
			//����ֱ�Ӹ�map��ֵ������������ֱ�ֵ��key��value��
			calendar.put(d[x],i[x]);
		}
	}
	public static void main(String[] args)
	{
		String[] dates = {"01/01/01", "03/05/01", "02/04/01"};
		String[] items = {"New Years", "Birthday", "Anniversity"};
		Ch12_02_ExampleTreeMap example = new Ch12_02_ExampleTreeMap(dates, items);
		System.out.println("map=" + example.calendar);
		//entrySet������������ӳ���ϵ�� Set ��ͼ
		Set mappings = example.calendar.entrySet();
		System.out.println("Object\t\t\t\tkey\t\tvalue");
		//���ǰ�forѭ����while����
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
