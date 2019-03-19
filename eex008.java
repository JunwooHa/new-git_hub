package chapter12;

public class ex008 {
	public static void main(String[] args)
	{
		Thread mainthread = Thread.currentThread();
		System.out.println("프로그램 시작 스레드 이름:" + mainthread.getName());
		
		ex006 threadA =new ex006();
		System.out.println("작업 스레드 이름:" + threadA.getName());
		threadA.start();
		
		ex007 threadB = new ex007();
		System.out.println("작업 스레드 이름:" + threadB.getName());
		threadB.start();
	}
}
