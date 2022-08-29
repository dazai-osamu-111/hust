import javax.swing.*;
import java.awt.event.*;
public class ComboBoxExample{
	JFrame f;
	ComboBoxExample(){
		f = new JFrame("ComboBox Example");
		final JLabel label = new JLabel();
		label.setHorizontalAlignment(JLabel.CENTER);
		label.setSize(400,100);
		JButton b = new JButton("Show");
		b.setBounds(200,100,75,20);
		String languages[] = {"C", "C++", "C#", "java", "PHP"};
		final JComboBox cb = new JComboBox(languages);
		cb.setBounds(50,100,90,20);
		f.add(cb);f.add(b);f.add(label);
		f.setLayout(null);
		f.setSize(450,450);
		f.setVisible(true);
		b.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				String data = "Programing language Selected: " + cb.getItemAt(cb.getSelectedIndex());
				label.setText(data);
			}
		});
	}
	public static void main(String args[]){
		new ComboBoxExample();
	}
}