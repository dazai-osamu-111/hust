import java.io.*;
import java.net.*;

public class Myclient{
	public static void main(String args[]){
		try{
			Socket s = new Socket("localhost",6666);
			DataInputStream dout = new DataOutputStream(s.getOutputStream());
			dout.writeUTF("Hello Server");
			dout.flush();
			doutclose();
			s.close();
		} catch(Exception e){System.out.println(e);}
	}
}