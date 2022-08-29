import java.io.*;
class M{
	void method() throws IOException{
		throw new IOException("device error");
	}
}

class Testthows4{
	public static void main(String args[]) throws IOException{
		M m = new M();
		m.method();
		
		System.out.println("normal flow...");
	}
}