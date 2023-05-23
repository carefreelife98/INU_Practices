package _0516_GUI;

import javax.swing.*;
import java.awt.*;
import java.util.zip.GZIPOutputStream;

public class JFrameEX {

    public static class MyFrame extends JFrame {
        // 생성자
        public MyFrame() {
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setTitle("300x300 스윙 프레임 만들기");
            setSize(300, 300); //프레임 크기 : 300x300
            setVisible(true);// 프레임 출력
        }
    }

    public static class ContentPaneEx extends JFrame {
        public ContentPaneEx() {
            setTitle("ContentPane 과 JFrame");

            //프레임의 x 버튼을 누르면 자동으로 응용 프로그램의 종료까지 시켜준다.
            //꼭 사용하자.
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            Container contentPane = getContentPane();
            contentPane.setBackground(Color.BLACK);
            contentPane.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));

            contentPane.add(new JButton("add"));
            contentPane.add(new JButton("sub"));
            contentPane.add(new JButton("mul"));
            contentPane.add(new JButton("div"));
            contentPane.add(new JButton("Calculate"));

            setSize(300, 200);

            setVisible(true);
        }

        public static void main(String[] args) {
            new ContentPaneEx(); // 익명 객체 생성
        }

    }


    public static void main(String[] args) {
        MyFrame frame = new MyFrame();
    }

    public static class GridLayoutEx extends JFrame {
        public GridLayoutEx() {
            setTitle("GrifLayout Sample");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


            GridLayout grid = new GridLayout(4, 2);
            grid.setVgap(5);

            Container c = getContentPane();
            c.setLayout(grid);
            c.add(new JLabel(" 이름"));
            c.add(new JTextField(""));
            c.add(new JLabel(" 학번"));
            c.add(new JTextField(""));
            c.add(new JLabel(" 학과"));
            c.add(new JTextField(""));
            c.add(new JLabel(" 과목"));
            c.add(new JTextField(""));
            setSize(300, 200);
            setVisible(true);
        }

        public static void main(String[] args) {
            new GridLayoutEx();
        }
    }

    public static class NullContainerEx extends JFrame {
        public NullContainerEx() {
            setTitle("NULL Container Sample");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            Container c = getContentPane();
            c.setLayout(null);

            JLabel la = new JLabel("Hello, Press Buttons!");
            la.setLocation(130, 50);
            la.setSize(200, 20);
            c.add(la);

            for (int i = 1; i <= 9; i++) {
                JButton b = new JButton(Integer.toString(i));
                b.setLocation(i * 15, i * 15);
                b.setSize(50, 20);
                c.add(b);
            }
            setSize(300, 200);
            setVisible(true);
        }

        public static void main(String[] args) {
            new NullContainerEx();
        }

    }


}
