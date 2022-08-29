import javax.swing.*;
import java.awt.event.*;

public class CheckBoxExample2 extends JFrame implements ActionListener{
	JLabel l;
	JCheckBox cb1,cb2,cb3;
	JButton b;
	CheckBoxExample2(){
		l = new JLabel("Food Ordering System");
		l.setBounds(50,50,300,20);
		cb1 = new JCheckBox("Ga 100");
		cb1.setBounds(100,100,300,20);
		cb2 = new JCheckBox("De 150");
		cb2.setBounds(100,150,300,20);
		cb3 = new JCheckBox("meo 200");
		cb3.setBounds(100,200,300,20);
		b = new JButton("Ordering");
		b.setBounds(250,150,250,50);
		add(cb1);add(cb2);add(cb3);add(l);add(b);
		b.addActionListener(this);
		setSize(800,800);
		setLayout(null);
		setVisible(true);
		
	}
	
	public void actionPerformed(ActionEvent e){
		int mount = 0;
		String msg = "";
		if(cb1.isSelected()){
			mount+=100;
			msg += "ga 100\n";
		}
		if(cb2.isSelected()){
			mount += 150;
			msg +="meo 150\n";
		}
		if(cb3.isSelected()){
			mount+=200;
			msg +="de 200\n";
		}
		msg += "------------------\n";
		JOptionPane.showMessageDialog(this, msg + "Total: " + mount);
	}
	public static void main(String args[]){
		new CheckBoxExample2();
	}
}