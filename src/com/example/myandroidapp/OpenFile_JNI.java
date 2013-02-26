package com.example.myandroidapp;

public class OpenFile_JNI {
	static
	{
		System.loadLibrary("openfile-jni");
	}
	public native String OpenFileFunction_JNI(String msg);
}
