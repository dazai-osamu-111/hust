import java.util.Scanner;

public class ReversePyramidPattern{
	public static void main(String args[]){
		int i, j, n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number: ");
		n = in.nextInt();
		for(i=0;i<n;i++)
			System.out.print("* ");
		System.out.println();
		for(i=0;i<n-1;i++){
			for(j=0;j<=i;j++){
				System.out.print(" ");
			}
			for(j=0;j<n-i-1;j++)
				System.out.print("* ");
			System.out.println();
		}
	}
}
