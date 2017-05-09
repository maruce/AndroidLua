#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <jni.h>
#include <android/log.h>

#define LOGTAG "lua-jni"

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOGTAG, ##__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOGTAG, ##__VA_ARGS__) 
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOGTAG, ##__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOGTAG, ##__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOGTAG, ##__VA_ARGS__)

#define REQUIRE_JNI_VERSION JNI_VERSION_1_6

extern JavaVM* gJVM;
extern JNIEnv* gEnv;

#endif // __GLOBAL_H__
