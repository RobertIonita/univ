package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;

public class AddComponent {
    public StringBuffer jsonStr = new StringBuffer();
    private final String API = "https://tonu.rocks/school/AWSMApp/api/components.php";
    public TextField category;
    public TextField name;
    public TextField provider;
    public TextField amount;
    public TextArea comments;
    public CheckBox paid;

    public void gotoHomeComponent(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("Home.fxml"));
        Scene homeScene = new Scene(root);
        Stage window = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        window.setScene(homeScene);
        window.show();
    }

    public void postComponent(ActionEvent actionEvent) throws IOException {
        final String POST_PARAMS = "{\n" +
                "    \"category\": \"" + category.getText() + "\",\r\n" +
                "    \"name\": \"" + name.getText() + "\",\r\n" +
                "    \"provider\": \"" + provider.getText() + "\",\r\n" +
                "    \"amount\": " + amount.getText() + ",\r\n" +
                "    \"paid\": " + paid.isSelected() + ",\r\n" +
                "    \"comments\": \"" + comments.getText() + "\",\r\n" +
                "    \"image\": \"" + "no_image.jpg" + "\"" + "\n}";

        System.out.println(POST_PARAMS);
        URL url = new URL(API);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("PUT");
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);
        OutputStream os = conn.getOutputStream();
        os.write(POST_PARAMS.getBytes());
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
            System.out.println("POST FAILED");
        }
    }
}
