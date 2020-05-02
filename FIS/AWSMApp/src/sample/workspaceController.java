package sample;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class workspaceController {
    @FXML
    private BorderPane bp;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button systemBtn;

    @FXML
    public Button plusBtn;

    @FXML
    private Button homeBtn;
    @FXML
    private AnchorPane ap;




        @FXML
        void addBtn(MouseEvent event) throws IOException {
            loadPage("adaugaComponente");


        }

        @FXML
        void compBtn(MouseEvent event) throws IOException {
           loadPage("componenteScene");


        }



        @FXML
        void graphBtn(MouseEvent event) throws IOException {
            loadPage("graphScene");
        }

        @FXML
        void homeBtn(MouseEvent event) throws IOException {
            Parent root = FXMLLoader.load(getClass().getResource("homeScene.fxml"));
            Scene systemsScene = new Scene(root);
            Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
            window.setScene(systemsScene);
            window.show();

        }

        @FXML
        void systBtn(MouseEvent event) throws IOException {
            loadPage("systemsScene");

        }



    @FXML
    void initialize() throws IOException {


    }
    void loadPage(String page) throws IOException {
   Parent root=null;
        try{
           root= FXMLLoader.load(getClass().getResource(page+".fxml"));

        }catch(IOException ex){
            Logger.getLogger(workspaceController.class.getName()).log(Level.SEVERE,null,ex);
        }
        bp.setCenter(root);

    }
}
