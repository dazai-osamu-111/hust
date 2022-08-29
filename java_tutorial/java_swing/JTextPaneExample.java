import java.awt.*;
import javax.swing.*;
import javax.swing.text.*;

public class JTextPaneExample{
	public static void main(String args[]) throws BadLocationException{
		JFrame frame = new JFrame("JTextPane Example");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container cp = frame.getContentPane();
		JTextPane pane = new JTextPane();
		SimpleAttributeSet attributeSet = new SimpleAttributeSet();
		StyleConstants.setBold(attributeSet,true);
		
		// Set the attribute before adding text
		pane.setCharacterAttributes(attributeSet, true);
		pane.setText("Welcome");
		
		attributeSet = new SimpleAttributeSet();
		StyleConstants.setItalic(attributeSet, true);
		StyleConstants.setForeground(attributeSet, Color.red);
		StyleConstants.setBackground(attributeSet, Color.blue);
		
		Document doc = pane.getStyledDocument();
		doc.insertString(doc.getLength(), "To java", attributeSet);
		
		attributeSet = new SimpleAttributeSet();
		doc.insertString(doc.getLength(), "World", attributeSet);
		
		JScrollPane scrollPane = new JScrollPane(pane);
		cp.add(scrollPane, BorderLayout.CENTER);
		
		frame.setSize(400,300);
		frame.setVisible(true);
	}
}
