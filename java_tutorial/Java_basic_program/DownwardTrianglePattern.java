import java.util.Scanner;

public class DownwardTrianglePattern{
	public static void main(String args[]){
		int i, j, n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a number: ");
		n = in.nextInt();
		for(i=0;i<n;i++){
			for(j=0;j<n-i;j++){
				System.out.print("* ");
			}
			System.out.println();
		}
	}
}
