package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.stage.Modality;
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
            int id,
            String category,
            String name,
            String provider,
            int amount,
            String paid,
            String comments,
            String imgSource,
            int layoutX, int layoutY) {

        Pane pane = new Pane();
        pane.setPrefSize(120, 120);
        pane.setLayoutX(layoutX);
        pane.setLayoutY(layoutY);
        pane.setVisible(true);
        Text name_label = new Text(name);
        name_label.setY(100);
        Text category_label = new Text(category);
        category_label.setY(110);
        pane.getChildren().add(name_label);
        pane.getChildren().add(category_label);
        Pane image = new Pane();
        image.setStyle("-fx-background-image: url(" + imgSource + "); -fx-background-size: cover; -fx-background-position: center center;");
        image.setPrefSize(100, 90);
        image.setLayoutX(0);
        image.setLayoutY(0);
        pane.getChildren().add(image);
        Button deleteBtn = new Button("Delete");
        deleteBtn.setOnAction(e -> {
            System.out.println("Delete triggered for: "+id);
            final String DELETE_PARAMS = "{\n" +
                    "    \"id\": " + id + ",\r\n" +
                    "    \"name\": \"" + name + "\"" + "\n}";
            try {
                pane.setVisible(false);
                APIHandler.makeRequest("DELETE", "components", DELETE_PARAMS);
            } catch (IOException ioException) {
                ioException.printStackTrace();
                pane.setVisible(true);
            }
        });
        pane.getChildren().add(deleteBtn);
        Button updateBtn = new Button("Update");
        updateBtn.setLayoutX(100);
        updateBtn.setOnAction(e -> {
            UpdateComponent updateComponent =
                    new UpdateComponent(id, category, name, provider, amount, paid, comments);
            FXMLLoader loader = new FXMLLoader(
                    getClass().getResource("UpdateComponent.fxml")
            );
            loader.setController(updateComponent);
            Stage stage = new Stage();
            Parent dialog = null;
            try {
                dialog = loader.load();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
            stage.setScene(new Scene(dialog));
            stage.setTitle("My modal window");
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initOwner( ((Node)e.getSource()).getScene().getWindow() );
            stage.show();

        });
        pane.getChildren().add(updateBtn);
        wrapper.getChildren().add(pane);
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
            String provider = objectInArray.getString("provider");
            int amount = objectInArray.getInt("amount");
            String paid = objectInArray.getString("paid");
            String comments = objectInArray.getString("comments");
            String imgSource = objectInArray.getString("image");
            int layoutX = 0;

            if (i % 3 == 1) {
                layoutX = 340;
            } else if (i % 3 == 2) {
                layoutX = 680;
            }

            appendTemplate(id, category, name, provider, amount, paid, comments ,imgSource, layoutX, layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 200;
            System.out.println(layoutX + "Y: " + layoutY + "i: " + i);
        }
    }

    public void gotoAddComponent(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("AddComponent.fxml"));
        Scene addComponentScene = new Scene(root);
        Stage window = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        window.setScene(addComponentScene);
        window.show();
    }
}
