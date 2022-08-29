class A1{
	A1 fool(){
		return this;
	}
	
	void print(){
		System.out.println("Inside the class A1");
	}
}

// A2 is the child of A1
class A2 extends A1{
	@Override
	A1 fool(){
		return this;
	}
	
	void print(){
		System.out.println("Inside the class A2");
	}
}

// A3 is the child class of A2

class A3 extends A2{
	@Override
	A1 fool(){
		return this;
	}
	
	@Override
	void print(){
		System.out.println("Inside the class A3");
	}
}

public class CovariantExample{
	// main method
	public static void main(String argvs[]){
		A1 a1 = new A1();
		
		// this is ok
		a1.fool().print();
		
		A2 a2 = new A2();
		
		((A2)a2.fool()).print();
		
		A3 a3 = new A3();
		
		((A3)a3.fool()).print();
	}
}