import  java.awt.*;
import  java.awt.event.*;

public class CheckboxGroup2{
	CheckboxGroup2(){
		Frame f = new Frame("Checkbox Group");
		Label l = new Label();
		l.setAlignment(l.CENTER);
		l.setSize(400,100);
		CheckboxGroup cbg = new CheckboxGroup();
		Checkbox cb1 = new Checkbox("C++", cbg, false);
		cb1.setBounds(50,100,50,50);
		Checkbox cb2 = new Checkbox("java", cbg, false);
		cb2.setBounds(50,150,50,50);
		f.add(l);f.add(cb1);f.add(cb2);
		f.setSize(400,400);
		cb1.addItemListener(new ItemListener(){
			public void itemStateChanged(ItemEvent e){
				l.setText("C++ checkbox: Checked");
			}
		});
		
		cb2.addItemListener(new ItemListener(){
			public void itemStateChanged(ItemEvent e){
				l.setText("java checkbox: Checked");
			}
		});
		
		
		f.setLayout(null);
		f.setVisible(true);
	}
	public static void main(String args[]){
		new CheckboxGroup2();
	}
}