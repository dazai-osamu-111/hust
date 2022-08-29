public class FibonacciExample{
	public static void main(String args[]){
		int i, n1 = 1, n2 = 1, n3, n = 10;
		System.out.print(n1 + " " +n2);
		for(i=0;i<n;i++){
			n3 = n1+n2;
			System.out.print(" " + n3);
			n1 = n2;
			n2 = n3;
		}
	}
}