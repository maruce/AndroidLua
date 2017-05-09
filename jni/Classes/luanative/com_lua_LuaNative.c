#include "global.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <unistd.h>

#include "main-lua.h"

static lua_State * m_Lua = NULL;

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