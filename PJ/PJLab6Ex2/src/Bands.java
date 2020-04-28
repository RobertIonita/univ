import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.DefaultListModel;

public class Bands extends JFrame {
    private JTextField txtInput;
    private JButton btnDelete;
    private JList listBands;
    private JPanel mainPanel;


    public Bands(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();

        DefaultListModel listModel = new DefaultListModel();
        JList bandsList = new JList(listModel);
        bandsList.setBounds(0, 0, getWidth(), getHeight());
        listBands.add(bandsList);

        txtInput.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                if (e.getKeyCode() == 10) {
                    listModel.addElement(txtInput.getText());
                    txtInput.setText("");
                }
            }
        });


        btnDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int[] selected = bandsList.getSelectedIndices();
                for (int index : selected)
                    listModel.removeElementAt(index);
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new Bands("Formații");
        frame.setVisible(true);
    }
}


