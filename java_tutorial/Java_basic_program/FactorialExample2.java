import java.util.Scanner;

public class FactorialExample2{
	static int checkFactorial(int n){
		if(n == 0) return 1;
		else return  (n*checkFactorial(n-1));
	}
	
	public static void main(String args[]){
		int n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter an integer number: ");
		n = in.nextInt();
		n = checkFactorial(n);
		System.out.println("Factorial of n is " + n);
	}	
}