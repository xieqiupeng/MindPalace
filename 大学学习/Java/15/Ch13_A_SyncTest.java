class SyncStack
{
	private int index = 0;
	private char []buffer = new char[6];
	public synchronized void push(char c)
	{
		while(index == buffer.length)
		{
			try
			{
				this.wait();
			}
			catch(InterruptedException e){}
		}
		this.notify();
		buffer[index] = c;
		index ++;
	}
	public synchronized char pop()
	{
		while(index == 0)
		{
			try
			{
				this.wait();
			}
			catch(InterruptedException e)
			{}
		}
		this.notify();
		index --;
		return buffer[index];
	}
}

class Producer implements Runnable
{
	SyncStack theStack;
	public Producer(SyncStack s)
	{
		theStack = s;
	}
	public void run()
	{
		char c;
		for(int i=0; i<20; i++)
		{
			c = (char)(Math.random()*26 + 'A');
			theStack.push(c);
			System.out.println("Produced: " + c);
			try
			{
				Thread.sleep((int)(Math.random()*100));
			}
			catch(InterruptedException e){}
		}
	}
}

class Consumer implements Runnable
{
	SyncStack theStack;
	public Consumer(SyncStack s)
	{
		theStack = s;
	}
	public void run()
	{
		char c;
		for(int i=0; i<20; i++)
		{
			c = theStack.pop();
			System.out.println("Consumed: " + c);
			try
			{
				Thread.sleep((int)(Math.random()*1000));
			}
			catch(InterruptedException e)
			{
			}
		}
	}
}


public class Ch13_A_SyncTest {
	public static void main(String[] args) {
		SyncStack stack = new SyncStack();
		Runnable source = new Producer(stack);
		Runnable sink = new Consumer(stack);
		Thread t1 = new Thread(source);
		Thread t2 = new Thread(sink);
		t1.start();
		t2.start();
	}
}
