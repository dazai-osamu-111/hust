abstract class Demo{
	abstract void display();
}

public class Myclass extends Demo{
	void display(){
		System.out.println("Abstract method?");
	}
	
	public static void main(String args[]){
		Demo obj = new Myclass();
		obj.display();
	}
}