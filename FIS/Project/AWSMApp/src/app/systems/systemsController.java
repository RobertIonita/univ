package app.systems;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import app.productCard.ComponentController;


import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.*;

public class systemsController {
    @FXML
    private Text name;

    @FXML
    private Pane Backstage;

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

    public void appendTemplate(ComponentController component,
                               int layoutX, int layoutY) throws IOException {

       FXMLLoader loader=new FXMLLoader(getClass().getResource("/app/productCard/Component.fxml"));
       loader.setController(component);
       Pane componentCard=loader.load();
       componentCard.setLayoutX(layoutX);
       componentCard.setLayoutY(layoutY);
       
        wrapper.getChildren().add(componentCard);

        scroll.setContent(wrapper);


    }
    @FXML
    private void search(ActionEvent event) throws JSONException, IOException {
        wrapper.getChildren().clear();
        int layoutY = 30;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());

        for (int i = 0; i < jsonArray.length(); i++) {

            JSONObject objectInArray = jsonArray.getJSONObject(i);

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            String comments = objectInArray.getString("comments");
            String imgSource = objectInArray.getString("image");

            categorii.add(category);
            int layoutX=50;
            if(i%3==1){
                layoutX=270;
            }else if(i%3==2){
                layoutX=480;
            }
            ComponentController component =
                    new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments,categorii);
            appendTemplate(component,layoutX,layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 270;

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

                int id = objectInArray.getInt("id");
                String category = objectInArray.getString("category");
                String name = objectInArray.getString("name");
                int amount = objectInArray.getInt("amount");
                int price = objectInArray.getInt("price");
                String provider = objectInArray.getString("provider");
                Boolean paid = objectInArray.getString("paid").equals("true");
                String comments = objectInArray.getString("comments");
                String imgSource = objectInArray.getString("image");
                int layoutX=50;
                if(i%3==1){
                    layoutX=270;
                }else if(i%3==2){
                    layoutX=480;
                }
                ComponentController component =
                        new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments,categorii);
                appendTemplate(component,layoutX,layoutY);
                layoutY += (i+1) % 3 != 0 ? 0 : 270;
            }else if(categorieBox.getValue().toString().equalsIgnoreCase("All")){
                int id = objectInArray.getInt("id");
                String category = objectInArray.getString("category");
                String name = objectInArray.getString("name");
                int amount = objectInArray.getInt("amount");
                int price = objectInArray.getInt("price");
                String provider = objectInArray.getString("provider");
                Boolean paid = objectInArray.getString("paid").equals("true");
                String comments = objectInArray.getString("comments");
                String imgSource = objectInArray.getString("image");
                int layoutX=50;
                if(i%3==1){
                    layoutX=270;
                }else if(i%3==2){
                    layoutX=480;
                }
                ComponentController component =
                        new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments,categorii);
                appendTemplate(component,layoutX,layoutY);
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

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            String comments = objectInArray.getString("comments");
            String imgSource = objectInArray.getString("image");

            categorii.add(category);
            int layoutX=50;
            if(i%3==1){
                layoutX=270;
            }else if(i%3==2){
                layoutX=480;
            }
            ComponentController component =
                    new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments,categorii);
            appendTemplate(component,layoutX,layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 270;

        }
    }

    @FXML
    public void initialize() throws JSONException, IOException {


        int layoutY = 30;
        JSONArray jsonArray=new JSONArray(jsonStr.toString());

        for (int i = 0; i < jsonArray.length(); i++) {

            JSONObject objectInArray = jsonArray.getJSONObject(i);

            int id = objectInArray.getInt("id");
            String category = objectInArray.getString("category");
            String name = objectInArray.getString("name");
            int amount = objectInArray.getInt("amount");
            int price = objectInArray.getInt("price");
            String provider = objectInArray.getString("provider");
            Boolean paid = objectInArray.getString("paid").equals("true");
            String comments = objectInArray.getString("comments");
            String imgSource = objectInArray.getString("image");

            categorii.add(category);
            int layoutX=50;
            if(i%3==1){
                layoutX=270;
            }else if(i%3==2){
                layoutX=480;
            }
            ComponentController component =
                    new ComponentController(id, category, name, amount, price, imgSource, provider, paid, comments,categorii);
            appendTemplate(component,layoutX,layoutY);
            layoutY += (i+1) % 3 != 0 ? 0 : 270;

        }


        categorieBox.setItems(FXCollections.observableArrayList(categorii));
        categorieBox.getSelectionModel().selectFirst();
    }
}
