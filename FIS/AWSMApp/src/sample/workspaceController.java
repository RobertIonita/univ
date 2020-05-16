package sample;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.nio.file.Path;
import java.util.Collection;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

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
    private Text lastAdded;
    @FXML
    private Text totalSystems;

    @FXML
    private Text lastAddedComp;
    @FXML
    private Text totalComponents;
    @FXML
    private VBox recentFilesVbox;

    public StringBuffer jsonStr = new StringBuffer();
    private  final String API_Components="https://tonu.rocks/school/AWSMApp/api/components/";
    private final String API_Systems="https://tonu.rocks/school/AWSMApp/api/systems/";

    public workspaceController() throws IOException {
        URL url = new URL(API_Components);
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }



    @FXML
        void addBtn(MouseEvent event) throws IOException {
            loadPage("adaugaComponente");


        }

        @FXML
        void compBtn(MouseEvent event) throws IOException {
           loadPage("componenteScene");


        }


        @FXML
        void systBtn(MouseEvent event) throws IOException {
            loadPage("systemsScene");

        }



    @FXML
    void initialize() throws IOException, JSONException {
        Parent rootNode=null;
        try{
            rootNode=FXMLLoader.load(getClass().getResource("homeScene.fxml"));
        }catch (IOException ex){
            ex.printStackTrace();
        }
        bp.setCenter(rootNode);


    }
    @FXML
    void homeBtn(MouseEvent event) throws IOException, JSONException {
        loadPage("homeScene");

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
