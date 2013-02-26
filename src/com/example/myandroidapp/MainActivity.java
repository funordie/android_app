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
    
    public void ReadFileCmd(View v) {
        //get text from edit box
    	EditText mEdit;
    	String strFile, strRes;
    	int res;
    	TextView mView;
    	
        mEdit   = (EditText)findViewById(R.id.editText1);
        strFile = mEdit.getText().toString();
    	
        //call FileOperation
        FileOperationJNI myFileOp = new FileOperationJNI();
        //open file
        res = myFileOp.OpenFile(strFile, 0);
        if(res == 0) {
	        //read file
	        strRes = myFileOp.ReadString();
	        //close file
	        myFileOp.CloseFile();
        }
        else {
        	strRes = "Cannot open file";
        }
    	//send return string to text view
        mView   = (TextView)findViewById(R.id.textView2);
        mView.setText(strRes);
    }
    
    public void WriteFileCmd(View v) {
        //get text from edit box
    	EditText mEdit;
    	String strWrite, strFile, strRes;
    	int res;
    	TextView mView;
    	
    	strRes = "Write Srting OK!";
    	
    	mEdit   = (EditText)findViewById(R.id.editText1);
        strFile = mEdit.getText().toString();
        
        mEdit   = (EditText)findViewById(R.id.editText2);
        strWrite = mEdit.getText().toString();
    	
        //call FileOperation
        FileOperationJNI myFileOp = new FileOperationJNI();
        //open file
        res = myFileOp.OpenFile(strFile, 1);
        if(res == 0) {
	        //write to file
	        res = myFileOp.WriteString(strWrite);
	        if(res != 0) {
	        	strRes = "Cannot write to file";
	        }
	        //close file
	        myFileOp.CloseFile();
        }
        else {
        	strRes = "Cannot open file";
        }
    	//send return string to text view
        mView   = (TextView)findViewById(R.id.textView2);
        mView.setText(strRes);
    }
}
