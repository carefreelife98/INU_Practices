package _0418_interface;

public class SmartPhone extends PDA implements MobilePhoneInterface, MP3Interface {
    @Override
    public void sendCall() {
        System.out.println("따르릉따르릉~");

    }

    @Override
    public void receiveCall() {
        System.out.println("전화 왔어요~~");
    }

    @Override
    public void sendSMS() {
        System.out.println("문자 갑니다~~");
    }

    @Override
    public void receiveSMS() {
        System.out.println("문자 왔어욧");
    }

    @Override
    public void play() {
        System.out.println("음악 재생합니다!!");
    }

    @Override
    public void stop() {
        System.out.println("음악 중단합니다!!!");
    }
    public void schedule() {
        System.out.println("일정 관리 합니다.");
    }
}
