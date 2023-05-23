package HW_1;

public class HW_Check_2 {
    static class Sample {
        int id;

        public Sample(int x) {
            this.id = x;
        }

        //void 가 들어가 있으면 안된다. 생성자에는 static, 리턴 데이터 타입 등을 제외하고 선언한다.
        public /*void*/ Sample() {
            this(0); //생성자가 첫번째 문장이 아니었기 때문에 컴파일 오류. 첫번째 문장으로 바꿔 주었다.
            System.out.println("생성자 호출");
            // System.out.println("생성자 호출"); 문장과 this(0); 문장의 순서를 바꾸어 주어야 한다.
        }
    }

    public static void main(String[] args) {
        Sample sample = new Sample(); // 1. new Sample 에 아무 파라미터도 넘기지 않으면 기본 default 값인 Sample() 이 호출된다.
        // 2. Sample()는 this(0) 을 통해 int 형 파라미터 하나를 받는 또다른 생성자 Sample(int x)를 호출하고 x에 숫자 0이 삽입된다.(int x = 0)
        // 3. Sample(int x)는 this.id 를 통해 인스턴스화 된 class Sample 의 변수인 id를 카리키고,
        // 이전에 파라미터로 넘어와 x에 담겨져 있는 0을 id 에 담는다.

        System.out.println("sample.id = " + sample.id);
        //sample.id 를 출력해보면 id = 0 인것을 알 수 있다.
    }
}
