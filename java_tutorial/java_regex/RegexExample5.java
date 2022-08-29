import java.util.regex.*;
class RegexExample5{
	public static void main(String args[]){
		System.out.println("Metacharecters d..."); // d means digit
		
		System.out.println(Pattern.matches("\\d", "abc")); 
		System.out.println(Pattern.matches("\\d", "1")); 
		System.out.println(Pattern.matches("\\d", "4443")); 
		System.out.println(Pattern.matches("\\d", "323abc"));

		System.out.println("metacharecters D...");  //D means non-digit
		
		System.out.println(Pattern.matches("\\D", "abc")); 
		System.out.println(Pattern.matches("\\D", "1")); 
		System.out.println(Pattern.matches("\\D", "4443")); 
		System.out.println(Pattern.matches("\\D", "323abc")); 
		System.out.println(Pattern.matches("\\D", "m")); 
		
		System.out.println(Pattern.matches("\\D*" , "mak"));
	}
}