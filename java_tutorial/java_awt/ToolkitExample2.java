
 
import java.awt.Button;
import java.awt.Frame;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
public class ToolkitExample2 {
    public static void main(String[] args) {
        Frame frame = new Frame("Ví dụ Toolkit trong Java AWT");
        Button button = new Button("beep");
        button.setBounds(50, 100, 60, 30);
        frame.add(button);
        frame.setSize(400, 300);
        frame.setLayout(null);
        frame.setVisible(true);
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Toolkit.getDefaultToolkit().beep();
            }
        });
    }
}