import java.util.Scanner;

public class FascinatingNumberExample{
	public static void main(String args[]){
		int n, i;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter a number: ");
		n = in.nextInt();
		for(i=0;i<=n;i++){
			if(isFascinatingNumber(i)) 
				System.out.println( i + " is fascinating Number");
		}
	}
	static boolean isFascinatingNumber(int n){
		int n1, n2, i, count = 0;
		char c, ch;
		String concatstr;
		n1 = n*2;
		n2 = n*3;
		concatstr = n + "" + n1 + n2;
		//System.out.println(concatstr);
		for(c='1';c<='9';c++){
			count = 0;
			for(i=0;i<concatstr.length();i++){
				ch = concatstr.charAt(i);
				if(ch == '0') continue;
				if(ch == c) count++;
			}
			if(count != 1) 
				return false;
		}
		return true;
	}
}