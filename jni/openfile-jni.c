#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "com_example_myandroidapp_OpenFile_JNI.h"
#include <android/log.h>

JNIEXPORT jstring JNICALL Java_com_example_myandroidapp_OpenFile_1JNI_OpenFileFunction_1JNI
  (JNIEnv *env, jobject thiz, jstring inJNIStr)
{
	char outStr[256];
	int readSize;
    //char logString[50];

	const char * inpStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	__android_log_write(ANDROID_LOG_ERROR, "Tag", inpStr );

	FILE* file = fopen(inpStr,"r");
	if (file == NULL) {
		return (*env)->NewStringUTF(env, "cannot open file");
	}
	else {
		//return (*env)->NewStringUTF(env, "file open success");
		__android_log_write(ANDROID_LOG_ERROR, "Tag", "file open success");
	}
	/*
	if (file != NULL)
	    {
	        fputs("HELLO WORLD!\n", file);
	        fflush(file);
	        fclose(file);
	    }
*/
	fgets ( outStr, 256, file);

	fflush(file);
    fclose(file);

    (*env)->ReleaseStringUTFChars(env,inJNIStr,inpStr);
    return (*env)->NewStringUTF(env, outStr);
}
