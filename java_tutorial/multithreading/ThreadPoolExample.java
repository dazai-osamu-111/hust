public class TestThreadPool{
	public static void main(String args[]){
		// creating a pool of 5 thread
		ExecutorService executor  = Executors.newFixedThreadPool(5);
		for(int i=0;i<10;i++){
			Runnable worker = new WorkerThread("" + i);
			executor.execute(worker); // calling execute method of ExecutorService
		}
		executor.shutdown();
		while(!executor.isTerminated()){}
		System.out.println("Finished all threads");
	}
}