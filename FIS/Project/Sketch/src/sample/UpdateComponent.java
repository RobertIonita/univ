package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.io.IOException;

public class UpdateComponent {
    public TextField categoryInput;
    public TextField nameInput;
    public TextField providerInput;
    public TextField amountInput;
    public TextArea commentsTextArea;
    public CheckBox paidCheckBox;
    public Button postBtn;

    public int recordId,
            recordAmount;
    public String recordCategory,
            recordName,
            recordProvider,
            recordPaid,
            recordComments;

    public UpdateComponent(
            int id,
            String category,
            String name,
            String provider,
            int amount,
            String paid,
            String comments
    ) {
        recordId = id;
        recordCategory = category;
        recordName = name;
        recordProvider = provider;
        recordAmount = amount;
        recordPaid = paid;
        recordComments = comments;
    }

    @FXML
    public void initialize() {
        categoryInput.setText(recordCategory);
        nameInput.setText(recordName);
        providerInput.setText(recordProvider);
        amountInput.setText(String.valueOf(recordAmount));
        paidCheckBox.setSelected(recordPaid.equals("true"));
        commentsTextArea.setText(recordComments);

        postBtn.setOnMouseClicked(e -> {
            System.out.println("Update triggered for: " + recordId);
            final String UPDATE_PARAMS = "{\n" +
                    "    \"id\": " + recordId + ",\r\n" +
                    "    \"category\": \"" + categoryInput.getText() + "\",\r\n" +
                    "    \"name\": \"" + nameInput.getText() + "\",\r\n" +
                    "    \"provider\": \"" + providerInput.getText() + "\",\r\n" +
                    "    \"amount\": " + amountInput.getText() + ",\r\n" +
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
