package app.systems;

import app.handlers.APIHandler;
import app.prototype.Product;
import app.systems.update.UpdateController;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

public class SystemController extends Product {

    public Pane component_wrapper;
    @FXML
    private Label providerLabel;
    @FXML
    private Label nameLabel;
    @FXML
    private Label priceLabel;
    @FXML
    private Label commentsLabel;
    @FXML
    private Pane imagePane;

    @FXML
    private Button deleteBtn;
    @FXML
    private Button updateBtn;


    private final String provider;
    private final String comments;
    private final String image;
    private final Boolean paid;

    public SystemController(int id, String category, String name, int amount, int price, String image,
                            String provider, Boolean paid, String comments) {
        super(id, category, name, amount, price, image);
        this.provider = provider;
        this.paid = paid;
        this.comments = comments;
        this.image = image;
    }

    @FXML
    public Pane initialize() {
        providerLabel.setText(provider);
        nameLabel.setText(name);
        commentsLabel.setText(comments);
        imagePane.setStyle("-fx-background-image: url(" + image + ")");

        deleteBtn.setOnAction(event -> {
            try {
                APIHandler.makeRequest("DELETE", "components", this.getDeleteJSON());
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        updateBtn.setOnAction(event -> {
            UpdateController updateComponent =
                    new UpdateController(id, category, name, amount, price, image, provider, paid, comments);
            FXMLLoader loader = new FXMLLoader(
                    getClass().getResource("/app/components/update/Update.fxml")
            );
            loader.setController(updateComponent);
            Stage stage = new Stage();
            Parent dialog = null;
            try {
                dialog = loader.load();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
            assert dialog != null;
            stage.setScene(new Scene(dialog));
            stage.setTitle("Update component");
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initOwner(((Node) event.getSource()).getScene().getWindow());
            stage.show();
        });
        return component_wrapper;
    }
}
