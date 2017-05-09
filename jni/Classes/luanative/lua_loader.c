#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <string.h>

#include "lua_file_io.h"

static const char * BYTECODE_FILE_EXT       = ".luac"
static const char * NOT_BYTECODE_FILE_EXT   = ".lua"

static int lua_loader(lua_State *L)
{
    char filename[256] = {0};
    filename = luaL_checkstring(L, 1);

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
    }else if(mod == 1){
        strcat(filename,NOT_BYTECODE_FILE_EXT);
    }
    
    if(file_util_internal_exists(filename)){

    }else if(file_util_external_exists(filename)){

    }
    
    return 1;
}

void lua_register_loader(lua_State * L, lua_CFunction func)
{
    if (!func) return;
    
    // stack content after the invoking of the function
    // get loader table
    lua_getglobal(L, "package");                                  /* L: package */
    lua_getfield(L, -1, "loaders");                               /* L: package, loaders */
    
    // insert loader into index 2
    lua_pushcfunction(L, func);                                   /* L: package, loaders, func */
    for (int i = (int)(lua_rawlen(L, -2) + 1); i > 2; --i)
    {
        lua_rawgeti(L, -2, i - 1);                                /* L: package, loaders, func, function */
        // we call lua_rawgeti, so the loader table now is at -3
        lua_rawseti(L, -3, i);                                    /* L: package, loaders, func */
    }
    lua_rawseti(L, -2, 2);                                        /* L: package, loaders */
    
    // set loaders into package
    lua_setfield(L, -2, "loaders");                               /* L: package */
    
    lua_pop(L, 1);
}