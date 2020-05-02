package sample;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

public class adaugaController {


    @FXML
    private HBox tipProdusHBOX;

    @FXML
    private RadioButton sisteme;

    @FXML
    private ToggleGroup group;

    @FXML
    private RadioButton comp;

    @FXML
    private HBox categorieHBOX;

    @FXML
    private ChoiceBox<String> CategorieProdus;

    @FXML
    private HBox denumireHBOX;

    @FXML
    private TextField denumireProdus;

    @FXML
    private HBox furnizorHBOX;

    @FXML
    private TextField furnizorProdus;

    @FXML
    private HBox cantitateHBOX;

    @FXML
    private Spinner<Double> cantitateProdus;

    @FXML
    private HBox statusHBOX;

    @FXML
    private RadioButton platit;

    @FXML
    private ToggleGroup group2;

    @FXML
    private RadioButton waiting;

    @FXML
    private HBox observatiiHBOX;

    @FXML
    private TextArea observatii;

    @FXML
    private Button addBtn;
    @FXML
    private Label furnizorText;
    @FXML
    private Label statusText;

    @FXML
    private Label observatiiText;

    @FXML
    private void logic(){
        if(comp.isSelected()){

            CategorieProdus.setItems(FXCollections.observableArrayList(
                    "Placa de baza", "microprocesor", "hdd","carcase","monitor"));
            CategorieProdus.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 ); -fx-font-family: 'Arial';-fx-font-size: 13;-fx-text-fill: #bebebe");

            statusHBOX.getChildren().addAll(statusText,platit,waiting);
            observatiiHBOX.getChildren().addAll(observatiiText,observatii);
            cantitateProdus.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(0,30,0,1));
        }else if(sisteme.isSelected()){
            CategorieProdus.setItems(FXCollections.observableArrayList(
                    "laptop","laptop mini","desktop office","desktop gaming","desktop replacement"));
            CategorieProdus.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );-fx-font-family: 'Arial';-fx-font-size: 13; -fx-text-fill: #bebebe");
            statusHBOX.getChildren().clear();
            observatiiHBOX.getChildren().clear();

            cantitateProdus.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(0,30,0,1));
        }
    }



}
