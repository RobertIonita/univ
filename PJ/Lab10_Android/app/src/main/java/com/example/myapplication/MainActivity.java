package com.example.myapplication;

import android.content.Intent;
import android.database.Cursor;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    EditText editId, editName, editAge;
    Button btnAdd, btnShow, btnUpdate, btnDelete, btnShowByAge;

    DB myDB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myDB = new DB(this);

        editId = (EditText) findViewById(R.id.idInput);
        editName = (EditText) findViewById(R.id.nameInput);
        editAge = (EditText) findViewById(R.id.ageInput);
        btnAdd = (Button) findViewById(R.id.addBtn);
        btnShow = (Button) findViewById(R.id.displayBtn);
        btnUpdate = (Button) findViewById(R.id.updateBtn);
        btnDelete = (Button) findViewById(R.id.deleteBtn);
        btnShowByAge = (Button) findViewById(R.id.gotoFilterBtn);


        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int id = Integer.parseInt(editId.getText().toString());
                String name = editName.getText().toString();
                int age = Integer.parseInt(editAge.getText().toString());
                boolean isInserted = myDB.insert(id, name, age);
                if (isInserted) {
                    editId.setText(String.valueOf(id + 1));
                    Toast.makeText(MainActivity.this, R.string.add_success,
                            Toast.LENGTH_LONG).show();
                } else
                    Toast.makeText(MainActivity.this, R.string.add_error, Toast.LENGTH_LONG).
                            show();
            }
        });
        btnShow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Cursor res = myDB.getAllData();
                if (res.getCount() == 0) {
                    showMessage(String.valueOf(R.string.error), String.valueOf(R.string.no_records_found));

                } else {
                    StringBuilder buffer = new StringBuilder();
                    while (res.moveToNext()) {
                        buffer.append(res.getString(0)).append(",").append(res.getString(1)).append(",").append(res.getString(2)).append("\n");
                    }
                    showMessage(getString(R.string.records), buffer.toString());
                }
            }
        });
        btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int id = Integer.parseInt(editId.getText().toString());
                myDB.delete(id);
                Toast.makeText(MainActivity.this, R.string.delete_success, Toast.LENGTH_LONG).
                        show();
            }
        });
        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String name = editName.getText().toString();
                int age = Integer.parseInt(editAge.getText().toString());
                boolean isUpdated = myDB.update(editId.getText().toString(), name, age);
                if (isUpdated) {
                    Toast.makeText(MainActivity.this, R.string.update_success,
                            Toast.LENGTH_LONG).show();
                } else
                    Toast.makeText(MainActivity.this, R.string.update_error, Toast.LENGTH_LONG).
                            show();
            }
        });
    }

    public void gotoFilter(View v) {
        Intent intent = new Intent(MainActivity.this, FilterActivity.class);
        startActivity(intent);
    }

    public void showMessage(String title, String message) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }
}


