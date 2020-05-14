package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;

import java.io.IOException;

public class popupController {

    @FXML
    private Pane imageHolder;

    @FXML
    private TextArea denumireProd;

    @FXML
    private TextField categorieProd;

    @FXML
    private ListView<?> listaComponente;

    @FXML
    private Button updateBtn;

    @FXML
    private Button deleteBtn;

    @FXML
    private Button saveBtn;
    @FXML
    private Pane warrantyArea;

    public int recordId,
            recordAmount;
    public String recordCategory,
            recordName,
            recordProvider,
            recordPaid,
            recordComments,
            recordImage;
    public popupController(int id,
                           String category,
                           String name,
                           String provider,
                           int amount,
                           String paid,
                           String comments,
                           String image
    ){
        recordId=id;
        recordCategory=category;
        recordName=name;
        recordProvider=provider;
        recordAmount = amount;
        recordPaid = paid;
        recordComments = comments;
        recordImage=image;
    }
    @FXML
    public  void initialize(){
        denumireProd.setText(recordName);
        denumireProd.setDisable(true);

        categorieProd.setText(recordCategory);
        categorieProd.setDisable(true);

        saveBtn.setVisible(false);

        imageHolder.setStyle("-fx-background-image: url("+recordImage+");" +
                "-fx-background-position: center center;" +
                " -fx-background-repeat: no-repeat;" +
                "-fx-background-size: auto");

        updateBtn.setOnMouseClicked(mouseEvent -> {
            denumireProd.setDisable(false);
            categorieProd.setDisable(false);
           saveBtn.setVisible(true);
        });
        saveBtn.setOnMouseClicked(mouseEvent -> {
            denumireProd.setDisable(true);
            categorieProd.setDisable(true);
            saveBtn.setVisible(false);
            System.out.println("update elemente: "+recordId);
            final String UPDATE_PARAMS = "{\n" +
                    "    \"id\": " + recordId + ",\r\n" +
                    "    \"category\": \"" + categorieProd.getText() + "\",\r\n" +
                    "    \"name\": \"" + denumireProd.getText() + "\",\r\n" +
                    "    \"provider\": \"" + recordProvider + "\",\r\n" +
                    "    \"amount\": " + recordAmount + ",\r\n" +
                    "    \"paid\": " + recordPaid + ",\r\n" +
                    "    \"comments\": \"" + recordComments + "\"\n}";
            try {
                APIHandler.makeRequest("UPDATE","components",UPDATE_PARAMS);
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
    }

}

