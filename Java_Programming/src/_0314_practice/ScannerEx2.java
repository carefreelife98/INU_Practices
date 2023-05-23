package _0314_practice;

import java.util.Scanner;

public class ScannerEx2 {
    public static void main(String[] args) {
        System.out.println("학번, 이름, 국어, 영어, 수학 ,과학 빈칸으로 분리하여 입력하세요");
        Scanner scanner = new Scanner(System.in);

        String num = scanner.next(); //문자열 읽기
        System.out.println("학번 = " + num + ",");

        String name = scanner.next();//문자열 읽기
        System.out.println("이름 = " + name + ",");

        double ko = scanner.nextDouble(); //정수읽기
        System.out.println("국어 = " + ko + ",");

        double en = scanner.nextDouble(); //실수 읽기
        System.out.println("영어 = " + en + ",");

        double math = scanner.nextDouble(); //논리값 읽기
        System.out.println("수학 = " + math + ",");

        double sc = scanner.nextDouble(); //정수읽기
        System.out.println("과학 = " + sc + ",");

        scanner.close(); //scanner 닫기

        System.out.println(num + name + "점수는: "+(ko + en + math + sc)/4 + "입니다");

    }
}