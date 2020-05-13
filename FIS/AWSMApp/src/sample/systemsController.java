package sample;

import com.sun.glass.ui.EventLoop;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.effect.BoxBlur;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;


import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.text.Element;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.URL;
import java.sql.*;
import java.util.*;

public class systemsController {
    @FXML
    private Text name;

    @FXML
    private Pane stage;

    @FXML
    private AnchorPane wrapper;
    @FXML
    private ScrollPane scroll;

    @FXML
    private Pane elements;

    @FXML
    private Pane textBox;

    @FXML
    private Text numeProd;

    @FXML
    private Text cantitateProd;
    @FXML
    private TextField searchBar;
    @FXML
    private ComboBox categorieBox;
    @FXML
    private Button showAll;



    Set categorii =new HashSet();
    public StringBuffer jsonStr = new StringBuffer();
    public systemsController() throws IOException {
        URL url = new URL("https://tonu.rocks/school/AWSMApp/api/components.php");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML

    public void appendTemplate(String name, String count,String id,boolean hasWarranty,String image,int layoutX, int layoutY) throws IOException {


            Pane paneContainer = new Pane();
            // paneContainer.setPrefSize(810,710);
            paneContainer.setLayoutX(layoutX);
            paneContainer.setLayoutY(layoutY);
            paneContainer.setVisible(true);

        //delete btn

            Button deleteBtn = new Button();
            deleteBtn.setStyle("-fx-background-color:#FF4200;\n" +
                    "    -fx-background-radius: 10;\n" +
                    "    -fx-font-style: \"Open Sans SemiBold\";\n" +
                    "    -fx-font-size: 12;\n" +
                    "-fx-text-fill: #FFFFFF;\n" +
                    "    -fx-cursor: hand;");
            deleteBtn.setPrefWidth(100);
            deleteBtn.setPrefHeight(30);
            deleteBtn.setText("Sterge");

        //modifica btn

            Button modificaBtn = new Button();
            modificaBtn.setStyle("-fx-background-color: #FFA000;\n" +
                    "    -fx-background-radius: 10;\n" +
                    "    -fx-font-family: 'Open Sans',11pt;\n" +
                    "    -fx-font-size: 12;\n" +
                    "-fx-text-fill: #FFFFFF;\n" +
                    "    -fx-cursor: hand;");
            modificaBtn.setPrefWidth(100);
            modificaBtn.setPrefHeight(30);
            modificaBtn.setText("Modifica datele");

          ///salveaza modificarile btn
        Button salveazaBtn = new Button();
        salveazaBtn.setStyle("-fx-background-color: #2ED3C6 ;\n" +
                "    -fx-background-radius: 10;\n" +
                "    -fx-font-family: 'Open Sans',11pt;\n" +
                "    -fx-font-size: 12;\n" +
                "-fx-text-fill: #FFFFFF;\n" +
                "    -fx-cursor: hand;");
        salveazaBtn.setPrefWidth(100);
        salveazaBtn.setPrefHeight(30);
        salveazaBtn.setText("Salveaza");
        salveazaBtn.setVisible(false);

        //report warranty

        HBox reportArea = new HBox();
        reportArea.setSpacing(5);

        Label reportTextField = new Label("Raporteaza defect");
        reportTextField.setStyle("-fx-font-family: 'Open Sans' ;\n" +
                "    -fx-text-fill:#0083FD;\n" +
                "    -fx-font-size: 11;\n" +
                "    -fx-cursor: hand;");

        //report combo box
        ComboBox reportTypes= new ComboBox<>();
        reportTypes.setItems(FXCollections.observableArrayList(categorii));
        reportTypes.setVisible(false);
        reportTypes.getSelectionModel().selectFirst();
        reportArea.getChildren().add(reportTextField);
        reportArea.getChildren().add(reportTypes);



       //design promo badge

            Pane promo = new Pane();
            promo.setStyle("-fx-background-color: #FF4200;-fx-background-radius: 3;-fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 )");
            promo.setPrefSize(62, 20);
            promo.setLayoutX(-5);
            promo.setLayoutY(13);

        //text promo

            Text textProm = new Text("promo");
            textProm.setFont(Font.font("Open Sans", 12));
            textProm.setFill(Color.WHITE);
            textProm.setLayoutX(15);
            textProm.setLayoutY(12);
            promo.getChildren().add(textProm);


       //designul la carduri
       Pane pane=new Pane();
       pane.setStyle("-fx-background-image: url("+image+");" +
               "    -fx-background-color: transparent;" +
               "    -fx-background-repeat: no-repeat;"+
               "-fx-background-position: center center;"+
               "    -fx-background-size: cover,auto;"+
               "    -fx-background-radius:  15;" +
               "     -fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );" +
               "    -fx-background-position: top ");

       pane.setPrefSize(174, 192);

        //imaginea produsului cadou
        File produsCadou = new File("F:\\GitHub\\Tonu\\univ\\FIS\\AWSMApp\\src\\sample\\assets\\imprimanta-laser-mono-samsung-sl-m2026.jpg");
        Image img3 = new Image(produsCadou.toURI().toString());
        ImageView iv3=new ImageView();
        iv3.setImage(img3);
        iv3.setFitWidth(150);
        //iv.setFitHeight(300);
        iv3.setPreserveRatio(true);

        //plus icon promo
        File icon = new File("F:\\GitHub\\Tonu\\univ\\FIS\\AWSMApp\\src\\sample\\assets\\ui.png");
        Image imgIcon = new Image(icon.toURI().toString());
        ImageView iv4=new ImageView();
        iv4.setImage(imgIcon);
        iv4.setFitWidth(30);
        //iv.setFitHeight(300);
        iv4.setPreserveRatio(true);
        iv4.setLayoutX(0);
        iv4.setLayoutY(70);

        //container icon
        Pane iconPanes = new Pane();
        iconPanes.setPrefSize(100,150);
        iconPanes.getChildren().add(iv4);
        iconPanes.setLayoutY(0);
        iconPanes.setLayoutX(0);

        //container imagine produs
        Pane imgPane= new Pane();
        imgPane.setPrefSize(300,300);
        imgPane.setStyle("-fx-background-image: url("+image+");" +
                "-fx-background-position: center center;" +
                " -fx-background-repeat: no-repeat;" +
                "-fx-background-size: cover,auto");
        imgPane.setLayoutY(20);
        imgPane.setLayoutX(20);


        //container imagine produs cadou
        Pane imgCadou= new Pane();
        imgCadou.setMaxSize(300,300);
        imgCadou.getChildren().add(iv3);
        imgCadou.setLayoutY(20);
        imgCadou.setLayoutX(0);




        //sectiunea de jos a cardului cu numele produsului
        Pane textBg=new Pane();
       textBg.setStyle("-fx-background-color: #FFFFFF; -fx-background-radius: 0 0 15 15;-fx-background-position: bottom ");
       //textBg.setPrefSize(174,55);
       textBg.setPrefWidth(174);
       textBg.setMinHeight(50);
       textBg.setLayoutY(174);

        numeProd = new Text(name);
        numeProd.setStyle("-fx-padding:10 10 10 0;-fx-font-family: 'Arial Black';-fx-font-size: 12;-fx-background-color:#636363 ");
        numeProd.setWrappingWidth(130);
        numeProd.setLayoutX(15);
        numeProd.setLayoutY(24);
        textBg.getChildren().add(numeProd);



        pane.getChildren().add(textBg);


        paneContainer.getChildren().add(pane);

        paneContainer.getStyleClass().add("card");

        ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //click pe produs
        paneContainer.setOnMouseClicked((e)->{
            BoxBlur blur=new BoxBlur(3,3,3);
            BorderPane centrum = new BorderPane();

            HBox imgPopupP = new HBox();
            imgPopupP.getChildren().add(imgPane);
            if(id.contains("2")){
                imgPopupP.getChildren().add(iconPanes);
                imgPopupP.getChildren().add(imgCadou);
            }


            centrum.setCenter(imgPopupP);
            Pane continutPane = new Pane();
            continutPane.setPrefSize(300,300);
            VBox continut = new VBox();

            VBox garantie=new VBox();
            garantie.setAlignment(Pos.CENTER);
            garantie.setLayoutY(135);
            garantie.setLayoutX(50);

            //denumirea produsului
            HBox numeHXbox = new HBox();
            numeHXbox.setSpacing(5);
            Text numePopup = new Text("Denumire produs:");
            numePopup.setFont(Font.font("Open Sans",14));
            TextArea numePopupField=new TextArea(name);
            numePopupField.setWrapText(true);
            numePopupField.setStyle("-fx-background-color: transparent;-fx-border-color: transparent");
            numePopupField.setMaxWidth(150);
           numePopupField.setPrefHeight(50);
            numePopupField.setEditable(false);
            numeHXbox.getChildren().add(numePopup);
            numeHXbox.getChildren().add(numePopupField);

            //cantitatea produsului
            HBox cantHXBox=new HBox();
            cantHXBox.setSpacing(5);
            Text cantPopup = new Text("Stoc produs: ");
            cantPopup.setFont(Font.font("Open Sans",14));
            TextField cantText = new TextField(count);
            cantText.setMaxWidth(150);
            cantText.setStyle("-fx-background-color: transparent;-fx-border-color: transparent");
            //disable editing
            cantText.setEditable(false);
            cantHXBox.getChildren().add(cantPopup);
            cantHXBox.getChildren().add(cantText);

            //id produs
            HBox idHBox=new HBox();
            idHBox.setSpacing(5);
            Text idPopup = new Text("Cod produs: ");
            idPopup.setFont(Font.font("Open Sans",14));
            TextField idText=new TextField(id);
            idText.setMaxWidth(150);
            idText.setStyle("-fx-background-color: transparent;-fx-border-color: transparent");
            //editable
            idText.setEditable(false);
            idHBox.getChildren().add(idPopup);
            idHBox.getChildren().add(idText);

            Text Beneficii = new Text("Beneficii:");
            Beneficii.setFill(Color.valueOf("#999999"));
            Beneficii.setFont(Font.font("Open Sans",14));
            garantie.getChildren().add(Beneficii);
            garantie.setSpacing(10);

            //sectiunea Warranty
            HBox WarrantyInfo=new HBox();
            File warrantyIconButton = new File("F:\\GitHub\\Tonu\\univ\\FIS\\AWSMApp\\src\\sample\\assets\\business-and-finance.png");
            Image img2 = new Image(warrantyIconButton.toURI().toString());
            ImageView iv2=new ImageView();
            iv2.setImage(img2);
            iv2.setFitWidth(30);
            //iv.setFitHeight(300);
            iv2.setPreserveRatio(true);
            WarrantyInfo.setSpacing(20);
            WarrantyInfo.getChildren().add(iv2);
            VBox raportWarranty = new VBox();
            raportWarranty.setSpacing(5);
            Text textWarranty=new Text("Garantie Inclusa");
            textWarranty.setFont(Font.font("Arial Black",11));
            textWarranty.setFill(Color.BLACK);
            raportWarranty.getChildren().add(textWarranty);
            raportWarranty.getChildren().add(reportArea);

            WarrantyInfo.getChildren().add(raportWarranty);

            //raporteaza defect
            reportTextField.setOnMouseClicked(new EventHandler<MouseEvent>() {
                @Override
                public void handle(MouseEvent mouseEvent) {

                reportTypes.setVisible(true);


            }

            });

            //daca se apasa pe butonul de modificare a datelor ,se deblocheaza textfieldurile
            modificaBtn.setOnAction(event -> {
                numePopupField.setEditable(true);
                cantText.setEditable(true);
                idText.setEditable(true);
                salveazaBtn.setVisible(true);
                deleteBtn.setDisable(true);
            });

            //daca se apasa pe salveaza ,se preiau datele din casete ,se blocheaza casetele si se trimit datele catre baza de date
            salveazaBtn.setOnAction(event -> {
                numePopupField.getText();
                numePopupField.setEditable(false);
                cantText.getText();
                cantText.setEditable(false);
                idText.getText();
                idText.setEditable(false);
                //trebuie de trimis datele catre baza de date
                /*
                Code here
                 */
                salveazaBtn.setVisible(false);
                deleteBtn.setDisable(false);

            });

            if(hasWarranty){
                garantie.getChildren().add(WarrantyInfo);


            }else{
                WarrantyInfo.getChildren().clear();
            }


            continut.getChildren().add(numeHXbox);
            continut.getChildren().add(cantHXBox);
            continut.getChildren().add(idHBox);
           continut.setStyle("-fx-border-style: solid none solid none;-fx-border-width:1; -fx-border-color: #999999");

            continut.setSpacing(3);
            continut.setLayoutX(40);
            continut.setLayoutY(20);

            continutPane.getChildren().add(continut);
            continutPane.getChildren().add(garantie);

            VBox buttons = new VBox();
            buttons.setSpacing(10);
            buttons.getChildren().add(deleteBtn);
            buttons.getChildren().add(modificaBtn);
            buttons.getChildren().add(salveazaBtn);
            buttons.setLayoutX(40);
            buttons.setLayoutY(210);

            continutPane.getChildren().add(buttons);


            centrum.setBottom(continutPane);

            //alert dialog



            Alert a = new Alert(Alert.AlertType.NONE);
            // set alert type
            a.setAlertType(Alert.AlertType.INFORMATION);
            a.setHeaderText(null);
            a.setGraphic(null);
            a.setTitle(null);


           DialogPane dialog=a.getDialogPane();
           dialog.setStyle("-fx-background-color: #FFFFFF" );
           a.initStyle(StageStyle.TRANSPARENT);
            a.getDialogPane().setMinWidth(350);
            a.getDialogPane().setPrefWidth(Control.USE_COMPUTED_SIZE);

            a.getDialogPane().setContent(centrum);

            // show the dialog


            stage.setEffect(blur);
            Optional<ButtonType> result = a.showAndWait();
            ButtonType button = result.orElse(ButtonType.OK);
            

            if(button==ButtonType.OK){
                stage.setEffect(null);

            }



        });

        if(id.contains("2")){

            paneContainer.getChildren().add(promo);
        }

        wrapper.getChildren().add(paneContainer);
        scroll.setContent(wrapper);
    }
    @FXML
    private void search(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();

        int layoutY = 0;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);


            if (objectInArray.getString("name").toLowerCase().contains(searchBar.getText().toLowerCase())) {
                Integer id=objectInArray.getInt("id");
                String category=objectInArray.getString("category");
                String name=objectInArray.getString("name");
                String provider=objectInArray.getString("provider");
                Integer amount=objectInArray.getInt("amount");
                Boolean paid=objectInArray.getBoolean("paid");
                String date=objectInArray.getString("date");
                String comments=objectInArray.getString("comments");
                String image=objectInArray.getString("image");
                int layoutX = i % 2 == 0 ? 100 : 330;
                appendTemplate(name, amount.toString(),id.toString(),true,image,layoutX,layoutY);
                layoutY += i % 2 == 0 ? 0 : 270;
            }

        }



    }

    @FXML
    public void filter(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();

        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            if (categorieBox.getValue().toString().equalsIgnoreCase(String.valueOf(objectInArray.getString("category")))) {

                Integer id=objectInArray.getInt("id");
                String category=objectInArray.getString("category");
                String name=objectInArray.getString("name");
                String provider=objectInArray.getString("provider");
                Integer amount=objectInArray.getInt("amount");
                Boolean paid=objectInArray.getBoolean("paid");
                String date=objectInArray.getString("date");
                String comments=objectInArray.getString("comments");
                String image=objectInArray.getString("image");
                int layoutX = i % 2 == 0 ? 100 : 330;
                appendTemplate(name, amount.toString(),id.toString(),true,image,layoutX,layoutY);
                layoutY += i % 2 == 0 ? 0 : 270;
            }else if(categorieBox.getValue().toString().equalsIgnoreCase("All")){
                Integer id=objectInArray.getInt("id");
                String category=objectInArray.getString("category");
                String name=objectInArray.getString("name");
                String provider=objectInArray.getString("provider");
                Integer amount=objectInArray.getInt("amount");
                Boolean paid=objectInArray.getBoolean("paid");
                String date=objectInArray.getString("date");
                String comments=objectInArray.getString("comments");
                String image=objectInArray.getString("image");
                int layoutX = i % 2 == 0 ? 100 : 330;
                appendTemplate(name, amount.toString(),id.toString(),true,image,layoutX,layoutY);
                layoutY += i % 2 == 0 ? 0 : 270;
            }

        }



    }

    @FXML
    void showAll(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 0;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            Integer id=objectInArray.getInt("id");
            String category=objectInArray.getString("category");
            String name=objectInArray.getString("name");
            String provider=objectInArray.getString("provider");
            Integer amount=objectInArray.getInt("amount");
            Boolean paid=objectInArray.getBoolean("paid");
            String date=objectInArray.getString("date");
            String comments=objectInArray.getString("comments");
            String image=objectInArray.getString("image");

            int layoutX = i % 2 == 0 ? 100 : 330;
            appendTemplate(name, amount.toString(),id.toString(),true,image,layoutX,layoutY);
            layoutY += i % 2 == 0 ? 0 : 270;


        }
    }

    @FXML
    public void initialize() throws JSONException, IOException {


        int layoutY = 0;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);

            Integer id=objectInArray.getInt("id");
            String category=objectInArray.getString("category");
            String name=objectInArray.getString("name");
            String provider=objectInArray.getString("provider");
            Integer amount=objectInArray.getInt("amount");
            Boolean paid=objectInArray.getBoolean("paid");
            String date=objectInArray.getString("date");
            String comments=objectInArray.getString("comments");
            String image=objectInArray.getString("image");
            System.out.println("\n nume:"+image);

            categorii.add(category);



            int layoutX = i % 2 == 0 ? 100 : 330;
            appendTemplate(name, amount.toString(),id.toString(),true,image,layoutX,layoutY);
            layoutY += i % 2 == 0 ? 0 : 270;

            categorii.add(category);
        }


        categorieBox.setItems(FXCollections.observableArrayList(categorii));
        categorieBox.getSelectionModel().selectFirst();
    }
}
