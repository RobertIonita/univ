package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

public class graphController {
    @FXML
    private Text numeProd;

    @FXML
    private Text cantitateProd;
    @FXML
    private Label denumireProd;
    @FXML
    private Text stocProd;

    @FXML
    private TextField codeInput;
    @FXML
    private Pane placeit;
    @FXML
    private Text nume;

    @FXML
    private Text idProdus;
    @FXML
    private Pane description;

    public StringBuffer jsonStr = new StringBuffer();
    public graphController() throws IOException {
        URL url = new URL("https://tonu.rocks/school/AWSMApp/api/components.php");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }


    private boolean show=false;
    @FXML
    public void appendTemplate(String name, String count,String id) throws IOException {
          int layoutX=832;
          int layoutY=611;

        Pane paneContainer = new Pane();
        // paneContainer.setPrefSize(810,710);
        paneContainer.setLayoutX(0);
        paneContainer.setLayoutY(0);
        paneContainer.setVisible(true);

        //designul la carduri
        Pane pane=new Pane();
        pane.setStyle("-fx-background-color:  #0083FD; -fx-background-radius:  15; -fx-effect:dropshadow(gaussian,rgba(8,88,207,0.08),7,0,0,5 );-fx-background-position: top ");
        pane.setPrefSize(174, 192);

        Pane textBg=new Pane();
        textBg.setStyle("-fx-background-color: #FFFFFF; -fx-background-radius: 0 0 15 15;-fx-background-position: bottom ");
        textBg.setPrefSize(174,55);
        textBg.setLayoutY(137);


        numeProd = new Text(name);
        numeProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 15;-fx-background-color:#636363 ");
        numeProd.setLayoutX(7);
        numeProd.setLayoutY(20);

        nume=new Text("denumire produs: "+name);
        nume.setStyle("-fx-fill: #bebebe; -fx-font-family: 'Arial Black';-fx-font-size: 11");
        nume.setLayoutX(7);
        nume.setLayoutY(40);


        cantitateProd = new Text(count);
        cantitateProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 11;-fx-background-color:#bebebe ");
        cantitateProd.setLayoutX(7);
        cantitateProd.setLayoutY(37);
        ///
        stocProd=new Text("stoc magazin: "+count);
        stocProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 11;-fx-fill: #bebebe ");
        stocProd.setLayoutX(7);
        stocProd.setLayoutY(80);

        idProdus=new Text("idProdus: "+id);
        idProdus.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 11;-fx-fill: #bebebe ");
        idProdus.setLayoutX(7);
        idProdus.setLayoutY(120);

        textBg.getChildren().add(numeProd);
        textBg.getChildren().add(cantitateProd);
        pane.getChildren().add(textBg);

        paneContainer.getChildren().add(pane);
        //paneContainer.getStyleClass().add("wrp");



        placeit.setVisible(true);
        placeit.getChildren().add(paneContainer);

        description.setVisible(true);
        description.getChildren().clear();
        description.getChildren().add(nume);
        description.getChildren().add(stocProd);
        description.getChildren().add(idProdus);




    }



    @FXML
    private void search(ActionEvent event) throws JSONException, IOException {

        placeit.setVisible(false);
        description.setVisible(false);
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {



            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

            if (codeInput.getText().equalsIgnoreCase(String.valueOf(objectInArray.getString("name")))) {




                System.out.printf("%d ELEMENTS IN CURRENT OBJECT:\n", elementNames.length);
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

        appendTemplate(objectInArray.getString("name"), count.toString(),id.toString());

        }

     }



    }

}
