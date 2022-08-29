public class Employee{
	private int regno;
	private String name;
	// constructor of Employee class
	public Employee(int regno, String name){
		this.name = name;
		this.regno = regno;
	}
	
	public int getRegno(){
		return regno;
	}
	public void setRegno(int Regno){
		this.regno = regno;
	}
	
	public String getName(){
		return name;
	}
	
	public void setName(String name){
		this.name = name;
	}
}