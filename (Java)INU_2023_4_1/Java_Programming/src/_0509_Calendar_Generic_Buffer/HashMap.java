package _0509_Calendar_Generic_Buffer;

import java.util.Scanner;

class Student {
    int id;
    String tel;

    public Student(int id, String tel) {
        this.id = id;
        this.tel = tel;
    }

    public int getId() {
        return id;
    }

    public String getTel() {
        return tel;
    }
}

public class HashMap {
    public static void main(String[] args) {
        java.util.HashMap<String, Student> map = new java.util.HashMap<String, Student>();
        map.put("채승민", new Student(1, "010-2222-2222"));
        map.put("채소", new Student(2, "010-3333-3333"));
        map.put("야채", new Student(3, "010-4444-4444"));

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("검색할 이름?");
            String name = scanner.nextLine();
            if (name.equals("exit")) {
                break;
            }
            Student student = map.get(name);
            if (student == null) {
                System.out.println("은 없는 사람입니다.");
            } else {
                System.out.println("id: " + student.getId() + ",전화:" + student.getTel());
            }
        }
        scanner.close();
    }
}
