package chapter2;

public class ex014 
{
	public static void main(String[] args)
	{
		int num1=123456780;
		int num2=123456780;
		
		float num3=num2; /*�� �������� float�Լ��� ������23��Ʈ�� ���� �� �ִµ� int�� ũ��� 32��Ʈ �̹Ƿ� �ڷᰡ �սǵȴ�
							�׷��� ���⼭ num2�� num1�� ���� ���� �� �� ���� */
		num2=(int) num3;
		
		int result=num1 - num2;
		System.out.println(result);
	}
}
