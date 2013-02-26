package com.example.myandroidapp;

public class OpenFileJNI {
	static
	{
		System.loadLibrary("openfile-jni");
	}
	public native String OpenFileFunctionJNI(String msg);
}
