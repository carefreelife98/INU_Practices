package _0314_practice;

public class BitOperator {
    public static void main(String[] args) {
        short a = (short) 0x55ff;
        short b = (short) 0x00ff;

        System.out.println("[비트 연산 결과]");
        System.out.printf("%04x\n", (short) (a & b)); //비트 AND
        System.out.printf("%04x\n", (short) (a | b)); //비트 OR
        System.out.printf("%04x\n", (short) (a ^ b)); //비트 XOR
        System.out.printf("%04x\n", (short) (~a)); //비트 NOT

        byte c = 20; //0x14
        byte d = -8; //0xf8

        //비트 시프트 연산
        System.out.println("[시프트 연산 결과]");
        System.out.println(c<<2);
        System.out.println(c>>2);
        System.out.println(d>>2);
        System.out.printf("%x\n",(d>>2));
    }
}
