public class MultipleCatchBlock1{
	public static void main(String args[]){
		
		try{
			int a[] = new int[5];
			a[5] = 30/0;
		} 
		catch(ArithmeticException e){
			System.out.println("Arithmetic Eception occurs");
		}
		
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("ArrayIndexOutOfBoundsException occurs");
		}
		catch(Exception e){
			System.out.println("Parent Exeption occurs");
		}
		
		System.out.println("rest of code");
	}
}