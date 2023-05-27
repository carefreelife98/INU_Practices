package _0314_practice;

import java.util.Scanner;

public class ScannerEx {
    public static void main(String[] args) {
        System.out.println("이름, 도시, 나이, 체중, 독신 여부를 빈칸으로 분리하여 입력하세요");
        Scanner scanner = new Scanner(System.in);

        String name = scanner.next(); //문자열 읽기
        System.out.println("name = " + name + ",");

        String city = scanner.next();//문자열 읽기
        System.out.println("city = " + city + ",");

        int age = scanner.nextInt(); //정수읽기
        System.out.println("age = " + age + ",");

        double weight = scanner.nextDouble(); //실수 읽기
        System.out.println("weight = " + weight + ",");

        boolean single = scanner.hasNextBoolean(); //논리값 읽기
        System.out.println("single = " + single + "입니다");

        scanner.close(); //scanner 닫기
    }
}
