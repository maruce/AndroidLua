#include "global.h"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <string.h>

int file_util_internal_exists(const char * filepath){

	if(gAssetMgr == NULL || filepath == NULL || gInternalLuaPath == NULL) return 0;

	char path[256] = {0};
	strcat(path,gInternalLuaPath);
	strcat(path,"/");
	strcat(path,filepath);

	AAsset * asset = AAssetManager_open(gAssetMgr,path,AASSET_MODE_UNKNOWN);

	if(asset){
		AAsset_close(asset);
		return 1;
	}else{
		return 0;
	}
}

int file_util_external_exists(const char * filepath){

	if(filepath == NULL || gExternalLuaPath == NULL) return 0;

	char path[256] = {0};
	strcat(path,gExternalLuaPath);
	strcat(path,"/");
	strcat(path,filepath);

	FILE * fd = fopen(path,"rb");
	if(fd){
		fclose(fd);
		return 1;
	}else{
		return 0;
	}
}

void * file_util_internal_read(const char * filepath,long * readlen){

	*readlen = 0;

	if(gAssetMgr == NULL || filepath == NULL || gInternalLuaPath == NULL) return NULL;

	char path[256] = {0};
	strcat(path,gInternalLuaPath);
	strcat(path,"/");
	strcat(path,filepath);
	AAsset * asset = AAssetManager_open(gAssetMgr,path,AASSET_MODE_UNKNOWN);

	if(asset){

		*readlen = AAsset_getLength(asset);
		void * data = malloc(*readlen + 1);

		if(data == NULL){
			AAsset_close(asset);
			return NULL;
		}

		memset(data,0,*readlen + 1);
		AAsset_read(asset,data,*readlen);
		AAsset_close(asset);
		return data;
	}

	return NULL;
}

void * file_util_external_read(const char * filepath,long * readlen){

	if(filepath == NULL || gExternalLuaPath == NULL) return NULL;

	char path[256] = {0};
	strcat(path,gExternalLuaPath);
	strcat(path,"/");
	strcat(path,filepath);

	FILE * fd = fopen(path,"rb");
	if(fd){
		fseek (fd, 0, SEEK_END);   		//将文件指针移动文件结尾
		*readlen = ftell (fd); 			//求出当前文件指针距离文件开始的字节数

		void * data = malloc(*readlen + 1);

		if(data == NULL){
			fclose(fd);
			return NULL;
		}

		fseek (fd, 0, SEEK_SET);
		memset(data,0,*readlen + 1);
		
		fread(data,1,*readlen,fd);
		fclose(fd);
		return data;
	}

	return NULL;
}
