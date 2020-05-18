package app.home.recentItems;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class RecentItemsController {

    @FXML
    private Label nameLabel;

    @FXML
    private Label amountLabel;

    @FXML
    private Label dateLabel;

    public  String nameRecord,
                    dateRecord;
    public int amountRecord;
    public RecentItemsController(String name, int amount, String date){
        nameRecord=name;
        dateRecord=date;
        amountRecord=amount;
    }
    @FXML
    public void initialize(){
        nameLabel.setText(nameRecord);
        amountLabel.setText(String.valueOf(amountRecord));
        dateLabel.setText(dateRecord);
    }
}
