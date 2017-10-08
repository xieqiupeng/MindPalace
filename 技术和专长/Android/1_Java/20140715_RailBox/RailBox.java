public class RailBox {
	
	//定义一个对象，还有把自己给实例化了。
	 Object data;
	 RailBox next;
	
	public static void main(String args[])
	{
		RailBox railBox = new RailBox();
		Apple apple = new Apple();
		railBox.data = apple;
		System.out.println(railBox.data);
		
		RailBox railBox2 = new RailBox();
		Orange orange = new Orange();
		railBox2.data = orange;
		
		railBox.next = railBox2;
		
		System.out.println(railBox.next.data);
	}	
}