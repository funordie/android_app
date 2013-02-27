LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -g
LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello-jni.c

LOCAL_MODULE    := openfile-jni
LOCAL_SRC_FILES := openfile-jni.c
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog 

LOCAL_MODULE    := file-operation-jni
LOCAL_SRC_FILES := file-operation-jni.c

include $(BUILD_SHARED_LIBRARY)