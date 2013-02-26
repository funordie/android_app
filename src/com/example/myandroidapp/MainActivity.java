package com.example.myandroidapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //Hello_JNI myJNI = new Hello_JNI();
        //OpenFile_JNI myOpenFile = new OpenFile_JNI();
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
    public void OpenFileCmd(View v) {
        //get text from edit box
    	EditText mEdit;
    	String strFile, strRes;
        mEdit   = (EditText)findViewById(R.id.editText1);
        strFile = mEdit.getText().toString();
    	
    	//call open file 
    	OpenFile_JNI myOpenFile = new OpenFile_JNI();
    	strRes = myOpenFile.OpenFileFunction_JNI(strFile);
    	
    	//send return string to text view
        TextView tv = new TextView(this);
        tv.setText(strRes);
        setContentView(tv);
    }
}
