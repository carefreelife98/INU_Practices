package _0321_If_For_Array;

public class For {
    public static void main(String[] args) {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i;
            System.out.println(i);

            if (i <= 9) {
                System.out.println("+");
            }else {
                System.out.println("sum = " + sum);
            }
        }

    }
}
