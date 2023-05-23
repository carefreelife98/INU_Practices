package _0314_practice;


/**
 *
 * 시험 문제 출제 가능 유형
 *
 */


public class TypeConversion {
    public static void main(String[] args) {
        byte b = 127;
        int i = 100;

        System.out.println(b + i);
        System.out.println(10/4); // 정수 나누기 정수는 몫의 값인 정수가 나옴.
        System.out.println(10.0/4); // 하나라도 double 형이 있으면 double 로 변환되어 나옴.
        System.out.println((char)0x12340041); //char 이 2byte 이기 때문에 0041까지만 출력. 0041='A' 출력
        System.out.println((byte)(b+i));
        System.out.println((int)2.9 +1.8);
        System.out.println((int)(2.9+1.8));
        System.out.println((int)2.9 + (int)1.8);
    }
}
