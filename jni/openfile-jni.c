#include <string.h>
#include <jni.h>
#include "com_example_myandroidapp_OpenFile_JNI.h"


JNIEXPORT jstring JNICALL Java_com_example_myandroidapp_OpenFile_1JNI_OpenFile_1JNI
  (JNIEnv *env, jobject thiz, jstring inJNIStr)
{

	char *concatenated;
	const jbyte *sx;
	jstring retval;

	/* Get the UTF-8 characters that represent our java string */
	sx = (*env)->GetStringUTFChars(env, inJNIStr, NULL);

	/* Concatenate the two strings. */
	concatenated = malloc(strlen("asd ") + strlen(sx) + 1);
	strcpy(concatenated, "asd ");
	strcat(concatenated, sx);

	/* Create java string from our concatenated C string */
	retval = (*env)->NewStringUTF(env, concatenated);

	/* Free the memory in sx */
	(*env)->ReleaseStringUTFChars(env, inJNIStr, sx);

	/* Free the memory in concatenated */
	free(concatenated);

	return retval;
}
