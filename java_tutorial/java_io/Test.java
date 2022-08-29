import java.io.*;

class Test{
	public static void main(String args[]) throws Exception{
		FileOutputStream fout = new FileOutputStream("ga2.txt");
		BufferedOutputStream bout = new BufferedOutputStream(fout);
		String s = "in the rain. after trying my best, i failed";
		byte arr[] = s.getBytes();
		bout.write(arr);
		bout.flush();
		bout.close();
		fout.close();
		System.out.println("success");
	}
}