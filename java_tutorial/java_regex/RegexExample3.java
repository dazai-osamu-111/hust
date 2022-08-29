import java.util.regex.*;
class RegexExample3{
	public static void main(String args[]){
		System.out.println(Pattern.matches("[amn]", "abcd"));
		System.out.println(Pattern.matches("[amn]", "a"));
		System.out.println(Pattern.matches("[amn]", "m"));
	}
}