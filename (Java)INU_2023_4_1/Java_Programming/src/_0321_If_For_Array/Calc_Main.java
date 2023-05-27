package _0321_If_For_Array;

public class Calc_Main {
    public static void main(String[] args) {
        double sum = 0.0;

        for (int i = 0; i < args.length; i++) {
            sum += Double.parseDouble(args[i]);
        }
        System.out.println("합계 = " + sum);
    }
}

/**
 * edit configuration 가서 값을 넣어주고 실행시켜야 동작.
 */
