class TestFinallyBlock{
	public static void main(String args[]){
		try{
			String s= null;
			int data = 25/5;
			s.length();
			System.out.println(data);
		} catch(NullPointerException e){System.out.println(e);}
		finally{System.out.println("finally block is always executed");}
		System.out.println("rest of the code ...");
	}
}