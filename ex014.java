package chapter2;

public class ex014 
{
	public static void main(String[] args)
	{
		int num1=123456780;
		int num2=123456780;
		
		float num3=num2; /*이 과정에서 float함수의 가수는23비트를 받을 수 있는데 int의 크기는 32비트 이므로 자료가 손실된다
							그래서 여기서 num2는 num1과 같은 값이 될 수 없다 */
		num2=(int) num3;
		
		int result=num1 - num2;
		System.out.println(result);
	}
}
