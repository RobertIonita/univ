package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class popupController {

    @FXML
    private Pane imageHolder;

    @FXML
    private VBox descriptionVBOX;

    @FXML
    private VBox closeVBOX;

    @FXML
    private Button close;

    @FXML
    void closePOP(ActionEvent event) {
        Stage stage = (Stage) close.getScene().getWindow();
        stage.close();

    }
}
