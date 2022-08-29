import java.awt.*;
import javax.swing.*;

public class DisplayGraphics extends Canvas{
	public void paint(Graphics g){
		g.drawString("Hello", 40, 40);
		setBackground(Color.WHITE);
		g.fillRect(130,30,50,60);
		setForeground(Color.RED);
		g.fillOval(130,130,50,60);
		g.drawArc(30,200,40,50,90,60);
		g.fillArc(30,30,40,50,180,40);
	}
	
	public static void main(String args[]){
		DisplayGraphics m = new DisplayGraphics();
		JFrame f = new JFrame();
		f.add(m);
		f.setSize(400,400);
		//f.setLayout(null);
		f.setVisible(true);
	}
}