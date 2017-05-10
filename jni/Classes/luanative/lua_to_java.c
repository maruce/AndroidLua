#include "lua_to_java.h"

#define REFECTUTIL_CLASS_NAME  "com/lua/ReflectUtil"

static int _static_call_java(const char * clsname, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME)
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticCall",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn);

	return 1;
}

static int _static_call_d_java(const char * clsname, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME)
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticCallD",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn);

	return 1;
}

static int _call_java(const char * clsname, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME)
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"Call",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn);

	return 1;
}

static int _call_d_java(const char * clsname, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME)
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"CallD",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn);

	return 1;
}