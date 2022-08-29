class A5{
	void m(){
		System.out.println(this); // print same reference ID
	}
	
	public static void main(String args[]){
		A5 obj = new A5();
		System.out.println(obj); // prints the reference ID
		obj.m();
		A5 obj2 = new A5();
		System.out.println(obj2); // prints the reference ID
		obj.m();
	}
}