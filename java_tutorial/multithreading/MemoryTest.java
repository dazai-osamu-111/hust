public class MemoryTest{
	public static void main(String args[]) throws Exception{
		Runtime r = Runtime.getRuntime();
		System.out.println("Total memory: " + r.totalMemory());
		System.out.println("Free memory: " + r.freeMemory());
		
		for(int i=0;i<10000;i++){
			new MemoryTest();
		}
		
		System.out.println("After creating 10000 instance, free memory: " + r.freeMemory());
		System.gc();
		System.out.println("After gc(), free memory: " + r.freeMemory());
	}
}