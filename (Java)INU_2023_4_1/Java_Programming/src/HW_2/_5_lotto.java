package HW_2;

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class _5_lotto {

    /**
     * • 로또번호는 자연수 1~45에서 총 7개 숫자를 중복없이 생성
     * <p>
     * • 작업 순서
     * • 1) 숫자 6개를 랜덤으로 추출
     * • 2) 추출된 수는 오름차순 정렬
     * • 3) 마지막 보너스 숫자도 랜덤 추출 • 4) 전체 로또번호 출력
     * • Vector<E>와 같은 컬렉션 사용
     */

    // Vector -> String 변환
    public static StringBuilder sb(Vector<Integer> vec) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < vec.size(); i++) {
            if (i == vec.size() - 1) {
                sb.append("+ (Special Number) : ");
            }
            sb.append(vec.get(i));
            sb.append(" ");
        }
        return sb;
    }

    public static Vector<Integer> genNormalNum() {
        Vector<Integer> randVec = new Vector<>(6);

        // randVec 요소의 중복이 없을 때까지 반복
        int rand;
        for (int i = 0; i < randVec.capacity(); i++) {
            // rand = 1~45 까지의 난수 생성
            rand = (int) (Math.random() * 45 + 1);

            if (randVec.contains(rand)) {
//                System.out.println((i + 1) + "번째" + "중복 난수 발견!! : " + rand);
                i--;
                continue;
            }
            randVec.add(rand);
//            System.out.println("추가: " + rand);
        }
        // 오름차순 정렬
        Collections.sort(randVec);

        return randVec;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        do {
            System.out.println("ENTER 를 눌러 로또 번호를 생성: ");
            System.out.println("esc 입력 시 종료");

            if ("esc".equals(scan.nextLine())) {
                System.out.println("종료");
                break;
            }

            Vector<Integer> lotto = genNormalNum();

            System.out.println("로또 번호 생성기");
            System.out.println("앞자리 6개 : " + lotto);

            int special = (int) (Math.random() * 45 + 1);
            System.out.println("Special Number : " + special);

            System.out.println("이번 주 당첨 번호!");
            System.out.println("-----------------------------------------");
            lotto.add(special);
            System.out.println(sb(lotto));
            System.out.println("-----------------------------------------");
        }while(!"\n".equals(scan.nextLine()));
    }
}
