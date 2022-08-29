import javax.swing.*;
import java.awt.event.*;

public class MenuExample implements ActionListener{
	JFrame f;
	JMenuBar mb;
	JMenu file,edit,help;
	JTextArea ta;
	JMenuItem cut,copy,paste,selectAll;
	MenuExample(){
		f = new JFrame("Menu Example");
		file = new JMenu("File");
		edit = new JMenu("Edit");
		help = new JMenu("Help");
		mb = new JMenuBar();
		mb.add(file);mb.add(edit);mb.add(help);
		cut = new JMenuItem("Cut");
		copy = new JMenuItem("Copy");
		paste = new JMenuItem("Paste");
		selectAll = new JMenuItem("Select All");
		edit.add(cut);edit.add(copy);edit.add(paste);edit.add(selectAll);
		f.add(mb);
		ta = new JTextArea();
		ta.setBounds(5,5,360,320);
		f.add(ta);
		cut.addActionListener(this);
		copy.addActionListener(this);
		paste.addActionListener(this);
		selectAll.addActionListener(this);
		f.setJMenuBar(mb);
		f.setSize(400,400);
		f.setVisible(true);
		f.setLayout(null);
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource() == cut)
			ta.cut();
		if(e.getSource() == copy)
			ta.copy();
		if(e.getSource() == paste)
			ta.paste();
		if(e.getSource() == selectAll)
			ta.selectAll();
	}
	
	public static void main(String args[]){
		new MenuExample();
	}
	
}