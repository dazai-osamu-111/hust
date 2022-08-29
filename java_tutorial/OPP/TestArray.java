class TestArray{
	public static void main(String args[]){
		int a[] = new int[5]; // declaration and instantiation
		a[0] = 10; //initialization
		a[1] = 20;
		
		// traversing array
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
	}
}