class Reentrant{
	public synchronized void m(){
		n();
		System.out.println("This is m() method");
	}
	
	public synchronized void n(){
		System.out.println("This is n() method");
	}
}