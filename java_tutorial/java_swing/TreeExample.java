import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
public class TreeExample{
	JFrame f;
	TreeExample(){
		f = new JFrame();
		DefaultMutableTreeNode style = new DefaultMutableTreeNode("Style");
		DefaultMutableTreeNode color = new DefaultMutableTreeNode("Color");
		DefaultMutableTreeNode font = new DefaultMutableTreeNode("Font");
		style.add(color);
		style.add(font);
		DefaultMutableTreeNode red = new DefaultMutableTreeNode("Red");
		DefaultMutableTreeNode blue = new DefaultMutableTreeNode("Blue");
		DefaultMutableTreeNode black = new DefaultMutableTreeNode("Black");
		DefaultMutableTreeNode green = new DefaultMutableTreeNode("Green");
		color.add(red);color.add(blue);color.add(black);color.add(green);
		JTree jt = new JTree(style);
		f.add(jt);
		f.setSize(200,200);
		f.setVisible(true);
	}
	public static void main(String args[]){
		new TreeExample();
	}
}