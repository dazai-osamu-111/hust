import java.util.Scanner;

public class PrimeExample3{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int n = s.nextInt();
		if(isPrime(n)){
			System.out.println(n + " ia a prime number");
		} else{
			System.out.println(n+ " is not a prime number");
		}
	}
	
	public static boolean isPrime(int n){
		int m = n/2, i;
		if(n <= 1) return false;
		for(i = 2; i< m;i++){
			if( n % i == 0) return false;
		}
		return true;
	}
}