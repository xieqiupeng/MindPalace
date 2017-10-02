import java.util.*;
public class ThreadTime
{
	public static void main(String[] args) throws InterruptedException
	{
		Runner r = new Runner();
		Thread t1 = new Thread(r);
		t1.start();
		Thread t2 = new Thread(r);
		t2.start();
		Thread t3 = new Thread(r);
		t3.start();
	}
}

class Runner implements Runnable
{
	public void run()
	{
		Date now = new Date();
		System.out.println("The thread time is- " + now.getHours() + " : " + now.getMinutes() + " : " + now.getSeconds());
	}
}