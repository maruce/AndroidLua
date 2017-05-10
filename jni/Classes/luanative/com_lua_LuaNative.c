#include "global.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <unistd.h>

#include "lua_main.h"

void JNICALL Java_com_lua_LuaNative_init(JNIEnv *env, jclass c, jobject ctx, jstring iLuaPath, jstring eLuaPath){
	if(gCtx == NULL){
		gCtx = (*env)->NewGlobalRef(env,ctx);

		jclass cls = (*env)->GetObjectClass(env,ctx);
		jmethodID mid = (*env)->GetMethodID(env,cls,"getAssets","()Landroid/content/res/AssetManager;");
		jobject obj = (*env)->CallObjectMethod(env,ctx,mid);
		gAssetMgr = AAssetManager_fromJava(env,obj);

		gInternalLuaPath = (*env)->GetStringUTFChars(env, iLuaPath, 0);
		gExternalLuaPath = (*env)->GetStringUTFChars(env, eLuaPath, 0);

	}
}

jboolean JNICALL Java_com_lua_LuaNative_start(JNIEnv *env, jclass c)
{
	LOGI("%s","lua native start");

	return lua_create() == 1 ? JNI_TRUE : JNI_FALSE;
}
void JNICALL Java_com_lua_LuaNative_onResume(JNIEnv *env, jclass c)
{
	LOGI("%s","lua native onResume");

	lua_on_resume();
}
void JNICALL Java_com_lua_LuaNative_onPause(JNIEnv *env, jclass c)
{
	LOGI("%s","lua native onPause");

	lua_on_pause();
}
void JNICALL Java_com_lua_LuaNative_onDestroy(JNIEnv *env, jclass c)
{
	LOGI("%s","lua native onDestroy");

	lua_on_destroy();
}

void JNICALL Java_com_lua_LuaNative_loop(JNIEnv *env, jclass c, jlong dtime)
{
	jlong sleep_time = dtime * 1000;

	while(lua_on_loop(dtime)){
		usleep(sleep_time);
	}

	LOGI("%s","on lua native loop end!");
}