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
import javafx.geometry.Insets;
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
import javax.net.ssl.HttpsURLConnection;
import javax.swing.*;
import javax.swing.text.Element;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.HttpURLConnection;
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
    private  final String API_Components="https://tonu.rocks/school/AWSMApp/api/components/";
    public StringBuffer jsonStr = new StringBuffer();
    public systemsController() throws IOException {
        URL url = new URL("https://tonu.rocks/school/AWSMApp/api/components/");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    public static void makeRequest(String METHOD, String endpoint, String BODY) throws IOException {
        System.out.println(BODY);
        String API = "https://tonu.rocks/school/AWSMApp/api/" + endpoint;
        if (METHOD.equals("UPDATE")) {
            API = API + "/update";
            METHOD = "PUT";
        }
        System.out.println(API);

        URL url = new URL(API);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod(METHOD);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);
        OutputStream os = conn.getOutputStream();
        os.write(BODY.getBytes());
        os.flush();
        os.close();
        int responseCode = conn.getResponseCode();
        System.out.println(" Response Code :  " + responseCode);
        System.out.println(" Response Message : " + conn.getResponseMessage());
        if (responseCode == HttpURLConnection.HTTP_OK) { //success
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    conn.getInputStream()));
            String inputLine;
            StringBuilder response = new StringBuilder();
            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }
            in.close();
            // print result
            System.out.println(response.toString());
        } else {
            System.out.println(METHOD + " FAILED");
        }
    }
    @FXML

    public void appendTemplate(String name, int count,int id,
                               String category,String provider,String paid,
                               String comment,boolean hasWarranty,String image,
                               int layoutX, int layoutY) throws IOException {

            Pane paneContainer = new Pane();
            paneContainer.setPrefSize(174,250);
            paneContainer.setLayoutX(layoutX);
            paneContainer.setLayoutY(layoutY);
            paneContainer.setVisible(true);

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
               "    -fx-background-size:cover,auto;"+
               "    -fx-background-radius:  15;" +
               "     -fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );" +
               "    -fx-background-position: top ");

       pane.setPrefSize(174, 192);

        //sectiunea de jos a cardului cu numele produsului
        Pane textBg=new Pane();
       textBg.setStyle("-fx-background-color: #FFFFFF; -fx-background-radius: 0 0 15 15;-fx-background-position: bottom ");
       //textBg.setPrefSize(174,55);
       textBg.setPrefWidth(174);
       textBg.setMinHeight(50);
       textBg.setLayoutY(174);

        numeProd = new Text(name);
        numeProd.setStyle("-fx-padding:10 10 10 0;-fx-font-family: 'Gotham Pro Black';-fx-font-size: 14;-fx-background-color:#636363 ");
        numeProd.setWrappingWidth(130);
        numeProd.setLayoutX(15);
        numeProd.setLayoutY(24);
        textBg.getChildren().add(numeProd);



        pane.getChildren().add(textBg);


        paneContainer.getChildren().add(pane);
        paneContainer.getStyleClass().add("card");

        ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //click pe produs
        paneContainer.setOnMouseClicked(mouseEvent -> {
            popupController popup=new popupController(
                    id,category,name,provider,count,
                    paid,comment,image);
            FXMLLoader loader=new FXMLLoader(getClass().getResource("popup.fxml"));
            loader.setController(popup);
            Stage stage=new Stage();

            Parent dialog=null;
            try {

                dialog=loader.load();
            } catch (IOException e) {
                System.out.println("whyy");
                e.printStackTrace();
            }
            stage.setScene(new Scene(dialog));
            stage.setTitle("Pop-up");
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initOwner( ((Node)mouseEvent.getSource()).getScene().getWindow());
            stage.show();
        });
        if(id==2){

            paneContainer.getChildren().add(promo);
        }

        wrapper.getChildren().add(paneContainer);

        scroll.setContent(wrapper);


    }
    @FXML
    private void search(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();

        int layoutY = 30;
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
                int layoutX=50;
                if(i%3==1){
                    layoutX=270;
                }else if(i%3==2){
                    layoutX=480;
                }
                appendTemplate(name, amount,id,category,provider,paid.toString(),comments,true,image,layoutX,layoutY);
                layoutY += (i+1) % 3 != 0 ? 0 : 270;

            }

        }



    }

    @FXML
    public void filter(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();

        int layoutY = 30;
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
                int layoutX=50;
                if(i%3==1){
                    layoutX=270;
                }else if(i%3==2){
                    layoutX=480;
                }
                appendTemplate(name, amount,id,category,provider,paid.toString(),comments,true,image,layoutX,layoutY);
                layoutY += (i+1) % 3 != 0 ? 0 : 270;
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
                int layoutX=50;
                if(i%3==1){
                    layoutX=270;
                }else if(i%3==2){
                    layoutX=480;
                }
                appendTemplate(name, amount,id,category,provider,paid.toString(),comments,true,image,layoutX,layoutY);
                layoutY += (i+1) % 3 != 0 ? 0 : 270;

            }

        }



    }

    @FXML
    void showAll(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 30;
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

            int layoutX=50;
            if(i%3==1){
                layoutX=270;
            }else if(i%3==2){
                layoutX=480;
            }
            appendTemplate(name, amount,id,category,provider,paid.toString(),comments,true,image,layoutX,layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 270;


        }
    }

    @FXML
    public void initialize() throws JSONException, IOException {


        int layoutY = 30;
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
            int layoutX=50;
            if(i%3==1){
                layoutX=270;
            }else if(i%3==2){
                layoutX=480;
            }
            appendTemplate(name, amount,id,category,provider,paid.toString(),comments,true,image,layoutX,layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 270;

            categorii.add(category);
        }


        categorieBox.setItems(FXCollections.observableArrayList(categorii));
        categorieBox.getSelectionModel().selectFirst();
    }
}
