package sample;

import javafx.fxml.FXML;
import javafx.scene.layout.Background;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.Iterator;

public class Controller {

    public StringBuffer jsonStr = new StringBuffer();
    public Controller() throws IOException {
        URL url = new URL("https://tonu.rocks/AWSMApp/api/systems.php");
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

    public void appendTemplate(String name, String count, int layoutX, int layoutY) {
        Pane pane = new Pane();
        pane.setPrefSize(120, 120);
        pane.setLayoutX(layoutX);
        pane.setLayoutY(layoutY);
        pane.setVisible(true);
        Text name_label = new Text(name);
        name_label.setY(90);
        Text count_label = new Text(count);
        count_label.setY(110);
        pane.getChildren().add(name_label);
        pane.getChildren().add(count_label);
        wrapper.getChildren().add(pane);
    }

    public void setData(String data) {
        name.setText(data);
    }

    @FXML
    public void initialize() throws JSONException {
        setData("kek");
        wrapper.getChildren().remove(0,1);
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
            Integer count = objectInArray.getInt("count");
            int layoutX = i % 2 == 0 ? 100 : 250;
            appendTemplate(objectInArray.getString("name"), count.toString(), layoutX, layoutY);
            layoutY += i % 2 == 0 ? 0 : 150;
            System.out.println();
        }
    }
}
