import java.awt.*;
class MenuExample{
	MenuExample(){
		Frame f = new Frame("Menu and MenuIten Example");
		MenuBar mb = new MenuBar();
		Menu menu = new Menu("Menu");
		Menu submenu = new Menu("Sub Menu");
		MenuItem i1 = new MenuItem("item 1");
		MenuItem i2 = new MenuItem("item 2");
		MenuItem i3 = new MenuItem("item 3");
		MenuItem i4 = new MenuItem("item 4");
		MenuItem i5 = new MenuItem("item 5");
		menu.add(i1);
		menu.add(i2);
		menu.add(i3);
		submenu.add(i4);
		submenu.add(i5);
		menu.add(submenu);
		mb.add(menu);
		f.setMenuBar(mb);
		f.setSize(400,400);
		f.setLayout(null);
		f.setVisible(true);
	}
	
	public static void main(String args[]){
		new MenuExample();
	}
}