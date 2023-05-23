package HW_1;

import java.util.Scanner;

public class Song {
    String title;
    String artist;
    int year;
    String country;

    //기본 생성자
    public Song() {
    }

    //매개변수 있는 생성자
    public Song(String title, String artist, int year, String country) {
        this.title = title;
        this.artist = artist;
        this.year = year;
        this.country = country;
    }

    public static void main(String[] args) {
        Song song = new Song(); // 기본 생성자 호출 --> default 값.
        System.out.println("노래제목, 가수, 발표년도, 국적 순서로 입력해주세요: ");
        Scanner sc = new Scanner(System.in);
        song.title = sc.next();
        song.artist = sc.next();
        song.year = sc.nextInt();
        song.country = sc.next();
        song.show();
    }

    public void show() {
        System.out.println(getClass().getSimpleName() + " 정보: " + year + ", " + country + " 국적의 " + artist + "가 부른 " + "''" + title + "''");
    }
}
