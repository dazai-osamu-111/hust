class TestMutilPriority extends Thread{
	public void run(){
		System.out.println("running thread name is: " + Thread.currentThread().getName());
		System.out.println("running thread Priority is: " + Thread.currentThread().getPriority());
	}
	
	public static void main(String args[]){
		TestMutilPriority m1 = new TestMutilPriority();
		TestMutilPriority m2 = new TestMutilPriority();
		
		m1.setPriority(Thread.MIN_PRIORITY);
		m2.setPriority(Thread.MAX_PRIORITY);
		
		m1.start();
		m2.start();
	}
}