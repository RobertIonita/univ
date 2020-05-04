package sample;

import com.sun.glass.events.MouseEvent;
import com.sun.glass.ui.EventLoop;
import com.sun.prism.paint.Color;
import javafx.event.ActionEvent;
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
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
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

    public void appendTemplate(String name, String count,String id,int layoutX, int layoutY) throws IOException {

        Pane paneContainer = new Pane();
      // paneContainer.setPrefSize(810,710);
       paneContainer.setLayoutX(layoutX);
       paneContainer.setLayoutY(layoutY);
       paneContainer.setVisible(true);

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
        iv.setFitHeight(300);
        iv.setPreserveRatio(true);
        Pane imgPane= new Pane();
        imgPane.setMaxSize(300,300);
        imgPane.getChildren().add(iv);
        imgPane.setLayoutY(20);
        imgPane.setLayoutX(20);




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

            Pane imgPopupP = new Pane();
            imgPopupP.getChildren().add(imgPane);

            centrum.setCenter(imgPopupP);
            Pane continutPane = new Pane();
            continutPane.setPrefSize(300,300);
            VBox continut = new VBox();

            Text numePopup = new Text("Denumire produs: "+name);
            numePopup.setFont(Font.font("Arial Black",11));

            Text cantPopup = new Text("Denumire produs: "+count);
            cantPopup.setFont(Font.font("Arial Black",11));

            Text idPopup = new Text("Denumire produs: "+id);
            idPopup.setFont(Font.font("Arial Black",11));


            continut.getChildren().add(numePopup);
            continut.getChildren().add(cantPopup);
            continut.getChildren().add(idPopup);
            continut.setSpacing(3);
            continut.setLayoutX(40);
            continut.setLayoutY(20);
            continutPane.getChildren().add(continut);

            centrum.setRight(continutPane);

            //alert dialog



            Alert a = new Alert(Alert.AlertType.NONE);
            // set alert type
            a.setAlertType(Alert.AlertType.INFORMATION);
            a.setHeaderText(null);
            a.setGraphic(null);
            a.setTitle(null);

           DialogPane dialog=a.getDialogPane();
           dialog.setStyle("-fx-background-color: #E6E7E7" );
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
                appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),layoutX,layoutY);
                layoutY += i % 3 == 0 ? 0 : 230;
            }

        }



    }

    @FXML
    public void initialize() throws JSONException, IOException {

        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            String name = objectInArray.getString("name");
            Integer count = objectInArray.getInt("count");
            Integer id=objectInArray.getInt("id");
            int layoutX = i % 2 == 0 ? 100 : 300;
            appendTemplate(objectInArray.getString("name"), count.toString(),id.toString(),layoutX,layoutY);
            layoutY += i % 2 == 0 ? 0 : 230;


        }
    }
}
