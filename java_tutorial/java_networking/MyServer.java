import java.io.*;
import java.net.*;

public class MyServer{
	public static void main(String args[]) throws Exception{
		ServerSocket ss = new ServerSocket(3333);
		Socket s = ss.accept();
		DataInputStream din = new DataInputStream(s.getInputStream());
		DataOutputStream dout = new DataOutputStream(s.getOutputStream());
		InputStreamReader sr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(sr);
		String str1="", str2="";
		while(!str1.equals("stop")){
			str1 =  din.readUTF();
			System.out.println("Client says: " + str1);
			//str2 = br.readLine();
			//dout.writeUTF(str2);
			//dout.flush();
		}
		dout.close();
		din.close();
		ss.close();
	}	
}