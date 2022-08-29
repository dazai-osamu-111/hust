class Student{
	int rollno;
	String name;
	float fee;
	Student(int rollno, String name, float fee){
		this.rollno = rollno;
		this.name = name;
		this.fee = fee;
	}

	void display(){
		System.out.println(rollno + " " + name + " " + fee);
	}
}
	class TestThis1{
	public static void main(String args[]){
		Student st = new Student(111, "hau dang yeu", 4.3f);
		st.display();
	}
	}