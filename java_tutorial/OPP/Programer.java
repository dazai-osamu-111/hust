class Employee{
	float salary = 40000;
}

class Programer extends Employee{
	int bonus = 10000;
	public static void main(String args[]){
		Programer pr = new Programer();
		System.out.println("Salary " + pr.salary);
		System.out.println("Bonus " + pr.bonus);
	}
}