package sample;

import javafx.fxml.FXML;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.Background;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.Iterator;

public class Controller {

    public StringBuffer jsonStr = new StringBuffer();
    public Controller() throws IOException {
        URL url = new URL("https://tonu.rocks/AWSMApp/api/components.php");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML
    private Text name;
    @FXML
    private Pane wrapper;

    public void appendTemplate(String name, String count, String imgSource, int layoutX, int layoutY) {
        Pane pane = new Pane();
        pane.setPrefSize(120, 120);
        pane.setLayoutX(layoutX);
        pane.setLayoutY(layoutY);
        pane.setVisible(true);
        Text name_label = new Text(name);
        name_label.setY(100);
        Text count_label = new Text(count);
        count_label.setY(110);
        pane.getChildren().add(name_label);
        pane.getChildren().add(count_label);
        Pane image = new Pane();
        image.setStyle("-fx-background-image: url("+imgSource+"); -fx-background-size: cover; -fx-background-position: center center;");
        image.setPrefSize(100, 90);
        image.setLayoutX(0);
        image.setLayoutY(0);
        pane.getChildren().add(image);
        wrapper.getChildren().add(pane);
        scroll.setContent(wrapper);
        last.getChildren().add(scroll);
    }

    @FXML
    public void initialize() throws JSONException {
        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);
            System.out.printf("%d ELEMENTS IN CURRENT OBJECT:\n", elementNames.length);
            for (String elementName : elementNames) {
                String k = new Integer(8).toString();
                System.out.print(elementName + " ");
                try {
                    System.out.println(objectInArray.getInt(elementName));
                } catch (JSONException e) {
                    System.out.println(objectInArray.getString(elementName));
                }
            }
            String name = objectInArray.getString("name");
            String category = objectInArray.getString("category");
            String imgSource = objectInArray.getString("image");
            int layoutX = i % 2 == 0 ? 100 : 350;
            appendTemplate(name, category, imgSource, layoutX, layoutY);
            layoutY += i % 2 == 0 ? 0 : 150;
            System.out.println();
        }
    }
}
