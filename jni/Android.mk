LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello-jni.c

LOCAL_MODULE    := openfile-jni
LOCAL_SRC_FILES := openfile-jni.c

include $(BUILD_SHARED_LIBRARY)