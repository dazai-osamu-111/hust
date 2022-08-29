import java.util.Scanner;

public class Sqrtroot{
	public static void main(String args[]){
		System.out.print("Enter a number: ");
		Scanner sc = new Scanner(System.in);
		double n = sc.nextDouble();
		System.out.println("Square root of n is: " + squareRoot(n));
	}
	
	static double squareRoot(double n){
		double t;
		double sqrtroot = n/2;
		do{
			t = sqrtroot;
			sqrtroot = ( t + n/t)/2;
		} while( t != sqrtroot);
		
		return t;
	}
}