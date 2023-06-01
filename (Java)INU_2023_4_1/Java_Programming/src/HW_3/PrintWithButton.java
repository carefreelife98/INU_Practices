package HW_3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class PrintWithButton extends JFrame {

    JButton[] button = new JButton[4];
    JLabel la = new JLabel("", SwingConstants.CENTER);
    JPanel p = new JPanel();

    public PrintWithButton() throws HeadlessException {
        String[] num = {"0", "1", "2", "C"};
        int BUTTON = 100;
        int MAX = 700;
        setTitle("press buttons to print / C for delete");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(new BorderLayout());

        la.setHorizontalAlignment(SwingConstants.CENTER);
        la.setBackground(Color.LIGHT_GRAY);
        la.setPreferredSize(new Dimension(30, 100));
        la.setOpaque(true);
        la.setVisible(true);
        c.add(la);

        p.add(new JLabel("0 이후에 새로운 숫자의 입력은 허용되지 않습니다."), BorderLayout.NORTH);
        p.setBackground(Color.ORANGE);
        p.setSize(MAX, 200);
        p.setVisible(true);


        MyMouseAdapter cl = new MyMouseAdapter();
        for (int i = 0; i < num.length; i++){
            button[i] = new JButton(num[i]);
            button[i].setText(num[i]);
            button[i].setSize(BUTTON, BUTTON);
            button[i].addMouseListener(cl);
            p.add(button[i]);
        }
        c.add(p, BorderLayout.NORTH);

        setSize(MAX, 200);
        setVisible(true);
    }
    class MyMouseAdapter extends MouseAdapter {
        @Override
        public void mousePressed(MouseEvent e) {
            if(!la.getText().startsWith("0")) {
                if (e.getSource() == button[0]) {
                    if (!la.getText().startsWith("0"))
                        la.setText(la.getText() + "0");

                } else if (e.getSource() == button[1]) {
                    la.setText(la.getText() + "1");

                } else if (e.getSource() == button[2]) {
                    la.setText(la.getText() + "2");
                }
            }
            else{
                la.setText("0");
            }
            if (e.getSource() == button[3]) {
                la.setText("");
            }
        }
    }
    public static void main(String[] args) {
        new PrintWithButton();
    }
}
