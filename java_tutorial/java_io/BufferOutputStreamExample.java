import java.io.*;

public class BufferOutputStreamExample {
	public static void main(String args[])throws Exception{
		FileOutputStream fout = new FileOutputStream("ga.txt");
		BufferedOutputStream bout = new BufferedOutputStream(fout);
		
		String s = "no copy code, write your own code";
		byte b[] = s.getBytes();
		bout.write(b);
		bout.flush();
		bout.close();
		fout.close();
		System.out.println("success");
	}
}