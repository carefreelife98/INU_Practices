package _0321_If_For_Array;

import java.util.Scanner;

public class While {
    public static void main(String[] args) {
        int count = 0;
        int sum = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.println("정수를 입력하고 마지막에 -1을 입력하세요.");

        int n = scanner.nextInt();
        while (n != -1) {
            sum += n;
            count++;
            n = scanner.nextInt();
        }
        if (count == 0) {
            System.out.println("입력된 수가 없습니다.");
        } else {
            System.out.println("정수의 개수는 " + count + " 개이며");
            System.out.println("평균은 " + (double) sum / count + "입니다.");
        }
        scanner.close();

    }
}
