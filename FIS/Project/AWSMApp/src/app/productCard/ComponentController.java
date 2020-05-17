package app.productCard;

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
import app.Prototype.Product;
import app.productCard.popup.popupController;

import java.io.IOException;
import java.util.Set;

public class ComponentController extends Product {


    @FXML
    private Pane paneContainer;

    @FXML
    private Pane imagePane;

    @FXML
    private Pane textPane;

    @FXML
    private Text productName;

    private final String provider;
    private final String comments;
    private final String image;
    private final Boolean paid;
    Set recorCategorii ;
    public ComponentController(int id, String category, String name, int amount, int price, String image,
                               String provider, Boolean paid, String comments,Set categorii) {
        super(id, category, name, amount, price, image);
        this.provider = provider;
        this.paid = paid;
        this.comments = comments;
        this.image = image;
        this.recorCategorii=categorii;
    }
    @FXML
    public Pane initialize(){

        productName.setText(name);
        imagePane.setStyle("-fx-background-image: url(" + image + ");" +
                "-fx-background-repeat: no-repeat;" +
                "-fx-background-size: cover");
        paneContainer.setOnMouseClicked(mouseEvent -> {
            popupController popup=new popupController(id, category, name, amount, price, image,provider,paid,comments,recorCategorii);
            FXMLLoader loader=new FXMLLoader(getClass().getResource("/app/productCard/popup/popup.fxml"));
            loader.setController(popup);
            Stage stage = new Stage();
            Parent dialog = null;
            try{
                dialog=loader.load();
            }catch (IOException ex){
                ex.printStackTrace();
            }
            Scene scene=new Scene(dialog);
            scene.setFill(Color.TRANSPARENT);
            stage.setScene(scene);
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initStyle(StageStyle.TRANSPARENT);


            stage.initOwner( ((Node)mouseEvent.getSource()).getScene().getWindow());
            stage.showAndWait();


        });
        return paneContainer;
    }
}
