package _0509_Calendar_Generic_Buffer;

import java.util.Iterator;
import java.util.Vector;

public class IteratorVectorEx {
    public static void main(String[] args) {
        Vector<Integer> v = new Vector<Integer>();

        for (int i = 0; i < 10; i++) {
            int rand = (int)(Math.random() * 100 + 1);
            v.add(rand);
        }
        System.out.println(v);
        Iterator<Integer> iter = v.iterator();
        while (iter.hasNext()) {
            int n = iter.next();
            System.out.println(n);
        }
        int sum = 0;
        iter = v.iterator();
        while (iter.hasNext()) {
            int n = iter.next();
            sum += n;
        }
        System.out.println("벡터에 있는 정수 합: " + sum);
    }
}
