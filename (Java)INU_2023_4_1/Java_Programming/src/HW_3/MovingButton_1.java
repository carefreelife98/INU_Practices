package HW_3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MovingButton_1 extends JFrame {
    private final int MY_BUTTON = 10;
    private final int MAX = 500;
    private JButton jb = new JButton();

    public MovingButton_1() {
        setTitle("Moving Button");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null);
        c.setBackground(Color.DARK_GRAY);
        c.addKeyListener(new movingKeyListener());

        jb.setText("상,하,좌,우 키를 사용하여 움직여보세요!");
        jb.setLocation(0, 0);
        jb.setSize(400, 50);
        c.add(jb);

        setSize(MAX * 2, MAX * 2);
        setVisible(true);
        c.setFocusable(true);
        c.requestFocus(); // 강제 포커스 부여.
    }

    class movingKeyListener extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {

            int keyCode = e.getKeyCode();

            switch (keyCode) {
                case KeyEvent.VK_UP:
                    if (jb.getY() - MY_BUTTON >= 0) {
                        jb.setLocation(jb.getX(), jb.getY() - MY_BUTTON);
                        jb.setText(MAX + " X " + MAX + "범위 내 이동 가능 / 단위: " + MY_BUTTON + " 현재 X: " + jb.getX() + " Y:" + jb.getY());
                    }break;
                case KeyEvent.VK_DOWN:
                    if (jb.getY() + MY_BUTTON <= MAX) {
                        jb.setLocation(jb.getX(), jb.getY() + MY_BUTTON);
                        jb.setText(MAX + " X " + MAX + "범위 내 이동 가능 / 단위: " + MY_BUTTON + " 현재 X: " + jb.getX() + " Y:" + jb.getY());
                    }break;
                case KeyEvent.VK_LEFT:
                    if (jb.getX() - MY_BUTTON >= 0) {
                        jb.setLocation(jb.getX() - MY_BUTTON, jb.getY());
                        jb.setText(MAX + " X " + MAX + "범위 내 이동 가능 / 단위: " + MY_BUTTON + " 현재 X: " + jb.getX() + " Y:" + jb.getY());
                    }break;
                case KeyEvent.VK_RIGHT:
                    if (jb.getX() + MY_BUTTON <= MAX) {
                        jb.setLocation(jb.getX() + MY_BUTTON, jb.getY());
                        jb.setText(MAX + " X " + MAX + "범위 내 이동 가능 / 단위: " + MY_BUTTON + " 현재 X: " + jb.getX() + " Y:" + jb.getY());
                    }break;
            }
        }

    }

    public static void main(String[] args) {
        new MovingButton_1();
    }
}
