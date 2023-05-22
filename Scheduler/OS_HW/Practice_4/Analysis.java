import java.util.Arrays;


public class Analysis {

	public PlatformInfo pInfo;

	public static void main(String[] args) {

	}

	public String run(PlatformInfo p) {

		pInfo = p;
		int schedulable = 0;

		switch (p.scheduler) {
			case 1000:    //utilization bound for RM
				schedulable = UBTestforRM();
				break;

			case 1001:    //utilization bound for EDF
				schedulable = UBTestforEDF();
				break;

			case 1002:    //RTA for Rm
				schedulable = RTATestforRM_Uni();
				break;

		}


		String result = schedulable + " " + pInfo.numTask;

		return result;
	}


	public int UBTestforRM() {
		//task 다더한거 n은 task 개수.
		//exectime/period <=
		double Usys = 0;
		for (int i = 0; i < pInfo.tasks.size(); i++) {
			Usys += pInfo.tasks.get(i).execTime / pInfo.tasks.get(i).Period;
		}
		if (Usys <= pInfo.tasks.size() * (Math.pow(2, 1.0 / pInfo.tasks.size()) - 1)) {
			return 1;
		} else {
			return 0;
		}
	}

	public int UBTestforEDF() {
		double Usys = 0;
		for (int i = 0; i < pInfo.tasks.size(); i++) {
			Usys += pInfo.tasks.get(i).execTime / pInfo.tasks.get(i).Period;
		}
		if (Usys <= 1.0) {
			return 1;
		} else {
			return 0;
		}
	}

	public int RTATestforRM_Uni() {
		//이중 루프 + while 문 하나.
		//taskSet 에 포함되어 있는 task 의 개수 만큼 돌린다.
		for(int k = 0; k<pInfo.tasks.size(); k++) {
			//tasks vector 에서 첫번째 task 부터 꺼낸다. == task_k
			//두번째 task 를 꺼낸다
			Task task_k = pInfo.tasks.get(k);

			//interval 은 꺼낸 task 의 exectime.(시작시간?)
			//두번째 task_k의 exectime 을 꺼낸다 == interval
			double interval = task_k.execTime;

			//task_k 의 시작시간이 task_k 의 deadline 보다 작거나 같을때까지 돌린다.
			while (interval <= task_k.Deadline) {

				//sum 에 task 의 시작시간을 더해놓는다.
				//두번째 sum : 첫번쨰 + 두번째 시작시간
				double sum = task_k.execTime;

				//taskSet 에 포함되어 있는 task 의 개수 만큼 돌린다.
				for (int i = 0; i < pInfo.tasks.size(); i++) {
					//같은 taskset 두개를 놓고 taskset 에서 k 번째에 있는 task_k 와 그전까지의 task_i를 사용
					//두번째: k 가 i 보다 1회 높다.
					//i < k 일때, task_k 이전까지의 task_i 를 하나씩 꺼내어 아래를 실행.
					//그리고 (task_i의 시작시간 X 올림(task_K의 시작시간 / task_i의 주기)) 를 sum 에 더한다. //ceil(올림함수) ex. 1.2 => 2
					// 이해하려 하지 말고 외우자.
					if (i < k) {
						Task task_i = pInfo.tasks.get(i);
						sum += task_i.execTime * (Math.ceil(interval / task_i.Period));
					}
				}
				// 첫번째 실행시 sum == interval 이므로 break;
				if (sum <= interval) {
					break;
				}
				interval = sum;
			}
			//if interval > task_k.Deadline -> deadline miss -> return 0;
			//else if no deadline miss guarantee for the target task_k -> continue;{
			//}
			if (interval > task_k.Deadline)
				return 0;
			else if (interval <= task_k.Deadline) {
				continue;
			}
		}
		return 1;
	}
}