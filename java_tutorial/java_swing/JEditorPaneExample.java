import javax.swing.*;

public class JEditorPaneExample{
	JFrame myFrame = null;
	
	public static void main(String args[]){
		(new JEditorPaneExample()).test();
	}
	
	private void test(){
		myFrame = new JFrame("JEditorPane Test");
		myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		myFrame.setSize(400,200);
		JEditorPane myPane = new JEditorPane();
		myPane.setContentType("text/plain");
		myPane.setText("Sleeping is necessary for a healthy body."
		+ " But sleeping in unnecessary times may spoil out health, wealth and studies" );
		myFrame.setContentPane(myPane);
		myFrame.setVisible(true);
	}
}