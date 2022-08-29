import java.util.Scanner;

public class PalindromeNumberExample{
	public static void main(String args[]){
		int n, temp, sum = 0, r;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter a number: ");
		n = s.nextInt();
		temp = n;
		while(n > 0){
			r = n%10;
			sum = sum*10 + r;
			n = n/10;
		}
		if(temp == sum) System.out.println(temp+" is palindrome number");
		else System.out.println(temp +" is not palindrome number");
	}
}