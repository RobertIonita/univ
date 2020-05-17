package app.productCard.popup;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import app.Prototype.Product;
import app.requestHandler.APIHandler;

import java.io.IOException;
import java.util.Set;

public class popupController extends Product {

    @FXML
    private Button updateBtn;

    @FXML
    private Pane deleteBtn;

    @FXML
    private Pane saveBtn;

    @FXML
    private Pane cancelBtn;

    @FXML
    private TextField categoryField;

    @FXML
    private TextField provider;

    @FXML
    private TextField stock;

    @FXML
    private TextField numeProd;

    @FXML
    private Pane imageHolder;

    @FXML
    private Text reportBtn;

    @FXML
    private Pane reportArea;

    @FXML
    private Text alegeComponenta;

    @FXML
    private ComboBox<?> componentsCombo;

    @FXML
    private Pane feedbackHolder;

    @FXML
    private Pane sendBtn;

    @FXML
    private Pane renuntaBtn;

    @FXML
    private Text trimiteTxt;

    @FXML
    private Text renuntaTxt;

    @FXML
    private Pane closeBtn;


    public int recordId,
            recordAmount;
    public String recordCategory,
            recordName,
            recordProvider,
            recordComments,
            recordImage;
    public Set recorCategorii ;
    boolean  recordPaid;
    public popupController(int id, String category, String name, int amount, int price, String image,
                           String provider, Boolean paid, String comments, Set categorii
    ){
        super(id,category,name,amount,price,image);
        this.recordId=id;
        this.recordCategory=category;
        this.recordName=name;
        this.recordProvider=provider;
        this.recordAmount = amount;
        this.recordPaid = paid;
        this.recordComments = comments;
        this.recordImage=image;
        this.recorCategorii=categorii;
    }
    @FXML
    public  void initialize(){

        //componente pentru garantie
        componentsCombo.setItems(FXCollections.observableArrayList(recorCategorii));
        componentsCombo.getSelectionModel().selectFirst();



        reportArea.getChildren().clear();

        numeProd.setText(recordName);
        numeProd.setDisable(true);

        categoryField.setText(recordCategory);
        categoryField.setDisable(true);

        stock.setText(String.valueOf(recordAmount));
        stock.setDisable(true);

        provider.setText(recordProvider);
        provider.setDisable(true);

        saveBtn.setVisible(false);
        cancelBtn.setVisible(false);

        imageHolder.setStyle("-fx-background-radius: 15" +
                ";-fx-background-image: url("+recordImage+");" +
                "-fx-background-position: center center;" +
                " -fx-background-repeat: no-repeat;" +
                "-fx-background-size: cover; ");

        //modifica
        updateBtn.setOnMouseClicked(mouseEvent -> {
            numeProd.setDisable(false);
            categoryField.setDisable(false);
            stock.setDisable(false);
            saveBtn.setVisible(true);
            cancelBtn.setVisible(true);
            provider.setDisable(false);
        });
        //save changes
        saveBtn.setOnMouseClicked(mouseEvent -> {
            numeProd.setDisable(true);
            categoryField.setDisable(true);
            provider.setDisable(true);
            stock.setDisable(true);
            saveBtn.setVisible(false);
            System.out.println("update elemente: "+recordId);
            final String UPDATE_PARAMS = "{\n" +
                    "    \"id\": " + recordId + ",\r\n" +
                    "    \"category\": \"" + categoryField.getText() + "\",\r\n" +
                    "    \"name\": \"" + numeProd.getText() + "\",\r\n" +
                    "    \"provider\": \"" + provider.getText() + "\",\r\n" +
                    "    \"amount\": " + Integer.valueOf(stock.getText()) + ",\r\n" +
                    "    \"paid\": " + recordPaid + ",\r\n" +
                    "    \"comments\": \"" + recordComments + "\"\n}";
            try {
                APIHandler.makeRequest("UPDATE","components",UPDATE_PARAMS);
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
        //cancel btn
        cancelBtn.setOnMouseClicked(mouseEvent -> {
            numeProd.setDisable(true);
            categoryField.setDisable(true);
            provider.setDisable(true);
            stock.setDisable(true);
            saveBtn.setVisible(false);
            cancelBtn.setVisible(false);
        });
        //delete btn
        deleteBtn.setOnMouseClicked(mouseEvent -> {
            final String DELETE_PARAMS="{\n" +
                    "    \"id\": " + recordId + ",\r\n" +
                    "    \"name\": \"" + numeProd.getText() + "\""+"\n}" ;
            try{
                APIHandler.makeRequest("DELETE","components",DELETE_PARAMS);
            }catch (IOException ex){
                ex.printStackTrace();
            }
            Stage stage = (Stage) ((Node)mouseEvent.getSource()).getScene().getWindow();
            // do what you have to do
            stage.close();
        });
        closeBtn.setOnMouseClicked(mouseEvent -> {
            Stage stage = (Stage) ((Node)mouseEvent.getSource()).getScene().getWindow();
            // do what you have to do
            stage.close();
        });

        reportBtn.setOnMouseClicked(mouseEvent -> {
            reportArea.getChildren().addAll(alegeComponenta,componentsCombo,feedbackHolder);
        });

        renuntaBtn.setOnMouseClicked(mouseEvent -> {
            reportArea.getChildren().clear();
        });
        

    }


}

