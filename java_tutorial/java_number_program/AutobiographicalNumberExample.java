import java.util.Scanner;

public class AutobiographicalNumberExample{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the upper number: ");
		int n = in.nextInt();
		for(int i=0;i<=n;i++){
			if(isAutobiographicalNumber(String.valueOf(i)))
				System.out.println(i + " is biographical Number" );
		}
	}
	
	static boolean isAutobiographicalNumber(String input){
		int len = input.length(), count;
		long[] series = new long[10];
		for(int i=0;i<len;i++){
			series[i] = Long.valueOf(input.substring(i,i+1));
		}
		for(int i=0;i<10;i++){
			count = 0;
			for(int j=0;j<len;j++){
				if(Long.valueOf(input.substring(j,j+1)) == i) count++;
			}
			if(count != series[i]) return false;
		}
		return true;
	}
}