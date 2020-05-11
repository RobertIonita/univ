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

import javax.swing.*;
import javax.swing.text.Element;
import java.awt.*;
import java.io.*;
import java.net.URL;
import java.util.Optional;

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



    public StringBuffer jsonStr = new StringBuffer();
    public systemsController() throws IOException {
        URL url = new URL("https://tonu.rocks/AWSMApp/api/systems.php");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }





    @FXML

    public void appendTemplate(String name, String count,String id,boolean hasWarranty,int layoutX, int layoutY) throws IOException {



        Pane paneContainer = new Pane();
      // paneContainer.setPrefSize(810,710);
       paneContainer.setLayoutX(layoutX);
       paneContainer.setLayoutY(layoutY);
       paneContainer.setVisible(true);

       //delete btn
        Button deleteBtn=new Button();
        deleteBtn.setStyle("-fx-background-color:#FF4200;\n" +
                "    -fx-background-radius: 10;\n" +
                "    -fx-font-style: \"Open Sans SemiBold\";\n" +
                "    -fx-font-size: 12;\n" +
                "-fx-text-fill: #FFFFFF;\n"+
                "    -fx-cursor: hand;");
        deleteBtn.setPrefWidth(100);
        deleteBtn.setPrefHeight(30);
        deleteBtn.setText("Sterge");

        //modifica btn
        Button modificaBtn=new Button();
        modificaBtn.setStyle("-fx-background-color: #FFA000;\n" +
                "    -fx-background-radius: 10;\n" +
                "    -fx-font-family: 'Open Sans',11pt;\n" +
                "    -fx-font-size: 12;\n" +
                "-fx-text-fill: #FFFFFF;\n"+
                "    -fx-cursor: hand;");
        modificaBtn.setPrefWidth(100);
        modificaBtn.setPrefHeight(30);
        modificaBtn.setText("Modifica datele");

        //report warranty
        HBox reportArea = new HBox();
        reportArea.setSpacing(5);

        Label reportTextField = new Label("Raporteaza defect");
        reportTextField.setStyle("-fx-font-family: 'Open Sans' ;\n" +
                "    -fx-text-fill:#0083FD;\n" +
                "    -fx-font-size: 11;\n" +
                "    -fx-cursor: hand;");

        ComboBox reportTypes = new ComboBox<>();
        reportTypes.setItems(FXCollections.observableArrayList(
                "Placa de baza", "microprocesor", "hdd","carcase","monitor"));
        reportTypes.setVisible(false);
        reportTypes.getSelectionModel().selectFirst();
        reportArea.getChildren().add(reportTextField);
        reportArea.getChildren().add(reportTypes);



       //design promo badge
        Pane promo=new Pane();
        promo.setStyle("-fx-background-color: #FF4200;-fx-background-radius: 3;-fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 )");
        promo.setPrefSize(62,20);
        promo.setLayoutX(-5);
        promo.setLayoutY(13);

        //text promo

        Text textProm = new Text("promo");
        textProm.setFont(Font.font("Open Sans",12));
        textProm.setFill(Color.WHITE);
        textProm.setLayoutX(15);
        textProm.setLayoutY(12);
        promo.getChildren().add(textProm);


       //designul la carduri
       Pane pane=new Pane();
       pane.setStyle("-fx-background-color:  #0083FD; -fx-background-radius:  15; -fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );-fx-background-position: top ");
       pane.setPrefSize(174, 192);

       //imaginea produsului
        File file = new File("F:\\GitHub\\Tonu\\univ\\FIS\\AWSMApp\\src\\sample\\assets\\aw-m15-hd-rollupimage.jfif");
       Image img = new Image(file.toURI().toString());
        ImageView iv=new ImageView();
        iv.setImage(img);
       iv.setFitWidth(300);
       //iv.setFitHeight(300);
        iv.setPreserveRatio(true);

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
        imgPane.setMaxSize(300,300);
        imgPane.getChildren().add(iv);
        imgPane.setLayoutY(20);
        imgPane.setLayoutX(20);

        //container imagine produs cadou
        Pane imgCadou= new Pane();
        imgCadou.setMaxSize(300,300);
        imgCadou.getChildren().add(iv3);
        imgCadou.setLayoutY(20);
        imgCadou.setLayoutX(0);

        Pane textBg=new Pane();
       textBg.setStyle("-fx-background-color: #FFFFFF; -fx-background-radius: 0 0 15 15;-fx-background-position: bottom ");
       textBg.setPrefSize(174,55);
       textBg.setLayoutY(137);

        numeProd = new Text(name);
        numeProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 15;-fx-background-color:#636363 ");
        numeProd.setLayoutX(7);
        numeProd.setLayoutY(20);

        cantitateProd = new Text(count);
        cantitateProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 11;-fx-background-color:#bebebe ");
        cantitateProd.setLayoutX(7);
        cantitateProd.setLayoutY(37);
        ///

        textBg.getChildren().add(numeProd);
        textBg.getChildren().add(cantitateProd);
        pane.getChildren().add(textBg);

        paneContainer.getChildren().add(pane);
        paneContainer.getStyleClass().add("card");

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
            garantie.setLayoutY(100);
            garantie.setLayoutX(40);

            Text numePopup = new Text("Denumire produs: "+name);
            numePopup.setFont(Font.font("Open Sans",14));

            Text cantPopup = new Text("Stoc produs: "+count);
            cantPopup.setFont(Font.font("Open Sans",14));

            Text idPopup = new Text("Cod produs: "+id);
            idPopup.setFont(Font.font("Open Sans",14));

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

            if(hasWarranty){
                garantie.getChildren().add(WarrantyInfo);


            }else{
                WarrantyInfo.getChildren().clear();
            }


            continut.getChildren().add(numePopup);
            continut.getChildren().add(cantPopup);
            continut.getChildren().add(idPopup);
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
            buttons.setLayoutX(40);
            buttons.setLayoutY(200);

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
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            if (searchBar.getText().equalsIgnoreCase(String.valueOf(objectInArray.getString("name")))) {

                for (String elementName : elementNames) {

                    String k = new Integer(8).toString();
                    System.out.print(elementName + " ");
                    try {
                        System.out.println(objectInArray.getInt(elementName));
                    } catch (JSONException e) {
                        System.out.println(objectInArray.getString(elementName));
                    }
                }

                String name = objectInArray.getString("name");
                Integer count = objectInArray.getInt("count");
                Integer id=objectInArray.getInt("id");
                int layoutX = i % 3 == 0 ? 100 : 300;
                appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),true,layoutX,layoutY);
                layoutY += i % 3 == 0 ? 0 : 230;
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

            if (categorieBox.getValue().toString().equalsIgnoreCase(String.valueOf(objectInArray.getString("name")))) {

                for (String elementName : elementNames) {

                    String k = new Integer(8).toString();
                    System.out.print(elementName + " ");
                    try {
                        System.out.println(objectInArray.getInt(elementName));
                    } catch (JSONException e) {
                        System.out.println(objectInArray.getString(elementName));
                    }
                }

                String name = objectInArray.getString("name");
                Integer count = objectInArray.getInt("count");
                Integer id=objectInArray.getInt("id");
                int layoutX = i % 2 == 0 ? 100 : 330;
                appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),true,layoutX,layoutY);
                layoutY += i % 2 == 0 ? 0 : 230;
            }else if(categorieBox.getValue().toString().equalsIgnoreCase("All")){
                for (String elementName : elementNames) {

                    String k = new Integer(8).toString();
                    System.out.print(elementName + " ");
                    try {
                        System.out.println(objectInArray.getInt(elementName));
                    } catch (JSONException e) {
                        System.out.println(objectInArray.getString(elementName));
                    }
                }

                String name = objectInArray.getString("name");
                Integer count = objectInArray.getInt("count");
                Integer id=objectInArray.getInt("id");
                int layoutX = i % 2 == 0 ? 100 : 330;
                appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),true,layoutX,layoutY);
                layoutY += i % 2 == 0 ? 0 : 230;
            }

        }



    }

    @FXML
    void showAll(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            String name = objectInArray.getString("name");
            Integer count = objectInArray.getInt("count");
            Integer id=objectInArray.getInt("id");
            int layoutX = i % 2 == 0 ? 100 : 330;
            appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),true,layoutX,layoutY);
            layoutY += i % 2 == 0 ? 0 : 230;


        }
    }

    @FXML
    public void initialize() throws JSONException, IOException {
        categorieBox.setItems(FXCollections.observableArrayList("All","laptop","laptop mini","desktop office","desktop gaming","desktop replacement"));
        categorieBox.getSelectionModel().selectFirst();

        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            String name = objectInArray.getString("name");
            Integer count = objectInArray.getInt("count");
            Integer id=objectInArray.getInt("id");
            int layoutX = i % 2 == 0 ? 100 : 330;
            appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),true,layoutX,layoutY);
            layoutY += i % 2 == 0 ? 0 : 230;


        }
    }
}
