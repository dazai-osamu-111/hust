public class LongestRepeatingSequence{
	
	public static String lcp(String str1, String str2){
		int length = Math.min(str1.length(), str2.length());
		for(int i=0;i<length;i++){
			if(str1.charAt(i) != str2.charAt(i)){
				return str1.substring(0,i);
			}
		}
		return str1.substring(0, length);
	}
	
	public static void main(String args[]){
		String str = "abdfghybdf";
		String temp, lrs = "";
		int n = str.length();
		for(int i=0; i<n;i++){
			for(int j=i+1;j<n;j++){
				temp = lcp(str.substring(i,n), str.substring(j,n));
				if(temp.length() > lrs.length())
					lrs = temp;
			}
		}
		System.out.println("Longest repeating sequence is " + lrs);
	}
}