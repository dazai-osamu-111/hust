import java.util.Scanner;


public class AutomorphicNumberExample{
	public static void main(String args[]){
		int n, i;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter a number: ");
		n = in.nextInt();
		for(i=0;i<n;i++){
			if(isAutomorphic(i)) System.out.print(i + " ");
		}
		System.out.println();
	}
	static boolean isAutomorphic(int n){
		int temp = n;
		int square, lastDigit = 0, count = 0, i;
		square = n*n;
		for(;n>0;n=n/10){
			count++;
		}
		for(;count>0;count=count/10){
			lastDigit = (int)((int)lastDigit*count + (int)square%(Math.pow(10, count))); 
		}
		if(lastDigit == temp) return true; 
		else return false;
	}
}