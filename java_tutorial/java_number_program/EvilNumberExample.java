import java.util.Scanner;

public class EvilNumberExample{
	static long ConvertToBinary(int n){
		long binaryNumber = 0;
		int rem = 0;
		int j = 1;
		while( n > 0 ){
			rem = n % 2;
			binaryNumber += rem*j;
			n = n/2;
			j *=10;
		}
		return binaryNumber;
		
	}
	
	static boolean isEvilNumber(int n){
		int temp,count = 0;
		long binaryNumber = ConvertToBinary(n);
		while(binaryNumber>0){
			temp = (int)binaryNumber%10;
			if(temp == 1) count++;
			binaryNumber = binaryNumber/10;
		}
		if((count%2) == 0 ) return true;
		else return false;
	}
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter upper number: ");
		int n = in.nextInt();
		for(int i=0;i<=n;i++){
			if(isEvilNumber(i))
				System.out.println(i + " is evil number" );
		}
	}
}