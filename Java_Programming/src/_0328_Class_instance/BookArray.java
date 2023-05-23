package _0328_Class_instance;

import java.util.Scanner;

class Book1 {
    String title, author;

    public Book1(String title, String author) {
        this.title = title;
        this.author = author;
    }
}

public class BookArray {
    public static void main(String[] args) {
        Book[] book = new Book[2];

        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < book.length; i++) {
            System.out.println("제목>>>");
            String title = scanner.nextLine();
            System.out.println("저자>>>");
            String author = scanner.nextLine();
            book[i] = new Book(title, author);
        }

        for (int i = 0; i < book.length; i++) {
            System.out.println("(" + book[i].title + "," + book[i].author + ")");
        }
        scanner.close();
    }
}
