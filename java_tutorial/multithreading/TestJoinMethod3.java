class TestJoinMethod3 extends Thread{
	public void run(){
		System.out.println("Running...");
	}
	
	public static void main(String args[]){
		TestJoinMethod3 t1 = new TestJoinMethod3();
		TestJoinMethod3 t2 = new TestJoinMethod3();
		
		System.out.println("name of t1: " + t1.getName());
		System.out.println("Name og t2: " + t2.getName());
		System.out.println("id of t1: " + t1.getId());
		
		t1.start();
		t2.start();
		
		t1.setName("Sonoo jaiswal");
		System.out.println("After changing name of 11: " + t1.getName());
	}
}