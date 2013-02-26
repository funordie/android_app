#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "com_example_myandroidapp_FileOperationJNI.h"
#include <android/log.h>

//global variables
FILE* file;

JNIEXPORT jint JNICALL Java_com_example_myandroidapp_FileOperationJNI_OpenFile
  (JNIEnv *env, jobject thiz, jstring jinpStr, jint perm)
{
	const char * inpStr = (*env)->GetStringUTFChars(env, jinpStr, NULL);
	__android_log_write(ANDROID_LOG_ERROR, "OpenFile:", inpStr );

	switch(perm) {
	case 0:
		//"r"
		__android_log_write(ANDROID_LOG_ERROR, "File Open:", "perm:r");
		file = fopen(inpStr,"r");
		break;

	case 1:
		//"w"
		__android_log_write(ANDROID_LOG_ERROR, "File Open:", "perm:w");
		file = fopen(inpStr,"w");
		break;
	default:
		__android_log_write(ANDROID_LOG_ERROR, "File Open:", "perm:unsupported");
		return -1;
	}

	if (file == NULL) {
		__android_log_write(ANDROID_LOG_ERROR, "File Open:", "cannot open file");
		goto cleanup;
	}
	__android_log_write(ANDROID_LOG_ERROR, "File Open:", "DONE" );
	return 0;

	cleanup:
		(*env)->ReleaseStringUTFChars(env,jinpStr,inpStr);
		return -1;

}

/*
 * Class:     com_example_myandroidapp_FileOperationJNI
 * Method:    CloseFile
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_example_myandroidapp_FileOperationJNI_CloseFile
  (JNIEnv *env, jobject thiz)
{
	if (file == NULL)
		return -1;

	__android_log_write(ANDROID_LOG_ERROR, "Close File:", "DONE" );
	return fclose(file);
}

/*
 * Class:     com_example_myandroidapp_FileOperationJNI
 * Method:    WriteString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_example_myandroidapp_FileOperationJNI_WriteString
  (JNIEnv *env, jobject thiz, jstring jinpStr)
{
	const char * inpStr = (*env)->GetStringUTFChars(env, jinpStr, NULL);
	__android_log_write(ANDROID_LOG_ERROR, "Write string:", inpStr );

	if (file == NULL)
		return -1;

	fputs(inpStr, file);
	fflush(file);
	__android_log_write(ANDROID_LOG_ERROR, "Write string:", "DONE" );
	return 0;
}

/*
 * Class:     com_example_myandroidapp_FileOperationJNI
 * Method:    ReadString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_myandroidapp_FileOperationJNI_ReadString
  (JNIEnv *env, jobject thiz)
{
	char outStr[256];

	fgets ( outStr, 256, file);
	__android_log_write(ANDROID_LOG_ERROR, "Read string:", outStr );
	__android_log_write(ANDROID_LOG_ERROR, "Read string:", "DONE" );
    return (*env)->NewStringUTF(env, outStr);
}
