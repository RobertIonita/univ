package sample;

import javafx.animation.Interpolator;
import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class HomeController extends workspaceController {

    @FXML
    private StackPane parentContainer;
    @FXML
    private AnchorPane anchorRoot;

    public HomeController() throws IOException {
    }

    @FXML
    private void gotoSystems(ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("workspace.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }
    @FXML
    private void gotoAdd(ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("workspace.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }





}
