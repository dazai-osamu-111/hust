import java.util.Scanner;

public class LeftTrianglePattern{
	public static void main(String args[]){
		int i, j, n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number: ");
		n = in.nextInt();
		for(i=0;i<n;i++){
			for(j=0;j<n-i-1;j++){
				System.out.print("  ");
			}
			for(j=0;j<=i;j++){
				System.out.print("* ");
			}
			System.out.println();
		}
	}
}