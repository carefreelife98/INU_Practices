import java.util.*;

public class Algorithm_EDF implements Scheduler {

    public Vector<Job> schedule(int t, int numberOfProcs, Vector<Job> readyQueue, Vector<Task> taskset) {

        //EDF 사용하여 활성화된 작업들의 List 를 정렬
        Comparator<Job> comp = Comparators.EDFComparator();
        Collections.sort(readyQueue, comp);

        return readyQueue;
    }
}
