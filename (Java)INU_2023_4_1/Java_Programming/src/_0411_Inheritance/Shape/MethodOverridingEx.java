package _0411_Inheritance.Shape;

public class MethodOverridingEx {
    static void paint(Shape p) {
        p.draw();
    }

    public static void main(String[] args) {
        Shape start,last,obj;
        //링크드 리스트로 도형 생성하여 연결
        start = new Line(); // Line객체 연결
        last = start;
        obj = new Rect();
        last.next = obj;
        last = obj;
        obj = new Line();
        last.next = obj;
        last = obj;
        obj = new Circle();
        last.next = obj;
        last = obj;

        Shape p = start;
        while (p != null) {
            p.draw();
            p = p.next;
        }
    }
}
