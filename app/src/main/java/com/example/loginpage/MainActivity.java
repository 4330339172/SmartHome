package com.example.loginpage;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import static com.example.loginpage.tools.StringChecker.checkString;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        EditText username=(EditText)findViewById(R.id.username);
        TextView tip=(TextView)findViewById(R.id.tips);
        Button login=(Button)findViewById(R.id.login);
        EditText password=(EditText)findViewById(R.id.password);

        username.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
                if (actionId == EditorInfo.IME_ACTION_NEXT ||
                        (event != null && event.getKeyCode() == KeyEvent.KEYCODE_ENTER && event.getAction() == KeyEvent.ACTION_DOWN)) {
                    password.requestFocus();
                    return true;
                }
                return false;
            }
        });


        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final String tempusername=username.getText().toString();
                final String temppassword=password.getText().toString();
                switch (checkString(tempusername))
                {
                    case 0:{
                        tip.setText("账号不能为空");
                        tip.setVisibility(View.VISIBLE);
                    };break;
                    case -1:{
                        tip.setText("账号不能有特殊字符");
                        tip.setVisibility(View.VISIBLE);
                    };break;
                    default:{
                        if(temppassword.equals("123")&&tempusername.equals("123"))
                        {
                            tip.setVisibility(View.GONE);
                            Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                            startActivity(intent);
                        }
                        else{
                            tip.setText("账号或密码错误");
                            tip.setVisibility(View.VISIBLE);
                        }
                    };break;
                }
            }
        });
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }

}