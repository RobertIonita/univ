package sample;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.util.Pair;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Optional;

public class HomeController {

    public StringBuffer jsonStr = new StringBuffer();
    public int nr_records = 0,
            offset = 0,
            limit = 4,
            current_page = 1,
            total_pages = 1;
    public String API = "https://tonu.rocks/school/PJ_Lab7/api/people";

    public void getRecords(String api, String query) throws IOException {
        URL url = new URL(api + query);
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        jsonStr = new StringBuffer();
        while ((line = reader.readLine()) != null) {
            jsonStr.append(line);
        }
        reader.close();
    }

    @FXML
    private Pane next;
    @FXML
    private Pane previous;
    @FXML
    private Pane last;
    @FXML
    private Pane first;

    public void enableNavigation(Pane btn1, Pane btn2) {
        btn1.getStyleClass().remove("disabled");
        btn2.getStyleClass().remove("disabled");
    }

    public void disableNavigation(Pane btn1, Pane btn2) {
        btn1.getStyleClass().add("disabled");
        btn2.getStyleClass().add("disabled");
    }

    public void getFirstPage() throws IOException, JSONException {
        if (!first.getStyleClass().contains("disabled")) {
            disableNavigation(first, previous);
            enableNavigation(next, last);
            offset = 0;
            current_page = 1;
            getRecords(API, "?offset=" + offset + "&limit=" + limit);
            parseRecords();
        }
    }

    public void getPreviousPage() throws IOException, JSONException {
        if (!first.getStyleClass().contains("disabled")) {
            current_page--;
            if (offset - limit < 0)
                offset = 0;
            else
                offset -= limit;
            if (current_page == 1)
                disableNavigation(first, previous);
            enableNavigation(next, last);
            getRecords(API, "?offset=" + offset + "&limit=" + limit);
            parseRecords();
            System.out.println(offset + " " + current_page);
        }
    }

    public void getNextPage() throws IOException, JSONException {
        if (!next.getStyleClass().contains("disabled")) {
            current_page++;
            if (offset + limit > nr_records)
                offset += nr_records - offset;
            else
                offset += limit;
            if (current_page == total_pages)
                disableNavigation(next, last);
            enableNavigation(first, previous);
            getRecords(API, "?offset=" + offset + "&limit=" + limit);
            parseRecords();
            System.out.println(offset);
        }
    }

    public void getLastPage() throws IOException, JSONException {
        if (!last.getStyleClass().contains("disabled")) {
            enableNavigation(first, previous);
            disableNavigation(next, last);
            offset = nr_records - limit;
            current_page = Math.floorDiv(nr_records, limit) + 1;
            getRecords(API, "?offset=" + offset + "&limit=" + limit);
            parseRecords();
        }
    }


    private void updateBounds() {
        total_pages = Math.floorDiv(nr_records, limit);
        if (nr_records % limit != 0)
            total_pages++;
    }

    public HomeController() throws IOException {
        getRecords(API, "?total");
        nr_records = Integer.parseInt(jsonStr.toString());
        updateBounds();
        if (nr_records <= limit)
            disableNavigation(next, last);
        getRecords(API, "?limit=" + limit);
    }


    @FXML
    private Pane results;

    public void renderRecords(String id, String name, String age, int index, boolean empty) {
        Node record = results.getChildren().get(index);
        ((Label) record.lookup(".record_id")).setText(id);
        ((Label) record.lookup(".record_name")).setText(name);
        ((Label) record.lookup(".record_age")).setText(age);
        if (empty) {
            record.getStyleClass().add("empty");
        } else {
            record.getStyleClass().remove("empty");
        }
    }

    @FXML
    private Label page_nr;

    public void parseRecords() throws JSONException {
        JSONArray jsonArray = new JSONArray(jsonStr.toString());
        int i;
        for (i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            int id = objectInArray.getInt("id");
            String name = objectInArray.getString("name");
            int age = objectInArray.getInt("age");
            renderRecords(Integer.toString(id), name, Integer.toString(age), i, false);
        }
        while (i < limit)
            renderRecords("", "", "", i++, true);
        page_nr.setText("Page " + current_page + " of " + total_pages);
        addClickListeners();
    }

    @FXML
    private Pane header;

    @FXML
    public Pane reset;

    @FXML
    public void initialize() throws JSONException {
        parseRecords();
        addClickListeners();
        headerActions();
        reset.setOnMouseClicked(e -> {
            System.out.println("Reset triggered");
            try {
                reRender("?total", "?limit=" + limit);
            } catch (IOException ex) {
                ex.printStackTrace();
            } catch (JSONException ex) {
                ex.printStackTrace();
            }
        });
    }

    private void reRender(String query1, String query2) throws IOException, JSONException {
        getRecords(API, query1);
        nr_records = Integer.parseInt(jsonStr.toString());
        updateBounds();
        disableNavigation(first, previous);
        if (nr_records <= limit)
            disableNavigation(next, last);
        else
            enableNavigation(next, last);
        getRecords(API, query2);
        parseRecords();
        current_page = 1;
        offset = 0;
    }

