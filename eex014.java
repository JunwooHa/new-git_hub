package chapter12;

public class ex014 {
	public static void main(String[] args)
	{
		ex011 calculator=new ex011();
		
		ex012 user1 = new ex012();
		user1.setcalculator(calculator);
		user1.start();
		
		ex013 user2 = new ex013();
		user2.setcalculator(calculator);
		user2.start();
	}
}
