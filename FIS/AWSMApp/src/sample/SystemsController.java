package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class SystemsController {

    @FXML
    private void gotoHome(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("homeScene.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }
    @FXML
    private void  gotoAdd(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("adaugaComponente.fxml"));
        Scene adaugaComponente= new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(adaugaComponente);
        window.show();
    }
}
