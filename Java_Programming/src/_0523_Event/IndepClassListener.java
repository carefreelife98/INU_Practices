package _0523_Event;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.security.cert.TrustAnchor;

public class IndepClassListener extends JFrame {
    public IndepClassListener() {
        setTitle("Action 이벤트 리스너 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JButton btn = new JButton("Action");
        btn.addActionListener(new MyActionListener());
        c.add(btn);

        setSize(350, 150);
        setVisible(true);
    }

    public static void main(String[] args) {
        new IndepClassListener();
    }
}

class MyActionListener implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton b = (JButton)e.getSource();
        if (b.getText().equals("Action")) {
            b.setText("액션");
        } else {
            b.setText("Action");
        }
    }
}