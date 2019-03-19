package chapter12;

public class ex011 {
	private int memory;
	
	public int getmemory()
	{
		return memory;
	}
	
	public void setmemory(int memory)
	{
		this.memory=memory;
		try
		{
			Thread.sleep(2000);
		}
		catch(InterruptedException e)	{}
		System.out.println(Thread.currentThread().getName() + ": " + this.memory);
	}
}
