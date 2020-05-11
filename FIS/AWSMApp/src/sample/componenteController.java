package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.ScrollPane;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

public class componenteController {
    @FXML
    private ScrollPane scroll;

    @FXML
    private AnchorPane wrapper;
    @FXML
    private Pane textBox;

    @FXML
    private Text numeProd;

    @FXML
    private Text cantitateProd;

    public StringBuffer jsonStr = new StringBuffer();
    public componenteController() throws IOException {
        URL url = new URL("https://tonu.rocks/AWSMApp/api/handler.php?table=components");
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML

    public void appendTemplate(String name, String count, int layoutX, int layoutY) throws IOException {

        Pane paneContainer = new Pane();
        // paneContainer.setPrefSize(810,710);
        paneContainer.setLayoutX(layoutX);
        paneContainer.setLayoutY(layoutY);
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

        cantitateProd = new Text(count);
        cantitateProd.setStyle("-fx-font-family: 'Arial Black';-fx-font-size: 11;-fx-background-color:#bebebe ");
        cantitateProd.setLayoutX(7);
        cantitateProd.setLayoutY(37);
        ///

        textBg.getChildren().add(numeProd);
        textBg.getChildren().add(cantitateProd);
        pane.getChildren().add(textBg);

        paneContainer.getChildren().add(pane);
        paneContainer.getStyleClass().add("wrp");

        // selecteaza cardul
        paneContainer.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                System.out.println("a fost selectat produsul: "+name);
            }
        });

        wrapper.getChildren().add(paneContainer);
        scroll.setContent(wrapper);


    }
    @FXML
    public void initialize() throws JSONException, IOException {
        int layoutY = 0;
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        for (int i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            String[] elementNames = JSONObject.getNames(objectInArray);

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
            int layoutX = i % 2 == 0 ? 100 : 300;
            appendTemplate(objectInArray.getString("name"), count.toString(), layoutX, layoutY);

            layoutY += i % 2 == 0 ? 0 : 210;

            System.out.println();
        }
    }

}
