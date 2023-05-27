import java.util.*;

public interface Scheduler {
	public Vector<Job> schedule(int t, int numberOfProcs, Vector<Job> readyQueue, Vector<Task> taskset);
}