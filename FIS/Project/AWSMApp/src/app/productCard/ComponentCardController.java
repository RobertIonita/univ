package app.productCard;

import app.components.Component;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import app.services.prototype.Product;
import app.productCard.popup.PopupController;
import org.json.JSONException;

import java.io.IOException;
import java.util.Set;

public class ComponentCardController extends Component {

    @FXML
    private Pane paneContainer;

    @FXML
    private Pane imagePane;

    @FXML
    private Pane textPane;

    @FXML
    private Text productName;

    Set recordCategories;

    public ComponentCardController(int id, String category, String name, int amount, int price, String date, String image,
                                   String provider, Boolean paid, Boolean delivered, String comments, Set categories) {
        super(id, category, name, amount, price, date, image, provider, paid, delivered, comments);
        this.recordCategories = categories;
    }
    public ComponentCardController (Component component, Set categories) {
        super(component.id, component.category,
                component.name,
                component.amount,
                component.price,
                component.date,
                component.image,
                component.provider,
                component.paid,
                component.delivered,
                component.comments);
        this.recordCategories = categories;
    }

    @FXML
    public Pane initialize() {

        productName.setText(name);
        imagePane.setStyle("-fx-background-image: url(" + image + ");" +
                "-fx-background-repeat: no-repeat;" +
                "-fx-background-size: cover");
        paneContainer.setOnMouseClicked(mouseEvent -> {
            PopupController popup =
                    new PopupController(id, category, name, amount, price, date, image, provider, paid, delivered, comments, recordCategories);

            FXMLLoader loader = new FXMLLoader(getClass().getResource("/app/productCard/popup/Popup.fxml"));
            loader.setController(popup);

            Stage stage = new Stage();
            Parent dialog = null;
            try {
                dialog = loader.load();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            Scene scene = new Scene(dialog);
            scene.setFill(Color.TRANSPARENT);
            stage.setScene(scene);
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initStyle(StageStyle.TRANSPARENT);
            stage.initOwner(((Node) mouseEvent.getSource()).getScene().getWindow());
            stage.showAndWait();
        });
        return paneContainer;
    }
}
