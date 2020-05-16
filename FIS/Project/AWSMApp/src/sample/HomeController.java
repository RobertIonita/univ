package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

public class HomeController extends workspaceController {

    @FXML
    private AnchorPane anchorRoot;

    @FXML
    private Text lastAdded;

    @FXML
    private Pane timeIconHolder;

    @FXML
    private Text totalSystems;

    @FXML
    private Text lastAddedComp;

    @FXML
    private Pane timeIconHolder1;

    @FXML
    private Text totalComponents;

    @FXML
    private VBox recentFilesVbox;
    @FXML
    private Pane wrapper;

    public StringBuffer jsonStr = new StringBuffer();
    private  final String API_Components="https://tonu.rocks/school/AWSMApp/api/components/";
    private final String API_Systems="https://tonu.rocks/school/AWSMApp/api/systems/";

    public HomeController() throws IOException {
        URL url = new URL(API_Components);
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();

    }
    @FXML
    public void initialize() throws JSONException, IOException {
        recentFilesVbox.setSpacing(20);
        recentItemsController recentItems;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());
        JSONObject jsonObject = jsonArray.getJSONObject(jsonArray.length()-1);

        for (int i = jsonArray.length()-1; i>(jsonArray.length()-4); i--) {

            JSONObject objectInArray = jsonArray.getJSONObject(i);

            Integer id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            String provider = objectInArray.getString("provider");
            Integer amount = objectInArray.getInt("amount");
            Boolean paid = objectInArray.getBoolean("paid");
            String date = objectInArray.getString("date");
            String comments = objectInArray.getString("comments");
            String image = objectInArray.getString("image");


            recentItems=new recentItemsController(name,amount,date);
            FXMLLoader loader=new FXMLLoader(getClass().getResource("recentItems.fxml"));
            loader.setController(recentItems);

            Pane homepage=loader.load();
            recentFilesVbox.getChildren().addAll(homepage);



        }
        totalComponents.setText(String.valueOf(jsonArray.length()));
        lastAddedComp.setText("Created on \n"+jsonObject.getString("date"));


    }
}
