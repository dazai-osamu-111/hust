class Bike{
	void run(){
		System.out.println("running...");
	}
}

class Splendor extends Bike{
	void run(){
		System.out.println("Running safely with 60 km");
	}
	
	public static void main(String args[]){
		Bike b = new Splendor(); //upcasting
		b.run();
	}
}