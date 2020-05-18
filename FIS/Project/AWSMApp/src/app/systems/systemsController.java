package app.systems;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import app.productCard.ComponentCardController;
import java.io.*;
import java.net.URL;
import java.util.*;

public class SystemsController {

    @FXML
    private AnchorPane wrapper;
    @FXML
    private ScrollPane scroll;
    @FXML
    private TextField searchBar;
    @FXML
    private ComboBox categoryBox;
    @FXML
    private Button showAll;


    Set categories = new HashSet();
    public StringBuffer jsonStr = new StringBuffer();

    public SystemsController() throws IOException {
        URL url = new URL("https://tonu.rocks/school/AWSMApp/api/components/");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML
    public void appendTemplate(ComponentCardController component,
                               int layoutX, int layoutY) throws IOException {

        FXMLLoader loader = new FXMLLoader(getClass().getResource("/app/productCard/ComponentCard.fxml"));
        loader.setController(component);
        Pane componentCard = loader.load();
        componentCard.setLayoutX(layoutX);
        componentCard.setLayoutY(layoutY);

        wrapper.getChildren().add(componentCard);
        scroll.setContent(wrapper);
    }

    @FXML
    private void search(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 30;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            Boolean delivered = objectInArray.getString("delivered").equals("true");
            String comments = objectInArray.getString("comments");
            String date = objectInArray.getString("date");
            String imgSource = objectInArray.getString("image");

            categories.add(category);
            int layoutX = 50;
            if (i % 3 == 1) {
                layoutX = 270;
            } else if (i % 3 == 2) {
                layoutX = 480;
            }
            ComponentCardController component =
                    new ComponentCardController(id, category, name, amount, price, date, imgSource, provider, paid, delivered, comments, categories);
            appendTemplate(component, layoutX, layoutY);
            layoutY += (i + 1) % 3 != 0 ? 0 : 270;
        }
    }

    @FXML
    public void filter(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();

        int layoutY = 30;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            if (categoryBox.getValue().toString().equalsIgnoreCase(String.valueOf(objectInArray.getString("category")))) {

                int id = objectInArray.getInt("id");
                String category = objectInArray.getString("category");
                String name = objectInArray.getString("name");
                int amount = objectInArray.getInt("amount");
                int price = objectInArray.getInt("price");
                String provider = objectInArray.getString("provider");
                Boolean paid = objectInArray.getString("paid").equals("true");
                Boolean delivered = objectInArray.getString("delivered").equals("true");
                String comments = objectInArray.getString("comments");
                String date = objectInArray.getString("date");
                String imgSource = objectInArray.getString("image");
                int layoutX = 50;
                if (i % 3 == 1) {
                    layoutX = 270;
                } else if (i % 3 == 2) {
                    layoutX = 480;
                }
                ComponentCardController component =
                        new ComponentCardController(id, category, name, amount, price, date, imgSource, provider, paid, delivered, comments, categories);
                appendTemplate(component, layoutX, layoutY);
                layoutY += (i + 1) % 3 != 0 ? 0 : 270;
            } else if (categoryBox.getValue().toString().equalsIgnoreCase("All")) {
                int id = objectInArray.getInt("id");
                String category = objectInArray.getString("category");
                String name = objectInArray.getString("name");
                int amount = objectInArray.getInt("amount");
                int price = objectInArray.getInt("price");
                String provider = objectInArray.getString("provider");
                Boolean paid = objectInArray.getString("paid").equals("true");
                Boolean delivered = objectInArray.getString("delivered").equals("true");
                String comments = objectInArray.getString("comments");
                String date = objectInArray.getString("date");
                String imgSource = objectInArray.getString("image");
                int layoutX = 50;
                if (i % 3 == 1) {
                    layoutX = 270;
                } else if (i % 3 == 2) {
                    layoutX = 480;
                }
                ComponentCardController component =
                        new ComponentCardController(id, category, name, amount, price, date, imgSource, provider, paid, delivered, comments, categories);
                appendTemplate(component, layoutX, layoutY);
                layoutY += (i + 1) % 3 != 0 ? 0 : 270;
            }
        }
    }

    @FXML
    void showAll(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 30;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());

        for (int i = 0; i < jsonArray.length(); i++) {

            JSONObject objectInArray = jsonArray.getJSONObject(i);

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            Boolean delivered = objectInArray.getString("delivered").equals("true");
            String comments = objectInArray.getString("comments");
            String date = objectInArray.getString("date");
            String imgSource = objectInArray.getString("image");

            categories.add(category);
            int layoutX = 50;
            if (i % 3 == 1) {
                layoutX = 270;
            } else if (i % 3 == 2) {
                layoutX = 480;
            }
            ComponentCardController component =
                    new ComponentCardController(id, category, name, amount, price, date, imgSource, provider, paid, delivered, comments, categories);
            appendTemplate(component, layoutX, layoutY);
            layoutY += (i + 1) % 3 != 0 ? 0 : 270;
        }
    }

    @FXML
    public void initialize() throws JSONException, IOException {
        int layoutY = 30;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());

        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            Boolean delivered = objectInArray.getString("delivered").equals("true");
            String comments = objectInArray.getString("comments");
            String date = objectInArray.getString("date");
            String imgSource = objectInArray.getString("image");

            categories.add(category);
            int layoutX = 50;
            if (i % 3 == 1) {
                layoutX = 270;
            } else if (i % 3 == 2) {
                layoutX = 480;
            }
            ComponentCardController component =
                    new ComponentCardController(id, category, name, amount, price, date, imgSource, provider, paid, delivered, comments, categories);
            appendTemplate(component, layoutX, layoutY);
            layoutY += (i + 1) % 3 != 0 ? 0 : 270;
        }

        categoryBox.setItems(FXCollections.observableArrayList(categories));
        categoryBox.getSelectionModel().selectFirst();
    }
}
