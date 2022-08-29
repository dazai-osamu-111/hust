interface personExample{
	public void input();
	public void display();
}

public class Person implements personExample{
	protected String id;
	protected String name;
	protected int age;
	
	Person(String id, String name, int age){
		this.id = id;
		this.name = name;
		this.age = age;
	}
	
	void setId( String id){
		this.id = id;
	}
	String getId(){
		return this.id;
	}
	
	
	void setName( String name){
		this.name = name;
	}
	String getName(){
		return this.name;
	}
	
	
	void setAge(int age){
		this.age = age;
	}
	int getAge(){
		return this.age;
	}
	
	
}