package _0418_interface;

public class SamsungPhone implements PhoneInterface{
    public void sendCall() {
        System.out.println("띠리리링");
    }

    @Override
    public void receiveCall() {
        System.out.println("전화가 왔습니다.");
    }

    public void flash() {
        System.out.println("전화기에 불이 켜졌습니다.");
    }
}
