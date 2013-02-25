package com.example.myandroidapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.widget.TextView;
import com.example.myandroidapp.Hello_JNI;
import com.example.myandroidapp.OpenFile_JNI;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //Hello_JNI myJNI = new Hello_JNI();
        OpenFile_JNI myOpenFile = new OpenFile_JNI();
        
        TextView tv = new TextView(this);
        //tv.setText(myJNI.messageFromNativeCode());
        tv.setText(myOpenFile.OpenFile_JNI("dev_mem_string"));
        setContentView(tv);
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
}
