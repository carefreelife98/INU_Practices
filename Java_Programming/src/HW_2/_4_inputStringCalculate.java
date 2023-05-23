package HW_2;

import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class _4_inputStringCalculate {
    /**
     * 실습 #4) 문자열 입력으로 계산 후 결과 출력
     * • 문자열 입력 예: “35+40-543-42+42-23”
     * • 입력되는 문자열은 매번 변경 가능
     * • 길이도 제한없음
     * • Vector<E>, StringTokenizer, Scanner 등 클래스 사용
     * • 연산은 덧셈과 뺄셈만 가능
     * • 앞에 있는 연산부터 순차적으로 진행
     * • 35++40과 같이 입력되면 프로그램 종료
     */

    public static int calc(String str) {
        Vector<String> num = tokensToVector(str);
        int sum = 0;

        if (error(num) == 0) {

            sum = Integer.parseInt(num.get(0));

            for (int i = 1; i < num.size(); i++) {

                switch (num.get(i)) {
                    case "+":
                        System.out.println("+ 연산 실행 : " + sum + "+" + Integer.parseInt(num.get(i + 1)));
                        sum = sum + Integer.parseInt(num.get(i + 1));
                        System.out.println("+ 결과: " + sum);
                        break;
                    case "-":
                        System.out.println("- 연산 실행 : " + sum + "-" + Integer.parseInt(num.get(i + 1)));
                        sum = sum - Integer.parseInt(num.get(i + 1));
                        System.out.println("- 결과: " + sum);
                        break;
                }
            }
        } else System.out.println("error code: " + error(num));
        return sum;
    }

    private static Vector<String> tokensToVector(String str) {
        // returnDelims: true로 하여 구분자인 "+", "-" 까지 token 으로 설정.
        StringTokenizer st = new StringTokenizer(str, "+-", true);
        Vector<String> num = new Vector<>();

        System.out.println("\n-----------------------");
        System.out.println("남아있는 Token의 개수: " + st.countTokens());

        while (st.hasMoreTokens()) {
            num.add(st.nextToken());
        }
        System.out.println(num);
        System.out.println("남은 토큰의 개수 = " + st.countTokens());
        System.out.println("-----------------------\n");
        return num;
    }

    private static int error(Vector<String> num) {

        int errorCode = 0;
        for (int i = 0; i < num.size(); i++) {

            if (num.get(0).equals("+") || num.get(0).equals("-")) {
                System.out.println("\n---------!!!ERROR!!!---------");
                System.out.println("연산자 우선 사용으로 종료합니다. " + num.get(0) + "\n");
                errorCode = 1;
                break;
            }
            else if (num.get(i).equals("+") && num.get(i).equals(num.get(i + 1))) {
                System.out.println("\n---------!!!ERROR!!!---------");
                System.out.println("연속된 연산자 사용으로 종료합니다. " + i + "번째 " + num.get(i) + " 와 " + (i + 1) + "번째 " + num.get(i + 1) + "\n");
                errorCode = 2;
                break;
            }
            else if (num.get(i).equals("-") && num.get(i).equals(num.get(i + 1))) {
                System.out.println("\n---------!!!ERROR!!!---------");
                System.out.println("연속된 연산자 사용으로 종료합니다. " + i + "번째" + num.get(i) + " 와 " + (i + 1) + "번째" + num.get(i + 1) + "\n");
                errorCode = 3;
                break;
            }
        }
        return errorCode;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        do {
            System.out.println("esc 입력 시 종료");

            System.out.println("실행할 연산이 포함된 문자열 입력: ");
            String str = scan.next();

            if (str.equals("esc")) {
                System.out.println("종료");
                break;
            }

            System.out.println("\n---------------------\n연산 결과 : " + calc(str));
            System.out.println("---------------------\n");
        }while(true);
    }
}
