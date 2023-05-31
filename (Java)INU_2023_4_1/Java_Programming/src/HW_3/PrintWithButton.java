package HW_3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class PrintWithButton extends JFrame {
    private final int MAX = 700;
    private final int BUTTON = 100;

    JButton button[] = new JButton[4];
    private String[] num = {"0", "1", "2", "C"};
    private String[] check = null;
    int check_ = 0;
    JLabel la = new JLabel(" ", SwingConstants.CENTER);
    JPanel p = new JPanel();
    public PrintWithButton() throws HeadlessException {
        setTitle("press buttons to print / C for delete");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBackground(Color.lightGray);
        setSize(MAX, MAX);
        setVisible(true);

        Container c = getContentPane();
        c.setLayout(new BorderLayout());

        c.setBackground(Color.gray);
        c.add(p, BorderLayout.NORTH);
        c.add(la, BorderLayout.CENTER);
        c.setFocusable(true);
        c.requestFocus();

        la.setLocation(350, 500);
        la.setBackground(Color.YELLOW);
        la.setSize(30, 100);

        p.setBackground(Color.BLACK);
        p.setSize(600, 200);
        MyClickListner cl = new MyClickListner();

        for (int i = 0; i < num.length; i++){
            button[i] = new JButton(num[i]);
            button[i].setSize(BUTTON, BUTTON);
            button[i].setLocation((p.getX() / BUTTON * i), 100);
            button[i].requestFocus();
            button[i].addMouseListener(cl);
            p.add(button[i], i);
        }
    }

    class MyClickListner implements MouseListener {

        @Override
        public void mouseClicked(MouseEvent e) {

//            if(!check[check.length - 1].equals("0")){
//                String temp = "";

                if (e.getSource() == button[0]) {
                    la.setText(la.getText() + "0");
//                    temp = "0";
                    check_++;
                }else if (e.getSource() == button[1]) {
                    la.setText(la.getText() + "1");
//                    temp = "1";
                    check_++;
                }else if (e.getSource() == button[2]) {
                    la.setText(la.getText() + "2");
//                    temp = "2";
                    check_++;
                }else if (e.getSource() == button[3]) {
                    la.setText("");
                    check_ = 0;
                }
//                check[check_] = temp;
//            }
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }

    public static void main(String[] args) {
        new PrintWithButton();
    }
}
