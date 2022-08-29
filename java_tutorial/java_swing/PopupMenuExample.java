import javax.swing.*;
import java.awt.event.*;
class PopupMenuExample{
	PopupMenuExample(){
	final JFrame f = new JFrame("PopupMenu Example");
	final JLabel label = new JLabel();
	label.setHorizontalAlignment(JLabel.CENTER);
	label.setSize(400,100);
	final JPopupMenu popupmenu = new JPopupMenu("Edit");
	JMenuItem cut = new JMenuItem("Cut");
	JMenuItem copy = new JMenuItem("Copy");
	JMenuItem paste = new JMenuItem("Paste");
	popupmenu.add(cut);popupmenu.add(copy);popupmenu.add(paste);
	f.addMouseListener(new MouseAdapter(){
		public void mouseClicked(MouseEvent e){
			popupmenu.show(f,e.getX(),e.getY());
		}
	});
	copy.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
			label.setText("copy MenuItem clicked");
		}
	});
	cut.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
			label.setText("cut MenuItem clicked");
		}
	});
	paste.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent e){
			label.setText("paste MenuItem clicked");
		}
	});
	f.add(label);f.add(popupmenu);
	f.setSize(400,400);
	f.setVisible(true);
	f.setLayout(null);
}
public static void main(String args[]){
	new PopupMenuExample();
}
}