#include <string.h>
#include <jni.h>
#include "com_example_myandroidapp_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_myandroidapp_MainActivity_messageFromNativeCode(JNIEnv* env, jobject this)
{
	return (*env)->NewStringUTF(env, "Hello from JNI !");
}
