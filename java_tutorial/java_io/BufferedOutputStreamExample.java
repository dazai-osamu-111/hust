import java.io.*;

public class BufferedOutputStreamExample{
public static void main(String args[]) throws Exception{
	FileInputStream input1 = new FileInputStream("ga.txt");
	FileInputStream input2 = new FileInputStream("ga2.txt");
	SequenceInputStream inst = new SequenceInputStream(input1, input2);
	int i;
	while((i=inst.read()) != -1){
		System.out.print((char)i);
	}
	inst.close();
	input1.close();
	input2.close();
}
}