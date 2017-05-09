#include <stdio.h>
#include <jni.h>
#include <android/log.h>

JavaVM* gJVM = NULL;
JNIEnv* gEnv = NULL; 

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	gJVM = vm;
	__android_log_print(ANDROID_LOG_INFO, "lua-jni", "%s", "===============> JNI_OnLoad \n");

	if((*vm)->GetEnv(vm, (void**) &gEnv, JNI_VERSION_1_4) != JNI_OK)
    {
        __android_log_print(ANDROID_LOG_ERROR, "lua-jni", "%s", "Failed to get the environment using GetEnv()");
        return -1;
    }else{
    	__android_log_print(ANDROID_LOG_INFO, "lua-jni", "%s", "Success to get the environment using GetEnv()");
    }

}