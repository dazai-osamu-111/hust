public class Insertion_sort{
	static void insertion_sort(int arr[]){
		int n = arr.length;
		for(int j=1;j<n;j++){
			int i = j-1;
			int key = arr[j];
			while(i>-1 && arr[i] > key){
				arr[i+1] = arr[i];
				i--;
			}
			arr[i+1] = key;
		}
	}
	public static void main(String args[]){
		int arr[] = {4,5,9,7,4,2,3,4};
		for(int i:arr){
			System.out.print(i+" ");
		}
		System.out.println();
		insertion_sort(arr);
		for(int i:arr){
			System.out.print(i+" ");
		}
		System.out.println();
	}
}