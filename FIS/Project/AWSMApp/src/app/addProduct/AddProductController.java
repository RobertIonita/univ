package app.addProduct;

import app.services.APIHandler;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

import java.io.*;

public class AddProductController {


    public CheckBox isPaid;
    public CheckBox isDelivered;
    @FXML
    private RadioButton isSystem;
    @FXML
    private RadioButton isComponent;
    @FXML
    private ChoiceBox<String> categorySelect;
    @FXML
    private TextField nameInput;
    @FXML
    private TextField providerInput;
    @FXML
    private Spinner<Double> amountInput;
    @FXML
    private Spinner<Double> priceInput;
    @FXML
    private Spinner<Double> warrantyInput;
    @FXML
    private HBox warrantyHBOX;
    @FXML
    private HBox statusHBOX;
    @FXML
    private HBox providerHBOX;
    @FXML
    private HBox deliveryCommentsHBOX;
    @FXML
    private TextArea deliveryComments;
    @FXML
    private Button addBtn;
    @FXML
    private Label statusText;
    @FXML
    private Label deliveryCommentsText;

    @FXML
    void addNewProduct(ActionEvent event) throws IOException {
        if (isComponent.isSelected()) {
            final String POST_PARAMS = "{\n" +
                    "    \"category\": \"" + categorySelect.getValue() + "\",\r\n" +
                    "    \"name\": \"" + nameInput.getText() + "\",\r\n" +
                    "    \"provider\": \"" + providerInput.getText() + "\",\r\n" +
                    "    \"amount\": " + amountInput.getValue() + ",\r\n" +
                    "    \"price\": " + priceInput.getValue() + ",\r\n" +
                    "    \"paid\": " + isPaid.isSelected() + ",\r\n" +
                    "    \"delivered\": " + isDelivered.isSelected() + ",\r\n" +
                    "    \"comments\": \"" + deliveryComments.getText() + "\n}";

            APIHandler.makeRequest("PUT", "components", POST_PARAMS);

        } else if (isSystem.isSelected()) {
            final String POST_PARAMS = "{\n" +
                    "    \"category\": \"" + categorySelect.getValue() + "\",\r\n" +
                    "    \"name\": \"" + nameInput.getText() + "\",\r\n" +
                    "    \"amount\": " + 200 + ",\r\n" +
                    "    \"price\": " + 199 + ",\r\n" +
                    "    \"warranty\": " + 12 + "\n}";

            APIHandler.makeRequest("PUT", "systems", POST_PARAMS);
        }

    }

    @FXML
    private void switchProductCategory() {
        amountInput.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(0, 100, 0, 1));
        amountInput.setEditable(true);
        if (isComponent.isSelected()) {
            categorySelect.setItems(FXCollections.observableArrayList(
                    "placa video", "placa de baza", "memorie RAM", "procesor", "hdd", "carcasa"));
            categorySelect.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 ); -fx-font-family: 'Arial';-fx-font-size: 13;-fx-text-fill: #bebebe");

            statusHBOX.getChildren().addAll(statusText, isPaid, isDelivered);
            deliveryCommentsHBOX.getChildren().addAll(deliveryCommentsText, deliveryComments);
            providerHBOX.setVisible(true);
            warrantyHBOX.setVisible(false);
        } else if (isSystem.isSelected()) {
            categorySelect.setItems(FXCollections.observableArrayList(
                    "laptop", "laptop mini", "desktop office", "desktop gaming", "desktop replacement"));
            categorySelect.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );-fx-font-family: 'Arial';-fx-font-size: 13; -fx-text-fill: #bebebe");
            statusHBOX.getChildren().clear();
            deliveryCommentsHBOX.getChildren().clear();
            providerHBOX.setVisible(false);
            warrantyHBOX.setVisible(true);
        }
    }
}
