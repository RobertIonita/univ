package app.components.update;

import app.prototype.Product;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import app.handlers.APIHandler;
import java.io.IOException;

public class UpdateController extends Product {
    public TextField categoryInput;
    public TextField nameInput;
    public TextField providerInput;
    public TextField amountInput;
    public TextField priceInput;
    public TextArea commentsTextArea;
    public CheckBox paidCheckBox;
    public Button postBtn;

    private final String provider;
    private final String comments;
    private final Boolean paid;

    public UpdateController(int id, String category, String name, int amount, int price, String image,
                            String provider, Boolean paid, String comments) {
        super(id, category, name, amount, price, image);
        this.provider = provider;
        this.paid = paid;
        this.comments = comments;
    }

    @FXML
    public void initialize() {
        categoryInput.setText(category);
        nameInput.setText(name);
        providerInput.setText(provider);
        amountInput.setText(String.valueOf(amount));
        priceInput.setText(String.valueOf(price));
        paidCheckBox.setSelected(paid);
        commentsTextArea.setText(comments);

        postBtn.setOnMouseClicked(e -> {
            System.out.println("Update triggered for: " + id);
            final String UPDATE_PARAMS = "{\n" +
                    "    \"id\": " + id + ",\r\n" +
                    "    \"category\": \"" + categoryInput.getText() + "\",\r\n" +
                    "    \"name\": \"" + nameInput.getText() + "\",\r\n" +
                    "    \"provider\": \"" + providerInput.getText() + "\",\r\n" +
                    "    \"amount\": " + amountInput.getText() + ",\r\n" +
                    "    \"price\": " + priceInput.getText() + ",\r\n" +
                    "    \"paid\": " + paidCheckBox.isSelected() + ",\r\n" +
                    "    \"comments\": \"" + commentsTextArea.getText() + "\"\n}";
            try {
                APIHandler.makeRequest("UPDATE", "components", UPDATE_PARAMS);
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        });
    }
}
