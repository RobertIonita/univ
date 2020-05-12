package com.example.lab10;

import android.annotation.SuppressLint;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

@SuppressLint("Registered")
class APIHandler extends MainActivity {

    private static String API = "https://tonu.rocks/school/PJ_Lab10/api/people";
    private static int nr_records = 0;
    static ArrayList<Person> people = new ArrayList<Person>();

    static void parseResponse(Response response) throws IOException, JSONException {
        assert response.body() != null;
        parseRecords(response.body().string());
    }

    static boolean makeRequest(String method, int id, String name, int age) throws IOException {
        final String REQUEST_BODY = "{\n" +
                "    \"id\": " + id + ",\r\n" +
                "    \"name\": \"" + name + "\",\r\n" +
                "    \"age\": " + age + "" + "\n}";
        System.out.println(REQUEST_BODY);
        String workaroundAPI = API; // JAVA sucks so in order to handle UPDATE and DELETE requests I've adapted API
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
        os.write(REQUEST_BODY.getBytes());
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
            return true;
        } else {
            System.out.println(method + " NOT WORKED");
            return false;
        }
    }


    private static void parseRecords(String jsonStr) throws JSONException {
        JSONArray jsonArray = new JSONArray(jsonStr);
        int i;
        for (i = 0; i < jsonArray.length(); i++) {
            JSONObject objectInArray = jsonArray.getJSONObject(i);
            int id = objectInArray.getInt("id");
            String name = objectInArray.getString("name");
            int age = objectInArray.getInt("age");
            System.out.println(id+", "+name+", "+age);
        }
    }

    APIHandler() throws IOException, JSONException {
//        nr_records = Integer.parseInt(jsonStr.toString());
//        parseRecords();
    }
}
