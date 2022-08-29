import javax.swing.*;
public class SpinnerExample{
	public static void main(String args[]){
		JFrame f = new JFrame("Spinner Example");
		SpinnerModel value = new SpinnerNumberModel(5,0,10,1);
		JSpinner spinner = new JSpinner(value);
		spinner.setBounds(100,100,50,30);
		f.add(spinner);
		f.setSize(300,300);
		f.setLayout(null);
		f.setVisible(true);
	}
}