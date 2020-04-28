import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;

public class Movies extends JFrame {
    private JPanel mainPanel;
    private JTextField txtMovie;
    private JPanel genresPanel;
    private JCheckBox ckbComedy;
    private JCheckBox ckbDrama;
    private JCheckBox ckbHistorical;
    private JCheckBox ckbAction;
    private JCheckBox ckbRomance;
    private JButton btnAdd;
    private JButton btnDelete;
    private JSpinner spinner;
    private JPanel tablePanel;
    private JTable moviesTable;
    private JTextField txtActors;
    static DefaultTableModel tableModel;

    class Record {
        String name,
                actors,
                genres;
        Number year;

        public Record(String name, String actors, String genres, Number year) {
            this.name = name;
            this.actors = actors;
            this.genres = genres;
            this.year = year;
        }

        void dispaly() {
            System.out.println(this.name + " " + this.actors + " " + this.genres + " " + this.year);
        }
    }

    public Movies(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);

        SpinnerModel spinnerModel = new SpinnerNumberModel(2020, 2015, 2020, 1);
        spinner.setModel(spinnerModel);

        String[] columnNames = {"Film", "Actori", "An lansare", "Genuri"};
        tableModel = new DefaultTableModel();
        for (String column : columnNames) {
            tableModel.addColumn(column);
        }
        moviesTable.setModel(tableModel);
        this.pack();

        btnAdd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String genres = "";
                JCheckBox[] checkboxes = {ckbAction, ckbComedy, ckbDrama, ckbHistorical, ckbRomance};
                for (JCheckBox element : checkboxes) {
                    if (element.isSelected())
                        genres += element.getText() + ", ";
                }
                if (genres.length() < 2)
                    genres = "Altele..";
                genres = genres.substring(0, genres.length() - 2);
                tableModel.addRow(new Object[] {txtMovie.getText(), txtActors.getText(), (Integer) spinner.getValue(), genres});
                System.out.println(tableModel.getRowCount());
            }
        });
        txtMovie.addFocusListener(new FocusAdapter() {
            public void focusLost(FocusEvent e) {
                if (txtMovie.getText().length() > 0 && txtActors.getText().length() > 0)
                    btnAdd.setEnabled(true);
                else
                    btnAdd.setEnabled(false);
            }
        });
        txtActors.addFocusListener(new FocusAdapter() {
            public void focusLost(FocusEvent e) {
                if (txtMovie.getText().length() > 0 && txtActors.getText().length() > 0)
                    btnAdd.setEnabled(true);
                else
                    btnAdd.setEnabled(false);
            }
        });

        btnDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (tableModel.getRowCount() > 0) {
                    int[] indices = moviesTable.getSelectedRows();
                    for (int index : indices)
                        tableModel.removeRow(index);
                }
                System.out.println("records: " + tableModel.getRowCount());
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new Movies("Filme");
        frame.setVisible(true);
    }
}
