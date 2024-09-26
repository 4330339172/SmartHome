package com.example.loginpage;

import android.os.Bundle;
import android.widget.ListView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.example.loginpage.mode.listviewmode;
import com.example.loginpage.tools.JSONReader;
import com.example.loginpage.tools.MyListViewAdapter;

import java.util.List;

public class MyListView extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_my_list_view);

        String jsonString = JSONReader.readJSONFromAsset(this, "data.json");
        List<listviewmode> list = JSONReader.parseJSON(this,jsonString);
        MyListViewAdapter adapter = new MyListViewAdapter(MyListView.this,R.layout.list_mode_view,list);
        ListView listView = (ListView) findViewById(R.id.my_list_view);
        listView.setAdapter(adapter);

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
}