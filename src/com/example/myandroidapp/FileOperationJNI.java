package com.example.myandroidapp;

public class FileOperationJNI {
	static
	{
		System.loadLibrary("file-operation-jni");
	}
	public native int OpenFile(String msg, int perm);
	public native int CloseFile();
	public native int WriteString(String msg);
	public native String ReadString();
}
