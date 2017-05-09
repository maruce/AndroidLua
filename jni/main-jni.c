#include "global.h"

JavaVM* gJVM = NULL;
JNIEnv* gEnv = NULL;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	gJVM = vm;
	LOGI("%s", "===============> JNI_OnLoad \n");

	if((*vm)->GetEnv(vm, (void**) &gEnv, REQUIRE_JNI_VERSION) != JNI_OK)
    {
        LOGE("%s", "Failed to get the environment using GetEnv()");
        return -1;
    }else{
    	LOGI("%s", "Success to get the environment using GetEnv()");
    }

    return REQUIRE_JNI_VERSION;
}