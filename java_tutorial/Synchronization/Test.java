class Customer{
	int mount = 10000;
	
	synchronized void withdraw(int mount){
		if(this.mount < mount){
			System.out.println("lower balance, waiting for deposit");
			try{wait();} catch(Exception e){};
		}
		this.mount -= mount;
		System.out.println("withdraw completed...");
	}
	
	synchronized void deposit(int mount){
		System.out.println("Going to deposit...");
		this.mount += mount;
		System.out.println("deposit completed...");
		notify();
	}
}

class Test{
	public static void main(String args[]){
		final Customer c = new Customer();
		new Thread(){
			public void run(){c.withdraw(15000);}
		}.start();
		new Thread(){
			public void run(){c.deposit(10000);}
		}.start();
	}
}