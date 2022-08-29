public class RecursionExample1{
	static void p(){
		System.out.println("Hello");
		p();
	}
	public static void main(String args[]){
		p();
	}
}