package app.components;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import app.handlers.APIHandler;

import java.io.IOException;

public class AddComponent {
    public TextField category;
    public TextField name;
    public TextField provider;
    public TextField amount;
    public TextArea comments;
    public CheckBox paid;
    public Button postBtn;

    public void gotoHomeComponent(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("../home/Home.fxml"));
        Scene homeScene = new Scene(root);
        Stage window = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        window.setScene(homeScene);
        window.show();
    }

    @FXML
    public void initialize() {
        postBtn.setOnMouseClicked(e -> {
            System.out.println("Post btn triggered");
            final String POST_PARAMS = "{\n" +
                    "    \"category\": \"" + category.getText() + "\",\r\n" +
                    "    \"name\": \"" + name.getText() + "\",\r\n" +
                    "    \"provider\": \"" + provider.getText() + "\",\r\n" +
                    "    \"amount\": " + amount.getText() + ",\r\n" +
                    "    \"paid\": " + paid.isSelected() + ",\r\n" +
                    "    \"comments\": \"" + comments.getText() + "\"" + "\n}";
            try {
                APIHandler.makeRequest("PUT","components", POST_PARAMS);
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        });
    }
}
