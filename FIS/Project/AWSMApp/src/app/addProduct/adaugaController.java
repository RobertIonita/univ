package app.addProduct;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

import javax.net.ssl.HttpsURLConnection;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

public class adaugaController {


    @FXML
    private HBox tipProdusHBOX;

    @FXML
    private RadioButton sisteme;

    @FXML
    private ToggleGroup groupTipProdus;

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
    private ToggleGroup groupStatus;

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

    public StringBuffer jsonStr=new StringBuffer();
    private  final String API_Components="https://tonu.rocks/school/AWSMApp/api/components";
    private  final String API_Systems="https://tonu.rocks/school/AWSMApp/api/systems.php";


   public boolean getGroupStatus() {
       RadioButton tipprodus= (RadioButton) groupStatus.getSelectedToggle();
       String text=tipprodus.getText();
       if(text.toLowerCase().contains("platit")){
           return  true;
       }else
           return false;
    }



    @FXML
    void adauga(ActionEvent event) throws IOException {
            if(comp.isSelected()){
                final String POST_PARAMS= "{\n" +
                        "    \"category\": \"" + CategorieProdus.getValue()+ "\",\r\n" +
                        "    \"name\": \"" + denumireProdus.getText() + "\",\r\n" +
                        "    \"provider\": \"" + furnizorProdus.getText() + "\",\r\n" +
                        "    \"amount\": " + cantitateProdus.getValue() + ",\r\n" +
                        "    \"paid\": " + getGroupStatus()+ ",\r\n" +
                        "    \"comments\": \"" + observatii.getText() + "\",\r\n" +
                        "    \"image\": \"" + "no_image.jpg" + "\"" + "\n}";
                System.out.println(POST_PARAMS);
                URL url=new URL(API_Components);
                HttpURLConnection conn= (HttpURLConnection) url.openConnection();
                conn.setRequestMethod("PUT");
                conn.setRequestProperty("Content-Type","application/json");
                conn.setDoOutput(true);
                OutputStream os=conn.getOutputStream();
                os.write(POST_PARAMS.getBytes());
                os.flush();
                os.close();
                int responseCode = conn.getResponseCode();
                System.out.println("Response code: "+responseCode);
                System.out.println("Response message: "+conn.getResponseMessage());
                if(responseCode== HttpsURLConnection.HTTP_OK){

                    BufferedReader in=new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    String inputLine;
                    StringBuilder response=new StringBuilder();
                    while ((inputLine=in.readLine())!=null){
                        response.append(inputLine);
                    }
                    in.close();
                    System.out.println(response);
                }else{
                    System.out.println("POST FAILED");
                }
            }else if(sisteme.isSelected()){
                final String POST_PARAMS= "{\n" +
                        "    \"category\": \"" + CategorieProdus.getValue()+ "\",\r\n" +
                        "    \"name\": \"" + denumireProdus.getText() + "\",\r\n" +
                        "    \"provider\": \"" + furnizorProdus.getText() + "\",\r\n" +
                        "    \"amount\": " + cantitateProdus.getValue() + ",\r\n" +
                        "    \"paid\": " + getGroupStatus()+ ",\r\n" +
                        "    \"comments\": \"" + observatii.getText() + "\",\r\n" +
                        "    \"image\": \"" + "no_image.jpg" + "\"" + "\n}";
                System.out.println(POST_PARAMS);
                URL url=new URL(API_Systems);
                HttpURLConnection conn= (HttpURLConnection) url.openConnection();
                conn.setRequestMethod("PUT");
                conn.setRequestProperty("Content-Type","application/json");
                conn.setDoOutput(true);
                OutputStream os=conn.getOutputStream();
                os.write(POST_PARAMS.getBytes());
                os.flush();
                os.close();
                int responseCode = conn.getResponseCode();
                System.out.println("Response Code: "+responseCode);
                System.out.println("Response Message: "+conn.getResponseMessage());
                if(responseCode == HttpsURLConnection.HTTP_OK){

                    BufferedReader in=new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    String inputLine;
                    StringBuilder response=new StringBuilder();
                    while ((inputLine=in.readLine())!=null){
                        response.append(inputLine);
                    }
                    in.close();
                    System.out.println(response);
                }else{
                    System.out.println("POST FAILED");
                }
            }

    }

    @FXML
    private void logic(){
        cantitateProdus.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(0,100,0,1));
        cantitateProdus.setEditable(true);
        if(comp.isSelected()){

            CategorieProdus.setItems(FXCollections.observableArrayList(
                    "placa video", "placa de baza", "memorie RAM","procesor","hdd", "carcasa"));
            CategorieProdus.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 ); -fx-font-family: 'Arial';-fx-font-size: 13;-fx-text-fill: #bebebe");

            statusHBOX.getChildren().addAll(statusText,platit,waiting);
            observatiiHBOX.getChildren().addAll(observatiiText,observatii);

        }else if(sisteme.isSelected()){
            CategorieProdus.setItems(FXCollections.observableArrayList(
                    "laptop","laptop mini","desktop office","desktop gaming","desktop replacement"));
            CategorieProdus.setStyle("-fx-background-color: FFFFFF;-fx-effect: dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );-fx-font-family: 'Arial';-fx-font-size: 13; -fx-text-fill: #bebebe");
            statusHBOX.getChildren().clear();
            observatiiHBOX.getChildren().clear();

        }
    }



}
