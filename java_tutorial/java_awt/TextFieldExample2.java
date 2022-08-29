import java.awt.*;
import java.awt.event.*;

public class TextFieldExample2 extends Frame implements ActionListener{
		TextField tf1,tf2,tf3;
		Button b1,b2;
		TextFieldExample2(){
			tf1 = new TextField();
			tf1.setBounds(100,50,120,20);
			tf2 = new TextField();
			tf2.setBounds(100,100,120,20);
			tf3 = new TextField();
			tf3.setBounds(100,150,120,20);
			b1 = new Button("+");
			b1.setBounds(50,200, 50,50);
			b2 = new Button("-");
			b2.setBounds(150,200,50,50);
			setSize(400,400);
			b1.addActionListener(this);
			b2.addActionListener(this);
			add(tf1);add(tf2);add(tf3);
			add(b1);add(b2);
			setLayout(null);
			setVisible(true);
		}
		
		public void actionPerformed(ActionEvent e){
			String s1 = tf1.getText();
			String s2 = tf2.getText();
			int a,b;
			a = Integer.parseInt(s1);
			b = Integer.parseInt(s2);
			int c = 0;
			if(e.getSource() == b1){
				c = a +b;
			} else if(e.getSource() == b2){
				c = a - b;
			}
			String s3 = String.valueOf(c);
			tf3.setText(s3);
		}
		public static void main(String args[]){
			new TextFieldExample2();
		}
	}
