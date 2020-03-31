import javax.swing.*;

public class SQLite_interface extends JFrame {
    private JPanel mainPanel;
    private JTextField userInput;
    private JButton userDeleteBtn;
    private JButton booksBtn;
    private JTextArea resultsTextArea;

    public SQLite_interface(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
    }

    public static void main (String[] args) {
        JFrame frame = new SQLite_interface("Hello, World!");
        frame.setVisible(true);
    }
}
