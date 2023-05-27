package _0321_If_For_Array;

import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args) {
        /**
         * -1이 입력되기 전까지 정수를 입력받는다.
         * 정수가 짝수 이면 값 출력하고, 카운트계산
         * -1을 입력하면 정수 개수 출력
         */

        int i = 0;
        int count = 0;

        Scanner scanner = new Scanner(System.in);
        while (i!=-1) {
            i = scanner.nextInt();
            if (i % 2 == 0) {
                System.out.println("짝수 값 출력" + i);
                count++;
            }
        }
        System.out.println("짝수인 정수의 개수 = " + count);

        scanner.close();
    }
}
