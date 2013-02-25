package com.example.myandroidapp;

public class OpenFile_JNI {
	static
	{
		System.loadLibrary("openfile-jni");
	}
	public native String OpenFile_JNI(String msg);
}
