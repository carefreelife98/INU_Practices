package HW_1;

public class HW_Check_1 {

    public static void main(String[] args) {

        //(1)
        System.out.println("예외가 발생할 소지가 있는 코드는 try 블록에 두는가, catch 블록에 두는가?: ");
        System.out.println("--> try 블록에 둡니다.");

        //(2-1) 지정한 배열의 크기를 넘겨 선언함
        // java.lang.ArrayIndexOutOfBoundsException
        try {
            int arr1[] = new int[3];
            arr1[4] = 5; //(1)

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("error = " + e);
        }

        //(2-2) String s 가 숫자로 쓰여진 String 이 아닌 문자열 Java 이기 때문에 error
        // java.lang.NumberFormatException
        try {
            String s = "Java";
            int n = Integer.parseInt(s);//(2)
        } catch (NumberFormatException e) {
            System.out.println("error = " + e);
        }

        //(2-3) int 형 배열 arr2 는 null 으로 지정되었으나 arr2[2] = 4 로 null 영역을 pointing 함.
        // java.lang.NullPointerException
        try {
            int arr2[] = null;
            arr2[2] = 4; //(3)
        } catch (NullPointerException e) {
            System.out.println("error = " + e);
        }
    }
}
