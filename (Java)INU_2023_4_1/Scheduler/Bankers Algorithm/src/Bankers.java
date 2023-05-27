import java.util.Scanner;

public class Bankers {
	private int need[][],allocate[][],max[][],avail[],numP,numR;

	private void input()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("201702797 Seungmin Chae");
		System.out.print("Enter no. of processes and resources : ");
		numP=sc.nextInt();  //# of process
		numR=sc.nextInt();  //# of resources
		need=new int[numP][numR];  //initializing arrays
		max=new int[numP][numR];
		allocate=new int[numP][numR];
		avail=new int[numR];

		System.out.println("Enter allocation matrix -->");
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)
				allocate[i][j]=sc.nextInt();  //allocation matrix 3(process) X 3(resources) 이면 9개 직접 입력 - 띄어쓰기 구분.

		System.out.println("Enter max matrix -->");
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)
				max[i][j]=sc.nextInt();  //max matrix

		System.out.println("Enter available matrix -->");
		for(int j=0;j<numR;j++)
			avail[j]=sc.nextInt();  //available matrix

		sc.close();
	}

	private int[][] calc_need(){
		for(int i=0;i<numP;i++)
			for(int j=0;j<numR;j++)  //calculating need matrix
				need[i][j]=max[i][j]-allocate[i][j];

		return need;
	}

	private boolean check(int i){
		//checking if all resources for ith process can be allocated
		// i = 프로세스
		// i 번째 프로세스를 파라미터로 넣어주면 해당 프로세스가 현재 execute 실행 후 끝마칠 수 있는지 check.
		for(int j=0;j<numR;j++) 
			if(avail[j]<need[i][j])
				return false;

		return true;
	}

	public void isSafe(){
		input();
		calc_need();

		// 프로세스 별 참, 거짓 값이 담겨 있는 boolean 배열 생성.
		boolean done[] = new boolean[numP];
		int j = 0;

		//프로세스 수만큼 실행
		while (j < numP) {
			boolean allocated = false;

			//프로세스 수만큼 check 후 만약 allocate 가능한 process[i] 가 있었다면 avail 의 크기가 for 문에서 늘어남.
			//아래 for 문에서 늘어난 avail 을 가지고 전체 프로세스의 allocate 가능 여부를 while 문에서 한번 더 탐색.
			for (int i = 0; i < numP; i++) {
				/** allocated : 현재 할당돤 리소스
				 * max : execution 을 끝마치기 위해 필요한 리소스의 수
				 * need : 현재 리소스(allocated)에서 max가 되기 위해 필요한 리소스의 수.
				 * avail : 현재 할당 가능하여 대기중인 리소스.
				*/
				// done[i] 에서 해당 process[i] 가 이미 allocate 되었는지 확인.
				// allocate 되었다면 done[i] 는 true 일 것.
				// check 했을 시 true 반환 = allocate 가능
				if (!done[i] && check(i)) {
					// allocated 를 true 로 바꿔주고
					allocated = true;
					// done[i]에 기록.
					done[i] = allocated;
					// avail - need 에 process[i] 의 max 를 더해줘 리소스를 반환한다. (avail = avail - need + max)
					System.out.print("\nprocess " + i + " 리소스 반환 전 avail = ");
					for (int a = 0; a < numR; a++) {
						System.out.print(avail[a] + " ");
					}
					for (int r = 0; r < numR; r++) {
						avail[r] = avail[r] - need[i][r] + max[i][r];
					}
					System.out.print("\nprocess " + i + " 리소스 반환 후 avail = ");
					for (int a = 0; a < numR; a++) {
						System.out.print(avail[a] + " ");
					}
					System.out.println("\n--------------------------");
					System.out.println("Allocated process : " + i);
					System.out.println("--------------------------");
				}
				//allocate 불가능 하다면 다음 프로세스 탐색.

			}
			// j+1 까지(while문 끝까지) 반복했으나 done[] 에 false가 하나라도 있을때
			// 하나라도 false 이면 break(safety execution 실패).
			if (j+1 == numP) {
				boolean a = true;
				for (boolean i : done) {
					if (i == false) {
						a = false;
						System.out.println("done" + "[" + j + "]" + " = " + done[j]);
						System.out.println("allocated 되지 않은 프로세스 발견 : process " + j);
					}
				}
				if (a == false){
					System.out.println("종료");
					break;
				}
			}
			j++;
		}
		// 프로세스 수만큼의 while문이 break 되지 않고 끝나면, safety.
		if (j == numP) {
			System.out.println("---------------------");
			System.out.println("Safely allocated");
			System.out.println("---------------------");
		} else {
			System.out.println("------------------!!!------------------");
			System.out.println("All process cant be allocated safely");
			System.out.println("------------------!!!------------------");
		}
	}

	public static void main(String[] args) {
		new Bankers().isSafe();

	}

}
