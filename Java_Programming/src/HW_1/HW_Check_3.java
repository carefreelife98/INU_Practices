package HW_1;

public class HW_Check_3 {

    static class Sample {
        int x; //instance 의 변수

        // int x 를 넘겨받아
        // Sample(instance)의 변수인 x(==this.x)에
        // = x 를 통해 x에 값을 넣어준다(세팅).
        public void setX(int x) {
            this.x = x;
            System.out.println("Sample.setX");
        }

        //리턴 데이터 타입이 int 이므로 int 값을 받아 int x 를 반환해준다.
        public int getX() {
            System.out.println("Sample.getX");
            return x;
        }

        // instance 가 될 class 와 이름이 같고
        // static, void / 리턴데이터 타입 지정이 되어있지 않다 --> 생성자.
        // int x를 받아 class(instance) 의 변수인 x에 삽입.
        public Sample(int x) {
            this.x = x;
        }

        public Sample() {
            setX(3);
            System.out.println("Sample.Sample");
        }

        public static void main(String[] args) {
            //static 참조 불가 --> class Sample 에 static 을 붙혀준다. --> static class Sample
            Sample a = new Sample();
            System.out.println("instance 생성: " + a);
            //new Sample() --> 기본 생성자 (default 값) 으로 이동하거나
            //new Sample(int 변수) 하여 전달해도 된다.
            //기본 생성자 new Sample() 을 만들고 setX 메소드를 사용하여 int x 값을 세팅해주었다.

            int n = a.getX();
            // 이후 x에 저장된 값을 class Sample 의 instance 인 a 에서 getX()메소드를 사용하여 꺼내 n에 저장한다.

            System.out.println("n = " + n);
            //n에 출력된 값(3) 을 볼 수 있다.
        }
    }
}
