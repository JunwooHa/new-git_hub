package chapter12;

import java.awt.Toolkit;

public class ex005 {
	public static void main(String[] args)
	{
		Thread thread = new ex004();		
		
		thread.start();
		
		for(int i=0;i<5;i++)
		{
			System.out.println("¶ò");
			
			try
			{
				Thread.sleep(500);
			}
			catch (Exception e)	{}
		}
	}
}
