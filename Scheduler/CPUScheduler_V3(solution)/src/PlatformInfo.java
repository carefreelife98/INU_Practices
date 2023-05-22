import java.util.Vector;

public class PlatformInfo {

	public double util;
	public double den; 
	public int taskSetNumber;
	public int scheduler;
	public int numProcessor;
	public int numTask;
	public Scheduler algorithm;
	public Vector<Job> readyQueue = new Vector<Job>();
	public Vector<Task> tasks = new Vector<Task>();
	public Vector<Double> latestReleaseTime =  new Vector<Double>();
	public double startTime=0,endTime=0;
	
	public PlatformInfo() {	}

}
