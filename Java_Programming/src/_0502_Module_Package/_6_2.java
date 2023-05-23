package _0502_Module_Package;

public class _6_2 {
    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            Point p = (Point) obj;
            if (x == p.x && y == p.y) {
                return true;
            } else {
                return false;
            }
        }

        public String toString() {
            return "Point("+ x + ","+ y +")";
        }
    }

    public class EqualsEx {
        public static void main(String[] args) {
            Point a = new Point(2, 3);
            Point b = new Point(2, 3);
//            Point c = a;

            Point c = new Point(3, 4);

            if (a == b) {
                System.out.println("a==b");
            }
            if (a.equals(b)) {
                System.out.println("a==b");
            }
            if (a.equals(c)) {
                System.out.println("a is equal to c");
            }
        }
    }

    public class ToStringEx {
        public static void main(String[] args) {
            Point p = new Point(2, 3);
            System.out.println(p.toString());
            System.out.println(p);
            System.out.println(p + "입니다.");
        }

    }
}
