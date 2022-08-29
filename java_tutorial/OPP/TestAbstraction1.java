abstract class Shape{
	abstract void draw();
}

class Rectangle extends Shape{
	void draw(){
		System.out.println("drawing rectangle");
	}
}

class Circle1 extends Shape{
	void draw(){
		System.out.println("drawing circle");
	}
}

// in real scenario method is called by programer or user

class TestAbstraction1{
	public static void main(String args[]){
		Shape s = new Circle1(); // In a real scenario, object is provided through 
		// method e.g.., getShape() method
		s.draw();
	}
}