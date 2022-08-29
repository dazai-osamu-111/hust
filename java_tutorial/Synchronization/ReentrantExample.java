class Reentrant{
	public synchronized void m(){
		n();
		System.out.println("This is m() method");
	}
	
	public synchronized void n(){
		System.out.println("This is n() method");
	}
}

public class ReentrantExample{
	public static void main(String args[]){
		final Reentrant re = new Reentrant();
		
		Thread t1 = new Thread(){
			public void run(){
				re.m(); // callong method of Reeentrant class
			}
		};
		t1.start();
	}
}