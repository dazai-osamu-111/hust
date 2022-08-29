import java.awt.*;
import java.awt.event.*;

public class LabelExample extends Frame implements ActionListener{
	TextField tf; Label l; Button b;
	LabelExample(){
		tf = new TextField();
		tf.setBounds(100,50,150,20);
		l = new Label();
		l.setBounds(100,100,200,20);
		b = new Button("find");
		b.setBounds(100,150,100,20);
		b.addActionListener(this);
		add(tf);add(b);add(l);
		setSize(500,500);
		setLayout(null);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e){
		try{
			String host = tf.getText();
			String ip = java.net.InetAddress.getByName(host).getHostAddress();
			l.setText("IP :     "+ ip);
		} catch(Exception ex){System.out.println(ex);}
	}
	
	public static void main(String args[]){
		new LabelExample();
	}
	
}