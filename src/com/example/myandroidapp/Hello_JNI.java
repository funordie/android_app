package com.example.myandroidapp;

public class Hello_JNI {
	static
	{
		System.loadLibrary("hello-jni");
	}
	public native String messageFromNativeCode();
}
