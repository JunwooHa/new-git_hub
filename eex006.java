package chapter12;

public class ex006 extends Thread{
	public ex006()
	{
		setName("ex006");
	}
	public void run()
	{
		for(int i=0;i<2;i++)
		{
			System.out.println(getName() + "가 출력한 내용");
		}
	}
}
