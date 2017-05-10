#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <string.h>

#include "global.h"
#include "lua_file_io.h"

static const char * BYTECODE_FILE_EXT       = ".luac";
static const char * NOT_BYTECODE_FILE_EXT   = ".lua";

static int lua_loader(lua_State *L)
{
    char filename[256] = {0};
    const char * fn = luaL_checkstring(L, 1);
    strcat(filename,fn);

    int mod = -1;
    
    int pos = -1;
    const char * ret = strstr(filename,BYTECODE_FILE_EXT);
    if(ret){
        pos = strlen(filename) - strlen(ret);
    }

    if (pos != -1)
    {
        memset(filename + pos,0,256 - pos);
        mod = 0;
    }
    else
    {
        ret = strstr(filename,NOT_BYTECODE_FILE_EXT);

        if(ret){
            pos = strlen(filename) - strlen(ret);
            if(strlen(NOT_BYTECODE_FILE_EXT) == strlen(ret)){
                memset(filename + pos,0,256 - pos);
                mod = 1;
            }
        }
    }

    // 替换 '.'' -> '/'
    pos = 0;
    while(filename[pos] != '\0'){
        if(filename[pos] == '.')
            filename[pos] = '/';
        pos++;
    }

    if(mod == 0){
        strcat(filename,BYTECODE_FILE_EXT);
    }else{
        strcat(filename,NOT_BYTECODE_FILE_EXT);
    }

    void * data = NULL;
    long dataLen = -1;

    if(data == NULL && file_util_external_exists(filename)){
        data = file_util_external_read(filename,&dataLen);
    }

    if(data == NULL && file_util_internal_exists(filename)){
        data = file_util_internal_read(filename,&dataLen);
    }

    if(data != NULL){
        luaL_loadbuffer(L, (const char *)data, dataLen, filename);
        free(data);
        return 1;
    }else{
        LOGE("can not find lua file:%s",filename);
        return 0;
    }
}

static void _register_loader(lua_State * L, lua_CFunction func)
{
    if (!func) return;

    lua_getglobal(L, "package");
    lua_getfield(L, -1, "searchers");

    lua_pushcfunction(L, func);  
    int i;                                 
    for (i = (int)(lua_rawlen(L, -2) + 1); i > 2; --i)
    {
        lua_rawgeti(L, -2, i - 1);
        lua_rawseti(L, -3, i);
    }
    lua_rawseti(L, -2, 2);

    lua_setfield(L, -2, "searchers");
    
    lua_pop(L, 1);
}

void lua_register_loader(lua_State * L){
    _register_loader(L,lua_loader);
}
