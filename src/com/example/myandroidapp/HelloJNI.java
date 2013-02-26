package com.example.myandroidapp;

public class HelloJNI {
	static
	{
		System.loadLibrary("hello-jni");
	}
	public native String messageFromNativeCode();
}
