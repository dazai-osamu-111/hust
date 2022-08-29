/*public class TestGarbage1{
	public void finalize(){
		System.out.println("Object is garbage collected");
	}
	
	public static void main(String args[]){
		TestGarbage1 g1 = new TestGarbage1();
		TestGarbage1 g2 = new TestGarbage1();
		
		g1 = null;
		g2 = null;
		
		System.gc();
	}
}*/

public class TestGarbage1{  
 public void finalize(){System.out.println("object is garbage collected");}  
 public static void main(String args[]){  
  TestGarbage1 s1=new TestGarbage1();  
  TestGarbage1 s2=new TestGarbage1();  
  s1=null;  
  s2=null;  
  System.gc();  
 }  
}  