import java.io.*;
import java.net.*;

public class MyServer{
	public static void main(String args[]){
		try{
			ServerSocket ss = new ServerSocket(6666);
			Socket s = ss.accept(); // Establishes connecttion and waits for the client
			DataInputStream data = new DataInputStream(s.getInputStream());
			String str = (String)data.readUTF();
			ss.close();
			System.out.println("message=" + str);
		} catch(Exception e){System.out.println(e);}
	}	
}