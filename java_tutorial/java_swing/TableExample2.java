import javax.swing.*;
import javax.swing.event.*;
public class TableExample2{
	public static void main(String args[]){
		JFrame f = new JFrame("Table Exaple");
		String data[][]={{"101","Amit","67000"} ,
		{"102","jai","78000"},{"101","Sachin","70000"}};
		String column[] = {"ID","NAME","Salary"};
		final JTable jt = new JTable(data,column);
		jt.setCellSelectionEnabled(true);
		ListSelectionModel select = jt.getSelectionModel();
		select.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		select.addListSelectionListener(new ListSelectionListener(){
			public void valueChanged(ListSelectionEvent e){
				String Data = null;
				int row[] = jt.getSelectedRows();
				int columns[] = jt.getSelectedColumns();
				for(int i=0;i<row.length;i++){
					for(int j=0;j<columns.length;j++){
						Data = (String)jt.getValueAt(row[i],columns[j]);
					}
				}
				System.out.println("Table element selected is: " + Data);
			}
		});
		JScrollPane sp = new JScrollPane(jt);
		f.add(sp);
		f.setSize(300,200);
		f.setVisible(true);
	}
	
}