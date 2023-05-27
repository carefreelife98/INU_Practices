import java.util.*;

public class Algorithm_RM implements Scheduler{

// Takes active jobs, current time, and task densities as input and returns indices of tasks that need to be scheduled at current time.
public Vector<Job> schedule(int t, int numberOfProcs, Vector<Job> readyQueue, Vector<Task> taskset){

	// Sort the list of active jobs based on RM
	Comparator<Job> comp = Comparators.RMComparator(taskset);
	Collections.sort(readyQueue, comp);

	return readyQueue;
}
}