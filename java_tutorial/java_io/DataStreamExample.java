import java.io.*;

public class DataStreamExample{
	public static void main(String args[]) throws Exception{
		InputStream input = new FileInputStream("ga.txt");
		DataInputStream inst = new DataInputStream(input);
		int count = input.available();
		byte arr[] = new byte[count];
		inst.read(arr);
		for(int i: arr){
			char k = (char) i;
			System.out.print(k + "-");
		}
	}
}