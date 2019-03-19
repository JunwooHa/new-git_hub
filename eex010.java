package chapter12;

public class ex010 {
	public static void main(String[] args)
	{
		for(int i=1;i<=10;i++)
		{
			Thread thread = new ex009("thread" + i);
			
			if(i != 10)
			{
				thread.setPriority(Thread.MIN_PRIORITY);
			}
			else
			{
				thread.setPriority(Thread.MAX_PRIORITY);
			}
			thread.start();
		}
	}
}
