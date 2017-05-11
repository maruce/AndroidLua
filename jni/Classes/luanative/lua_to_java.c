#include "global.h"
#include <stdlib.h>

#define REFECTUTIL_CLASS_NAME  "com/lua/ReflectUtil"

static int _static_call_java(const char * clsname, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
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
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticCallD",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn);

	return 1;
}

static int _static_call_javas(const char * clsname, const char * mname, jobject * out, jobjectArray objArr){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticCall",
		"(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);

	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn,objArr);

	return 1;
}

static int _static_call_d_javas(const char * clsname, const char * mname, jobject * out, jobjectArray objArr){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticCallD",
		"(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);

	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,mn,objArr);

	return 1;
}

static int _call_java(jobject obj, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"Call",
		"(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;");

	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,mn);

	return 1;
}

static int _call_d_java(jobject obj, const char * mname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"CallD",
		"(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;");

	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,mn);

	return 1;
}

static int _call_javas(jobject obj, const char * mname, jobject * out, jobjectArray objArr){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"Call",
		"(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;");

	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,mn,objArr);

	return 1;
}

static int _call_d_javas(jobject obj, const char * mname, jobject * out, jobjectArray objArr){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"CallD",
		"(Ljava/lang/Object;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;");

	jstring mn = (*gEnv)->NewStringUTF(gEnv,mname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,mn,objArr);

	return 1;
}

static int _static_get_java(const char * clsname, const char * fname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticGet",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,fn);

	return 1;
}

static int _static_get_d_java(const char * clsname, const char * fname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticGetD",
		"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,fn);

	return 1;
}

static int _get_java(jobject obj, const char * fname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"Get",
		"(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;");

	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,fn);

	return 1;
}
static int _get_d_java(jobject obj, const char * fname, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"GetD",
		"(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;");

	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,fn);

	return 1;
}
//-------------------------
static int _static_set_java(const char * clsname, const char * fname, jobject val, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticSet",
		"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,fn,val);

	return 1;
}

static int _static_set_d_java(const char * clsname, const char * fname, jobject val, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"StaticSetD",
		"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;");

	jstring cn = (*gEnv)->NewStringUTF(gEnv,clsname);
	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,cn,fn,val);

	return 1;
}

static int _set_java(jobject obj, const char * fname, jobject val, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"Set",
		"(Ljava/lang/Object;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;");

	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,fn,val);

	return 1;
}
static int _set_d_java(jobject obj, const char * fname, jobject val, jobject * out){
	*out = NULL;
	if(gEnv == NULL)return 0;

	jclass cls = (*gEnv)->FindClass(gEnv,REFECTUTIL_CLASS_NAME);
	if(cls == NULL){
		LOGE("can not find class of : %s",REFECTUTIL_CLASS_NAME);
		return 0;
	}

	jmethodID mid = (*gEnv)->GetStaticMethodID(gEnv,cls,"SetD",
		"(Ljava/lang/Object;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/Object;");

	jstring fn = (*gEnv)->NewStringUTF(gEnv,fname);
	*out = (*gEnv)->CallStaticObjectMethod(gEnv,cls,mid,obj,fn,val);

	return 1;
}
void lua_to_java_test(){

	int ret = 0;
	jobject * po = malloc(sizeof(jobject *));
	ret = _static_get_java("com.test.Test","mvalue",po);

	LOGI("lua_to_java_test ret=%d, obj is null ? -> %s",ret,(*po) == NULL ? "true" : "false");

	jclass cls = (*gEnv)->FindClass(gEnv,"java/lang/Integer");

	if(cls != NULL && (*po) != NULL){

		if((*gEnv)->IsInstanceOf(gEnv,*po,cls)){
			LOGI("IsInstanceOf Integer:%s","YES");
		}else{
			LOGI("IsInstanceOf Integer:%s","FALSE");
		}

	}else{
		LOGE("eeeeeeeeeeee");
	}

	free(po);
}
