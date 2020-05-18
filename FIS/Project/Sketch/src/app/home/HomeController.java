package app.home;

import app.components.ComponentController;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

public class HomeController {

    public StringBuffer jsonStr = new StringBuffer();

    public HomeController() throws IOException {
        URL url = new URL("https://tonu.rocks/school/AWSMApp/api/components");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML
    private Pane wrapper;

    public void appendTemplate(
            ComponentController component,
            int layoutX, int layoutY
    ) throws IOException {

        FXMLLoader loader = new FXMLLoader(getClass().getResource("/app/components/Component.fxml"));
        loader.setController(component);
        Pane componentCard = loader.load();
        componentCard.setLayoutX(layoutX);
        componentCard.setLayoutY(layoutY);

        wrapper.getChildren().add(componentCard);
    }

    @FXML
    public void initialize() throws JSONException, IOException {
        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);
            System.out.printf("%d ELEMENTS IN CURRENT OBJECT:\n", elementNames.length);
            for (String elementName : elementNames) {
                System.out.print(elementName + " ");
                try {
                    System.out.println(objectInArray.getInt(elementName));
                } catch (JSONException e) {
                    System.out.println(objectInArray.getString(elementName));
                }
            }
            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            String comments = objectInArray.getString("comments");
            String imgSource = objectInArray.getString("image");
            int layoutX = 0;

            if (i % 3 == 1) {
                layoutX = 340;
            } else if (i % 3 == 2) {
                layoutX = 680;
            }
            ComponentController component =
                    new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments);

            appendTemplate(component, layoutX, layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 320;
            System.out.println(layoutX + "Y: " + layoutY + "i: " + i);
        }
    }

    public void gotoAddComponent(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("/app/components/add/Add.fxml"));
        Scene addComponentScene = new Scene(root);
        Stage window = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        window.setScene(addComponentScene);
        window.show();
    }
}
