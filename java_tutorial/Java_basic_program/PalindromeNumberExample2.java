import java.util.*;

public class PalindromeNumberExample2{
	public static void main(String args[]){
		int length, i;
		Scanner Original = new Scanner(System.in);
		String reverse = ""; // Object of String class
		System.out.print("Enter a string/number to check if it is a palindrome number: ");
		String temp;
		temp = Original.nextLine();
		for(i = temp.length() - 1; i>=0; i--){
			reverse = reverse + temp.charAt(i);
		}
		if(temp.equals(reverse)) System.out.println(temp + " is palindrome number/string");
		else System.out.println(temp + " is not palindrome number/String");
	}
}