package chapter12;

public class ex012 extends Thread{
	private ex011 calculator;
	
	public void setcalculator(ex011 calculator)
	{
		this.setName("user1");
		this.calculator = calculator;
	}
	
	public void run()
	{
		calculator.setmemory(100);
	}
}
