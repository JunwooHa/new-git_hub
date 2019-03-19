package chapter12;

public class ex009 extends Thread{
	public ex009(String name)
	{
		setName(name);
	}
	public void run()
	{
		for(int i=0;i<200000000;i++)
		{
			System.out.println(getName());
		}
	}
}