    private void headerActions() {
        header.lookup(".icon_add").setOnMouseClicked(e -> {
            try {
                addRecord();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        });
        TextField input = (TextField) header.lookup("TextField");
        input.setOnAction(e -> {
            try {
                searchRecord(input.getText().replace(" ", "%20"));
            } catch (IOException ex) {
                ex.printStackTrace();
            } catch (JSONException ex) {
                ex.printStackTrace();
            }
        });
    }

    private void searchRecord(String name) throws IOException, JSONException {
        reRender("?total&name=" + name, "?name=" + name);
    }

    private void addClickListeners() {
        for (int i = 0; i < limit; i++) {
            Pane pane = (Pane) results.getChildren().get(i);
            String id = ((Label) pane.lookup(".record_id")).getText();
            String name = ((Label) pane.lookup(".record_name")).getText();
            String age = ((Label) pane.lookup(".record_age")).getText();
            pane.lookup(".icon_edit").setOnMouseClicked((e) -> {
                try {
                    editRecord(id, name, age);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            });
            pane.lookup(".icon_remove").setOnMouseClicked((e) -> {
                try {
                    removeRecord(id, name, age);
                } catch (IOException | JSONException ex) {
                    ex.printStackTrace();
                }
            });
        }
    }

    private void removeRecord(String id, String name, String age) throws IOException, JSONException {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setTitle("Confirmation Dialog");
        alert.setHeaderText("Look, do you really want to remove " + name + ", he/she's only " + age);
        alert.setContentText("Are you ok with this?");

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == ButtonType.OK) {
            makeRequest("DELETE", id, name, age);
            nr_records--;
            updateBounds();
        } else {
            System.out.println("Nope");
        }
    }

    private void editRecord(String id, String name, String age) throws IOException {

        Dialog<Pair<String, String>> dialog = new Dialog<>();
        dialog.setTitle("Edit ppl data");
        dialog.setHeaderText("Please insert updated data");
        ButtonType updateBtnType = new ButtonType("Ok", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(updateBtnType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField new_name = new TextField();
        new_name.setPromptText(name);
        TextField new_age = new TextField();
        new_age.setPromptText(age);

        grid.add(new Label("New name:"), 0, 0);
        grid.add(new_name, 1, 0);
        grid.add(new Label("New age:"), 0, 1);
        grid.add(new_age, 1, 1);

        Node editButton = dialog.getDialogPane().lookupButton(updateBtnType);
        editButton.setDisable(true);

        new_name.textProperty().addListener((observable, oldValue, newValue) -> {
            editButton.setDisable(newValue.trim().isEmpty());
        });
        dialog.getDialogPane().setContent(grid);
        Platform.runLater(new_name::requestFocus);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == updateBtnType) {
                return new Pair<>(new_name.getText(), new_age.getText());
            }
            return null;
        });

        Optional<Pair<String, String>> result = dialog.showAndWait();

        result.ifPresent(updated -> {
            String updatedAge = "";
            if (updated.getValue().length() > 0)
                updatedAge = updated.getValue();
            else updatedAge = age;
            System.out.println("New name = " + updated.getKey() + ", New age = " + updatedAge);
            try {
                makeRequest("UPDATE", id, updated.getKey(), updatedAge);
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

    }

    private void makeRequest(String method, String id, String name, String age) throws IOException {
        final String POST_PARAMS = "{\n" +
                "    \"id\": " + id + ",\r\n" +
                "    \"name\": \"" + name + "\",\r\n" +
                "    \"age\": \"" + age + "\"" + "\n}";
        System.out.println(POST_PARAMS);
        String workaroundAPI = API; // JAVA sucks so to handle UPDATE and DELETE requests I've adapted API
        if (method.equals("UPDATE"))
            workaroundAPI += "/update";
        else if (method.equals("DELETE"))
            workaroundAPI += "/delete";
        URL url = new URL(workaroundAPI);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("PUT");
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);
        OutputStream os = conn.getOutputStream();
        os.write(POST_PARAMS.getBytes());
        os.flush();
        os.close();
        int responseCode = conn.getResponseCode();
        System.out.println(method + " Response Code :  " + responseCode);
        System.out.println(method + " Response Message : " + conn.getResponseMessage());
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
            nr_records++;
        } else {
            System.out.println(method + " NOT WORKED");
        }
    }

    @FXML
    public Pane add;

    private void addRecord() throws IOException {
        Dialog<Pair<String, String>> dialog = new Dialog<>();
        dialog.setTitle("Add new ppl");
        dialog.setHeaderText("Please insert ppl data");
        ButtonType updateBtnType = new ButtonType("Ok", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(updateBtnType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField new_name = new TextField();
        new_name.setPromptText("Name");
        TextField new_age = new TextField();
        new_age.setPromptText("Age");

        grid.add(new Label("Name:"), 0, 0);
        grid.add(new_name, 1, 0);
        grid.add(new Label("Age:"), 0, 1);
        grid.add(new_age, 1, 1);

        Node addButton = dialog.getDialogPane().lookupButton(updateBtnType);
        addButton.setDisable(true);

        new_name.textProperty().addListener((observable, oldValue, newValue) -> {
            addButton.setDisable(newValue.trim().isEmpty());
        });
        dialog.getDialogPane().setContent(grid);
        Platform.runLater(new_name::requestFocus);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == updateBtnType) {
                return new Pair<>(new_name.getText(), new_age.getText());
            }
            return null;
        });

        Optional<Pair<String, String>> result = dialog.showAndWait();

        result.ifPresent(collected -> {
            System.out.println("Name = " + collected.getKey() + ", Age = " + collected.getValue());
            try {
                makeRequest("PUT", "-1", collected.getKey(), collected.getValue());
                nr_records++;
                updateBounds();
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
    }
}
