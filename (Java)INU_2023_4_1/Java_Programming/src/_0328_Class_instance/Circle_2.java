package _0328_Class_instance;

public class Circle_2 {
    int radius;
    String name;

    public Circle_2(){
        radius = 1;
        name = "";
    }

    public Circle_2(int r, String n){
        radius = r;
        name = n;
    }

    public double getArea(){
        return 3.14 * radius * radius;
    }

    public static void main(String[] args) {
        Circle_2 pizza;
        pizza = new Circle_2(10, "자바 피자");
        pizza.name = "자바 피자";
        double area = pizza.getArea();
        System.out.println(pizza.name + " 의 면적은 " + area);

        Circle_2 donut = new Circle_2();
        donut.name = "도넛 피자";
        area = donut.getArea();
        System.out.println(donut.name + " 의 면적은 " + area);
    }

}
