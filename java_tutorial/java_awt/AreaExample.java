import java.awt.*;
import java.awt.event.*;

public class AreaExample extends Frame implements ActionListener{
	Label l1,l2;
	TextArea area;
	Button b;
	AreaExample(){
		l1 = new Label();
		l1.setBounds(50,50,170,20);
		l2 = new Label();
		l2.setBounds(250,50,170,20);
		b = new Button("count");
		b.setBounds(170, 450, 70,20);
		area = new TextArea();
		area.setBounds(10,100, 380,300);
		add(l1);add(l2);add(area);add(b);
		b.addActionListener(this);
		setSize(400,500);
		setLayout(null);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e){
		String text = area.getText();
		String arr[] = text.split("\\s");
		l1.setText("Words: " + arr.length);
		l2.setText("Charcters: " + text.length());
	}
	public static void main(String args[]){
		new AreaExample();
	}
}