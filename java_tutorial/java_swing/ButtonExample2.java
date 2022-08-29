import javax.swing.*;
import java.awt.event.*;

public class ButtonExample2{
	ButtonExample2(){
		JFrame f = new JFrame();
		JButton b = new JButton("click here");
		b.setBounds(100,100,100,20);
		b.setIcon( new ImageIcon("siesta.png"));
		JLabel l = new JLabel();
		l.setBounds(100,30,200,20);
		b.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				l.setText("welcome to javatpoint");
			}
		});
		f.setSize(400,400);
		f.add(l); f.add(b);
		f.setLayout(null);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public static void main(String args[]){
		new ButtonExample2();
	}
}