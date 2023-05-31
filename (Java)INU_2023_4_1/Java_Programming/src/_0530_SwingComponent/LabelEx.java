package _0530_SwingComponent;

import javax.swing.*;
import java.awt.*;

public class LabelEx extends JFrame {
    public LabelEx() {
        setTitle("레이블 예");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        JLabel textLable = new JLabel("사랑합니다 .");

        ImageIcon beauty = new ImageIcon("/Users/carefreelife/Desktop/인천대학교/2023_4학년_1학기/Java_Programming/Java_PPT/ch11_images/ex11-2/beauty.jpg");
        JLabel imageLabel = new JLabel(beauty);

        ImageIcon normalIcon = new ImageIcon("/Users/carefreelife/Desktop/인천대학교/2023_4학년_1학기/Java_Programming/Java_PPT/ch11_images/ex11-2/normalIcon.gif");

        JLabel label = new JLabel("보고싶으면 전화 하세요 ", normalIcon, SwingConstants.CENTER);

        c.add(textLable);
        c.add(imageLabel);
        c.add(label);

        setSize(400, 600);
        setVisible(true);
    }
    public static void main(String[] args) {
        new LabelEx();
    }
}
