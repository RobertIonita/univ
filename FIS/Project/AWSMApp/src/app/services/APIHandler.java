package app.services;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class APIHandler {

    private static final String API = "https://tonu.rocks/school/AWSMApp/api/";

    public static StringBuffer getRecords(String endpoint, String query) throws IOException {
        StringBuffer getResponse = new StringBuffer();
        URL url = new URL(API + endpoint + query);
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            getResponse.append(line);
        }
        reader.close();
        System.out.println(getResponse);
        return getResponse;
    }

    public static void makeRequest(String METHOD, String endpoint, String BODY) throws IOException {
        System.out.println(BODY);
        String requestAPI = API + endpoint;
        if (METHOD.equals("UPDATE")) {
            requestAPI = requestAPI + "/update";
            METHOD = "PUT";
        }
        URL url = new URL(requestAPI);
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

    public static String getDashboard() throws IOException {
        StringBuffer getResponse = new StringBuffer();
        URL url = new URL(API);
        BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            getResponse.append(line);
        }
        reader.close();
        return getResponse.toString();
    }
}