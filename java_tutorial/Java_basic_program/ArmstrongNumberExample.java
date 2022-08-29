import java.util.Scanner;
import java.lang.Math;

public class ArmstrongNumberExample{
	static boolean checkArmstrongNumber(int n){
		int temp, digit = 0, sum = 0, last;
		temp = n;
		while(temp>0){
			temp = temp/10;
			digit++;
		}
		temp = n;
		while(temp > 0){
			last = temp%10;
			sum += (Math.pow(last, digit));
			temp = temp/10;
		}
		if(sum == n) return true;
		else return false;
	}
	
	public static void main(String args[]){
		int n, i;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter linmit number: ");
		n = in.nextInt();
		for(i=1;i<=n;i++){
			if(checkArmstrongNumber(i)) 
				System.out.print(i + " ");
		}
		System.out.println();
	}
}