class Student{
	int rollno; // Instance variable
	String name;
	static String college = "ITS"; // static variable
	// constructor
	Student(int r, String n){
		rollno = r;
		name = n;
	}
	// method to display the values
	void display(){
		System.out.println(rollno + " " + name + " " + college);
	}
}

class TestStaticVariable1{
	public static void main(String args[]){
		Student st1 = new Student(111, "Karan");
		Student st2 = new Student(222, "Aryan");
		Student.college = "BKA";
		st1.display();
		st2.display();
	}
}