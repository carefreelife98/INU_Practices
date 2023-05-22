import java.util.*;


public class Job {

	public double execTime;
	public double releaseTime;
	public double Deadline;
	public int TaskIndex;

	public Job(double exectime, double releaseTime, double deadline, int taskIndex){

		this.execTime = exectime;
		this.releaseTime = releaseTime;
		this.Deadline = deadline;
		this.TaskIndex = taskIndex;
	}
}