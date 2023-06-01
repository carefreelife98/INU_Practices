package HW_3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class PrintWithButton extends JFrame {
    private final int MAX = 700;
    private final int BUTTON = 100;
    private String[] num = {"0", "1", "2", "C"};

    JButton[] button = new JButton[4];
    JLabel la = new JLabel("", SwingConstants.CENTER);
    JPanel p = new JPanel();

    public PrintWithButton() throws HeadlessException {
        setTitle("press buttons to print / C for delete");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(MAX, MAX);
        setVisible(true);

        Container c = getContentPane();
        c.setLayout(new BorderLayout());

        la.setHorizontalAlignment(SwingConstants.CENTER);
        la.setBackground(Color.LIGHT_GRAY);
        la.setSize(30, 100);
        la.setOpaque(true);
        la.setVisible(true);
        c.add(la);

        p.setBackground(Color.BLACK);
        p.setSize(MAX, 200);
        p.setVisible(true);

        MyMouseAdapter cl = new MyMouseAdapter();
        for (int i = 0; i < num.length; i++){
            button[i] = new JButton(num[i]);
            button[i].setSize(BUTTON, BUTTON);
            button[i].addMouseListener(cl);
            p.add(button[i]);
        }
        c.add(p, BorderLayout.NORTH);
    }
    class MyMouseAdapter extends MouseAdapter {
        @Override
        public void mouseClicked(MouseEvent e) {
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
