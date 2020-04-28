import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame {
    private JPanel mainPane;
    private JButton btnAdd;
    private JTextField txtOperand1;
    private JTextField txtOperand2;
    private JButton btnSubtract;
    private JButton btnDivide;
    private JButton btnMultiply;
    private JTextPane txtResult;
    private JButton btnClear;


    public static boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }

    public Calculator(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPane);
        this.pack();

        btnClear.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                txtResult.setText("");
            }
        });
        btnAdd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String x = txtOperand1.getText();
                String y = txtOperand2.getText();
                if (isNumeric(x) && isNumeric(y)) {
                    txtResult.setText(Double.parseDouble(x) + Double.parseDouble(y) + "");
                } else {
                    txtResult.setText("NaN");
                }
            }
        });
        btnSubtract.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String x = txtOperand1.getText();
                String y = txtOperand2.getText();
                if (isNumeric(x) && isNumeric(y)) {
                    txtResult.setText(Double.parseDouble(x) - Double.parseDouble(y) + "");
                } else {
                    txtResult.setText("NaN");
                }
            }
        });
        btnMultiply.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String x = txtOperand1.getText();
                String y = txtOperand2.getText();
                if (isNumeric(x) && isNumeric(y)) {
                    txtResult.setText(Double.parseDouble(x) * Double.parseDouble(y) + "");
                } else {
                    txtResult.setText("NaN");
                }
            }
        });
        btnDivide.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String x = txtOperand1.getText();
                String y = txtOperand2.getText();
                if (isNumeric(x) && isNumeric(y)) {
                    if (y.equals("0")) {
                        txtResult.setText("Division by zero is illegal, you cunt!");
                    } else {
                        txtResult.setText(Double.parseDouble(x) / Double.parseDouble(y) + "");
                    }
                } else {
                    txtResult.setText("NaN");
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new Calculator("Calculator");
        frame.setVisible(true);
    }

}


