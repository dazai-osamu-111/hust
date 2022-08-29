//A java to test the encapsulated class
package com.javatpoint;
class Test{
	public static void main(String args[]){
		//creating instance of the encapsulation class
		Student s = new Student();
		// setting value in the name member
		s.setName("vijay");
		// getting value of the name member
		System.out.println(s.getName());
	}
}