import java.util.Scanner;

public class KeithNumberExample{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of digits the series must have: ");
		int numlen = sc.nextInt();
		if(numlen<2){
			System.out.println("The number must have at least 2 digits.");
		} else{
			// caculates the upper bound from where the series starts
			long lowBound = (long)Math.pow(10, numlen - 1);
			// caculates the upper bound from where the series ends
			long upperBound = (long)Math.pow(10, numlen);
			for(long l = lowBound; l < upperBound; l++){
				if(isKeith(String.valueOf(l))){
					// print all the Keith number between given range
					System.out.print(l + ",");
				}
			}
			
		}
		sc.close();
	}
	
	public static boolean isKeith(String input){
		int numlen = input.length();
		// keep track only the last three terms
		long[] series = new long[numlen];
		for(int i = 0; i < numlen; i++){
			series[i] = Long.valueOf(input.substring(i, i+1));
		}
		long next_term = 0;
		long number = Long.valueOf(input);
		while(next_term < number){
			next_term = 0;
			// calculate next term of the series
			for(int i = 0; i < numlen; i++){
				next_term = next_term + series[i];
				if( i < numlen - 1){
					// shift series to the left
					series[i] = series[i + 1];
				}else{
					// add new value to the series
					series[i] = next_term;
				}
				
			}
			// compares the next term of the series with the number and 
			// return boolean value accrodingly
			if(next_term == number){
				return true;
			}
		}
		return false;
	}
}