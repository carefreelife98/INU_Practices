package HW_1;

import java.util.Scanner;

public class Practice_1 {

    public static void main(String[] args) {
        System.out.println("5칙 연산 프로그램을 시작합니다: '=' 입력 시 종료합니다.");
        Scanner scan = new Scanner(System.in); // 스캐너
        String end = "";
        String tool = "";
        long i, j, rs = 0L; //변수 초기화
        while (true) {

            try {
                System.out.println("첫번째 정수 : ");
                end = scan.next();  // = 인지 구분하기 위해 일단 str로 입력
                if (end.equals("=")) { //첫번째 입력에 = 입력시 종료
                    break;
                } else {
                    i = Long.parseLong(end); // 첫 입력이 = 이 아니라면 str 입력을 Long으로 재변환

                    System.out.println("연산 기호 : ");
                    tool = scan.next();

                    System.out.println("두번째 정수 : ");
                    j = scan.nextLong();

                    if (tool.equals("+")) {
                        rs = i + j;
                    } else if (tool.equals("-")) {
                        rs = i - j;
                    } else if (tool.equals("*")) {
                        rs = i * j;
                    } else if (tool.equals("/")) {
                        try {
                            rs = i / j;
                        } catch (ArithmeticException e) {
                            System.out.println("error = " + e); //ArithmeticException 예외처리
                        }

                    } else if (tool.equals("%")) {
                        rs = i % j;
                    }
                    System.out.println("결과: " + rs);
                }
            } catch (NumberFormatException e) {     // NumberFormatException 예외처리
                System.out.println("error = " + e);
            }
        }
        System.out.println(" '=' 이 입력되었습니다 - 5칙 연산 프로그램 종료.");
    }
}
