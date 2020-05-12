package com.example.lab10;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.json.JSONException;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity {
    private static String API = "http://tonu.rocks/school/PJ_Lab10/api/people";

    private void showMessage(String title, String message) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }

    OkHttpClient okHttpClient = new OkHttpClient();

    private void makeGetRequest() {
        Request request = new Request.Builder()
                .url(API)
                .build();
        okHttpClient.newCall(request).enqueue(new Callback() {

            @Override
            public void onFailure(Call call, IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(Call call, final Response response) throws IOException {
                if (response.isSuccessful()) {
                    MainActivity.this.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                APIHandler.parseResponse(response);
                            } catch (IOException | JSONException e) {
                                e.printStackTrace();
                            }
                        }
                    });
                }
            }
        });
    }

    private void makePostRequest() throws IOException {
        // test data
        final String REQUEST_BODY = "{\n" +
                "    \"id\": " + R.id.idInput + ",\r\n" +
                "    \"name\": " + R.id.nameInput + ",\r\n" +
                "    \"age\": " + R.id.ageInput + "" + "\n}";

        RequestBody body = RequestBody.create(MediaType.parse("application/json; charset=utf-8"), REQUEST_BODY);
        Request request = new Request.Builder()
                .url(API)
                .put(body)
                .build();

        Call call = okHttpClient.newCall(request);
        okHttpClient.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                call.cancel();
            }

            @Override
            public void onResponse(Call call, final Response response) throws IOException {
                try {
                    APIHandler.parseResponse(response);
                    if (response.code() == 200)
                        Toast.makeText(MainActivity.this, R.string.add_record_success, Toast.LENGTH_LONG).show();
                    else
                        Toast.makeText(MainActivity.this, R.string.add_record_error, Toast.LENGTH_LONG).show();
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    EditText editId, editName, editAge;
    Button addBtn, displayBtn, updateBtn, deleteBtn;

    @SuppressLint("WrongThread")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editId = (EditText) findViewById(R.id.idInput);
        editName = (EditText) findViewById(R.id.nameInput);
        editAge = (EditText) findViewById(R.id.ageInput);
        addBtn = (Button) findViewById(R.id.addBtn);
        displayBtn = (Button) findViewById(R.id.displayBtn);
        updateBtn = (Button) findViewById(R.id.updateBtn);
        deleteBtn = (Button) findViewById(R.id.deleteBtn);

        makeGetRequest();

//        System.out.println(APIHandler.people.get(0).toString());

        addBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this, "clicked", Toast.LENGTH_LONG).show();
                try {
                    makePostRequest();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        updateBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int id = Integer.parseInt(editId.getText().toString());
                String name = editName.getText().toString();
                int age = Integer.parseInt(editAge.getText().toString());
                boolean isUpdated = false;
                try {
                    isUpdated = APIHandler.makeRequest("UPDATE", id, name, age);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (isUpdated)
                    Toast.makeText(MainActivity.this, R.string.add_record_success,
                            Toast.LENGTH_LONG).show();
                else
                    Toast.makeText(MainActivity.this, R.string.add_record_error, Toast.LENGTH_LONG).show();
            }
        });
    }
}
