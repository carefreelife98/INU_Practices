package _0418_interface;

public interface PhoneInterface {
    int TIMEOUT = 10000;
    void sendCall();
    void receiveCall();
    default void printLog() {
        System.out.println("**phone**");
    }
}

