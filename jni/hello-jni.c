#include <string.h>
#include <jni.h>
#include "com_example_myandroidapp_Hello_JNI.h"

JNIEXPORT jstring JNICALL Java_com_example_myandroidapp_Hello_1JNI_messageFromNativeCode(JNIEnv* env, jobject this)
{
	return (*env)->NewStringUTF(env, "Hello from JNI new !");
}
