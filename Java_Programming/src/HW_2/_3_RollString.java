package HW_2;

import java.util.LinkedList;
import java.util.Scanner;

public class _3_RollString {

    public static StringBuilder sb = new StringBuilder();

    // 연결리스트를 구분자 없는 String 으로 변환
    public static String TempAsString(LinkedList<Character> temp) {
        for (Character i : temp) {
            sb.append(i);
        }
        String tempAsString = sb.toString();
        return tempAsString;
    }

    public static void roll(String str, int n) {
        // n 값으로 0 입력시 바로 종료.
        if (n == 0) {
            System.out.println("종료함");
            return;
        }

        LinkedList<Character> list = getCharacters(str);
        LinkedList<Character> temp = (LinkedList<Character>) list.clone();

        System.out.println("초기 문자열 : " + list);
        int num = 0;

        // 입력된 정수 n 이 문자열 길이와 나누어 떨어지면 회전 중 초기 리스트와 같아지는 순간 회전 종료.
        if (str.length() % n == 0) {
            // n 이 양수인 경우.
            if (n > 0) {
                do {
                    num = rollingIfPositive(str, n, temp, num);
                } while (temp.getFirst() != list.getFirst());
            }
            // n이 음수인 경우. (n = 0 인 경우는 함수 초반에 미리 제외)
            else {
                do {
                    num = rollingIfNegative(str, n, temp, num);
                } while (temp.getFirst() != list.getFirst());
            }
            System.out.println(n + "이 문자열의 길이와 나누어 떨어지므로 처음과 같은 문자열 생성시 종료");
        }
        // 문자열의 길이가 n으로 나누어 떨어지지 않을 때
        else {
            // n 이 양수인 경우.
            if (n > 0) {
                // 다음 이동할 list(char) 범위에 초기 리스트의 첫번째 요소가 존재하면 종료
                boolean eval = true;
                int gen = 0;
                while(eval) {
                    if (num > 1) {
                        for (int i = 0; i < n; i++) {
                            if (temp.get(i) == list.get(0)) {
                                gen = i;
                                eval = false;
                                break;
                            }
                        }
                    }
                    if (eval == false) {
                        break;
                    }
                    num = rollingIfPositive(str, n, temp, num);
                }
                System.out.println("한번 더 회전시 " + "'" + temp.get(gen) + "'" + " 이(가) |" + n + "| 범위의 list 뒤 쪽으로 가기에 종료");
            }
            // n이 음수인 경우. (n = 0 인 경우는 함수 초반에 미리 제외)
            else {
                do {
                    num = rollingIfNegative(str, n, temp, num);
                } while (temp.get(temp.size() - (str.length() % n)) != list.getFirst());
                System.out.println("한번 더 회전시 " + "'" + temp.get(temp.size() - (str.length() % n)) + "'" + " 이(가) |" + n + "| 범위의 list 앞 쪽으로 오기에 종료");
            }
        }
    }

    private static int rollingIfNegative(String str, int n, LinkedList<Character> temp, int num) {
        num++;
        System.out.println(num + "번째 회전");
        System.out.println("<중간 과정>");
        // n 만큼 삭제 후 연결리스트의 뒤에 삽입
        for (int i = n; i < 0; i++) {
            temp.addFirst(temp.removeLast());
            System.out.println("remove last & add first = " + temp);
        }
        System.out.println("</중간 과정>");
        System.out.println(num + "번째 회전 끝: " + TempAsString(temp));
        // sb 초기화
        sb.delete(0, str.length());
        System.out.println("--------------------------------");
        return num;
    }

    private static int rollingIfPositive(String str, int n, LinkedList<Character> temp, int num) {
        num++;
        System.out.println("\n--------------------------------");
        System.out.println(num + "번째 회전");
        System.out.println("<중간 과정>");
        // n 만큼 삭제 후 연결리스트의 뒤에 삽입
        for (int i = 0; i < n; i++) {
            temp.add(temp.removeFirst());
            System.out.println("remove first & add last = " + temp);
        }
        System.out.println("</중간 과정>");
        System.out.println(num + "번째 회전 끝: " + TempAsString(temp));
        // sb 초기화
        sb.delete(0, str.length());
        System.out.println("--------------------------------\n");
        return num;
    }

    private static LinkedList<Character> getCharacters(String str) {
        LinkedList<Character> list = new LinkedList<>();

        // string을 list 에 char 형으로 삽입
        for (int i = 0; i < str.length(); i++) {
            list.add(str.charAt(i));
        }
        return list;
    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        System.out.println("문자열 입력 : ");
        String str = scan.next();

        System.out.println("문자열의 길이와 같거나 작은 정수 입력 : ");
        int n = scan.nextInt();
        roll(str, n);
    }
}
