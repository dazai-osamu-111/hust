import java.io.*;

class Parent{
	void msg(){System.out.println("parent");}
}

class TestExceptionChild extends Parent{
	void msg() throws ArithmeticException{
		System.out.println("Child");
	}
	
	public static void main(String args[]){
		Parent p = new TestExceptionChild();
		p.msg();
	}
}