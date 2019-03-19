package chapter12;

import java.awt.Toolkit;

public class ex003 {
	public static void main(String[] args)
	{
		Runnable beepTask=new ex002();
		Thread thread=new Thread(beepTask);
		
		thread.start();
		for(int i=0;i<5;i++)
		{
			System.out.println("¶ò");
			try
			{
				Thread.sleep(500);
			}
			catch(Exception e)	{}
		}
	}
}
