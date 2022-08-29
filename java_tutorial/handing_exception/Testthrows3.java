import  java.io.*;
class M{
	void method() throws IOException{
		System.out.println("device error");
	}
}

class Testthrows3{
	public static void main(String args[]) throws IOException{
		M m = new M();
		m.method();
		
		System.out.println("normal flow...");
	}
}