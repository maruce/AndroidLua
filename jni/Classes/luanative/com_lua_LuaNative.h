/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_lua_LuaNative */

#ifndef _Included_com_lua_LuaNative
#define _Included_com_lua_LuaNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_lua_LuaNative
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT jboolean JNICALL Java_com_lua_LuaNative_start
  (JNIEnv *, jclass);

/*
 * Class:     com_lua_LuaNative
 * Method:    onResume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_lua_LuaNative_onResume
  (JNIEnv *, jclass);

/*
 * Class:     com_lua_LuaNative
 * Method:    onPause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_lua_LuaNative_onPause
  (JNIEnv *, jclass);

/*
 * Class:     com_lua_LuaNative
 * Method:    onDestroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_lua_LuaNative_onDestroy
  (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_lua_LuaNative_loop
	(JNIEnv *env, jclass c, jlong dtime);

#ifdef __cplusplus
}
#endif
#endif
