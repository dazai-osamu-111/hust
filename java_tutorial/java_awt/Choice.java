import java.awt.*;

public class Choice{
	Choice(){
		Frame f = new Frame("Choice example");
		Choice c = new Choice();
		c.setBounds(100,100,100,20);
		c.add("item 1");
		c.add("item 2");
		c.add("item 3");
		c.add("item 4");
		c.add("item 5");
		f.add(c);
		f.setSize(400,400);
		f.setLayout(null);
		f.setVisible(true);
	}
	public static void main(String args[]){
		new Choice();
	}
}