import java.util.Scanner;

public class FactorialExample{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n, i, fac = 1;
		System.out.print("Enter an integer number: ");
		n = in.nextInt();
		for(i=1;i<=n;i++){
			fac *= i;
		}
		System.out.println("Factorial of " + n + " is " +fac);
	}
}