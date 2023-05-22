public class Analysis {
    public PlatformInfo pInfo;

    public static void main(String[] args) {

    }

    public String run(PlatformInfo p) {

        pInfo = p;
        int schedulable = 0; //schedule 할 수 있는지 없는지 0/1 반환? 소수로 반환?

        //platforminfo 의 int 형 scheduler의 값
        switch (p.scheduler) {
            case 1000: //에 1000이 들어가면 schedulable 에 RM 전달
                schedulable = UBTestforRM();
                break;

            case 1001: //에 1001이 들어가면 schedulable 에 EDF 전달
                schedulable = UBTestforEDF();
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
            Usys += pInfo.tasks.get(i).execTime/pInfo.tasks.get(i).Period;
        }
        if (Usys < pInfo.tasks.size() * (Math.pow(2, 1.0 / pInfo.tasks.size()) - 1)) {
            return 1;
        } else {
            return 0;
        }
    }

    public int UBTestforEDF() {

    }
}
