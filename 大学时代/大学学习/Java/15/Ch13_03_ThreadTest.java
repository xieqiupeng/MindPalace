
public class Ch13_03_ThreadTest {
	public static void main(String[] args) {
		Thread t1 = new MyThread("T1");
		t1.setPriority(Thread.MIN_PRIORITY);
		t1.start();
		Thread t2 = new MyThread("T2");
		t2.setPriority(Thread.MAX_PRIORITY);
		t2.start();
		Thread t3 = new MyThread("T3");
		t3.setPriority(Thread.MAX_PRIORITY);
		t3.start();
	}
}

class MyThread extends Thread
{
	String message;
	MyThread(String message)
	{
		this.message = message;
	}
	public void run()
	{
		for(int i=0; i<3; i++)
			System.out.println(message + "  " + getPriority());
	}
}