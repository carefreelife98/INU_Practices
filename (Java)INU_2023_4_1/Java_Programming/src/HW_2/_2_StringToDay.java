package HW_2;

import java.util.Calendar;
import java.util.Scanner;

public class _2_StringToDay {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        Calendar cal = Calendar.getInstance();

        while(true) {
            System.out.println("날짜 입력 (ex. 2023/05/10 ) : ");
            String str = scan.next();

            if (str.equals("exit")) {
                System.out.println("exit");
                break;
            } else {
                String[] split = str.split("/");
                cal.set(Calendar.YEAR, Integer.parseInt(split[0]));
                cal.set(Calendar.MONTH, Integer.parseInt(split[1]));
                cal.set(Calendar.DAY_OF_MONTH, Integer.parseInt(split[2]));
            }
            System.out.println("[data] 년도 : " + cal.get(Calendar.YEAR));
            System.out.println("[data] 월 : " + cal.get(Calendar.MONTH));
            System.out.println("[data] 일 : " + cal.get(Calendar.DAY_OF_MONTH));
        }
    }
}
