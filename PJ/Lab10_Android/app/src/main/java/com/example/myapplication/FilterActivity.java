package com.example.myapplication;
import android.database.Cursor;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class FilterActivity extends AppCompatActivity {
    EditText inputFrom, inputTo;
    Button btnFilter, btnBack;
    DB myDB;
    TextView filterResult;
    static final int REQUEST_IMAGE_CAPTURE = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_filter);

        myDB = new DB(this);
        inputFrom = (EditText) findViewById(R.id.ageFrom);
        inputTo = (EditText) findViewById(R.id.ageTo);
        btnFilter = (Button) findViewById(R.id.filterBtn);
        btnBack = (Button) findViewById(R.id.btnBack);
        filterResult = (TextView) findViewById(R.id.filterResult);

        btnFilter.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    int from = 0;
                    from = Integer.parseInt(inputFrom.getText().toString());
                    int to = 0;
                    to = Integer.parseInt(inputTo.getText().toString());

                    if(from >= to || from < 0) {
                        filterResult.setText(R.string.valid_range);
                    } else {
                        Cursor res = myDB.getAllData();
                        if (res.getCount() == 0) {
                            filterResult.setText(R.string.no_records_found);
                        } else {
                            StringBuilder buffer = new StringBuilder();
                            while (res.moveToNext()) {
                                if (to > res.getInt(2) && from < res.getInt(2)) {
                                    buffer.append(res.getString(0)).append(",").append(res.getString(1)).append(",").append(res.getString(2)).append("\n");
                                }
                            }
                            if(buffer.length() > 0)
                                filterResult.setText(buffer);
                            else
                                filterResult.setText(R.string.no_records_found);

                        }
                    }
                } catch (Exception e) {
                    filterResult.setText(R.string.error_occured);
                }
            }
        });

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }

}
