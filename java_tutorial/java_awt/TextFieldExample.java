import java.awt.*;

public class TextFieldExample{
	public static void main(String args[]){
	Frame f = new Frame("TextField Example");
	TextField tf1 = new TextField("Welcome to javatpoint");
	tf1.setBounds(100,100,120,20);
	TextField tf2 = new TextField("Awr tutorial");
	tf2.setBounds(100,150,120,20);
	f.add(tf1); f.add(tf2);
	f.setSize(400,400);
	f.add(tf1);f.add(tf2);
	f.setLayout(null);
	f.setVisible(true);
		
	}
}