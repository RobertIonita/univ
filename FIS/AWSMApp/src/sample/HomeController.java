package sample;

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

import java.io.IOException;

public class HomeController extends workspaceController {

    @FXML
    private StackPane parentContainer;
    @FXML
    private AnchorPane anchorRoot;
 static  workspaceController sidebarController;
    public HomeController() throws IOException {


    }
    public workspaceController getController(){
        return sidebarController;
    }

    @FXML
    private void gotoSystems(MouseEvent event) throws IOException {
     

    }
    @FXML
    private void gotoAdd(ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("workspace.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }
    @FXML
    private void gotoComponents(ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("workspace.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }
    @FXML
    private void gotoGraph(ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("workspace.fxml"));
        Scene systemsScene = new Scene(root);
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
        window.setScene(systemsScene);
        window.show();
    }





}
