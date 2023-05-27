
public class Task {

	public double Period;
	public double execTime;
	public double Deadline;		
		
	public Task(double period, double exectime, double deadline){
		this.Period = period;
		this.execTime = exectime;
		this.Deadline = deadline;		
	}
	
	public Task(Task task){		
		this.Period = task.Period;
		this.execTime = task.execTime;
		this.Deadline = task.Deadline;		
	}
}