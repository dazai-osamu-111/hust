class Student{
	int rollno;
	String name;
	void insertRecord(int r, String n){
		rollno = r;
		name = n;
	}
	
	void displayInformation(){
		System.out.println(rollno + " " + name);
	}
}

class TestStudent4{
	public static void main(String args[]){
		Student s1 = new Student();
		s1.insertRecord(101, "Karan");
		s1.displayInformation();
	}
}