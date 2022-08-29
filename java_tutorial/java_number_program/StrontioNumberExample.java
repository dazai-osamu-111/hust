import java.util.Scanner;

public class StrontioNumberExample{
	public static void main(String args[]){
		/*Scanner in = new Scanner(System.in);
		System.out.print("Enter upper number: ");
		int n = in.nextInt();*/	
		for(int i=1000; i<=9999;i++){
			if(checkStrontio(i)) 
				System.out.println( i + " is strontio number");
		}
	}
	
	static boolean checkStrontio(int n){
		n = n*2;
		int x1, x2;
		n = n/10;
		x1 = n%10;
		n = n/10;
		x2 = n%10;
		if(x1 == x2) return true;
		else return false;
	}
}