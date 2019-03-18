package chapter2;

public class ex008 
{
	public static void main(String[] args)
	{
		long var1=10;
		long var2=20L;
		//long var3=10000000000;	범위를 초과해서 컴파일 에러
		long var4=10000000000L;	//숫자 뒤에 l을 붙인 이유는 이 변수값이 4바이트가 아닌 8바이트를 알리기 위함이다
		
		System.out.println(var1);
		System.out.println(var2);
		System.out.println(var4);
	}
}
