package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;

public class recentItemsController {

    @FXML
    private Label productName;

    @FXML
    private Label cantitate;

    @FXML
    private Label dataAdd;

    @FXML
    private Pane wrapper;

    public  String nameRecord,
                    dateRecord;
    public int countRecord;
    public recentItemsController(String name,int count,String date){
        nameRecord=name;
        dateRecord=date;
        countRecord=count;
    }
    @FXML
    public void initialize(){
        productName.setText(nameRecord);
        cantitate.setText(String.valueOf(countRecord));
        dataAdd.setText(dateRecord);
    }
}
