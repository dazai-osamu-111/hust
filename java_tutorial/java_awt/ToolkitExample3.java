import java.awt.*;
class ToolkitExample3{
	ToolkitExample3(){
		Frame f = new Frame();
		Image icon = Toolkit.getDefaultToolkit().getImage("siesta.png");
		f.setIconImage(icon);
		f.setSize(400,400);
		f.setVisible(true);
	}
	
	public static void main(String args[]){
		new ToolkitExample3();
	}
}