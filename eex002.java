package chapter12;

import java.awt.Toolkit;

public class ex002 implements Runnable
{
	public void run()
	{
		Toolkit toolkit=Toolkit.getDefaultToolkit();
		
		for(int i=0;i<5;i++)
		{
			toolkit.beep();
			try
			{
				Thread.sleep(500);
			}
			catch(Exception e)	{}
		}
	}
}
