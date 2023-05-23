package _0321_If_For_Array;

public class DoWhile {
//    public static void main(String[] args) {
//        int i = 1;
//        int rs = 0;
//
//        Scanner scanner = new Scanner(System.in);
//        System.out.println("몇 단 부터? : ");
//        int num = scanner.nextInt();
//        int fs = num;
//
//        for (; num < 10; num++) {
//            do {
//                rs = num * i;
//                System.out.print(num + "X" + i + "=" + rs + ",");
//                i++;
//            } while (i < 10);
//            num=fs;
//        }
//        System.out.println("구구단 끝!");
//        scanner.close();
//    }

    /**
     * 실패;;
     *
     */

    public static void main(String[] args) {
        for(int i=1; i<10; i++) { // 1단에서 9단
            for (int j = 1; j < 10; j++) { // 각 단의 구구셈 출력
                System.out.print(i + "*" + j + "=" + i * j); // 구구셈 출력
                System.out.print('\t'); // 하나씩 탭으로 띄기 }
                System.out.println(); // 한 단이 끝나면 다음 줄로 커서 이동 }
            }

        }
    }
}
