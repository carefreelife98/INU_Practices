import java.util.*;

public class Comparators {
	
	public static final double error = 0.0000001;
	
	public static Comparator<Job> RMComparator(final int t, final Vector<Task> taskset) {
		return new Comparator<Job>() {

			public int compare(Job j1, Job j2) {
				int index1 = j1.TaskIndex;
				int index2 = j2.TaskIndex;
				
				Task task1 = taskset.get(index1);
				Task task2 = taskset.get(index2);							
				
				double period1 = task1.Period;
				double period2 = task2.Period;													 

				return (period1<period2 ? -1 : (period1>period2 ? 1:(index1 < index2 ? -1: 1)));			
				}
		};
	}
	//가장 짧은 Deadline 을 가진 작업이 가장 큰 우선순위를 가진다.
	// - 1. Deadline 에 가장 가까워진 작업부터 실행.
	// - 2. Deadline 이 동일한 경우에는 실행시간이 짧은 작업에 우선순위를 부여.
	// --> Deadline 까지의 남은 시간과 실행 시간으로 결정된다.
	// T: period(job이 생성되는 주기.)
	// C: executeTime(job의 실행시간)
	// D: Deadline

	//매 초 마다 갱신하며 Deadline 을 계산해야 한다. -> Simulator.java 의 Schedule 메소드가 구현해준다.
	public static Comparator<Job> EDFComparator() {
			return new Comparator<Job>() {

				//execTime = job 시작시간
				//releaseTime = job 끝나는 시간
				public int compare(Job j1, Job j2) {
					double dead1 = j1.Deadline;
					double dead2 = j2.Deadline;
					double actTime1 = j1.releaseTime - j1.execTime;
					double actTime2 = j2.releaseTime - j2.execTime;

					// -1,1 등이 반환되며 우선순위를 정하는 방식은 약속이기 때문에 그냥 외워야 한다.
					// 만약 우선순위가 같다면, 실행시간이 짧은 것에 Higher priority 를 준다.
					return (dead1 < dead2 ? -1 : (dead1 > dead2 ? 1:(actTime1 < actTime2 ? -1: 1)));
					}
			};
		}


	
	public static Comparator<Job> FIFOComparator() {
		return new Comparator<Job>() {

			public int compare(Job j1, Job j2) {				

				return -1;			
				}
		};
	}
}
