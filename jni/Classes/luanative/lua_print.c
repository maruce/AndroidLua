#include "global.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <string.h>

static char * _get_message(lua_State * L){
	int nargs = lua_gettop(L);
    
    void * m = malloc(1024);
    memset(m,0,1024);

    char * t = (char *)m;
    int i;
    for (i=1; i <= nargs; i++)
    {
        if (lua_istable(L, i))
            strcat(t,"table");
        else if (lua_isnone(L, i))
            strcat(t,"none");
        else if (lua_isnil(L, i))
            strcat(t,"nil");
        else if (lua_isboolean(L, i))
        {
            if (lua_toboolean(L, i) != 0)
                strcat(t,"true");
            else
                strcat(t,"false");
        }
        else if (lua_isfunction(L, i))
            strcat(t,"function");
        else if (lua_islightuserdata(L, i))
            strcat(t,"lightuserdata");
        else if (lua_isthread(L, i))
            strcat(t,"thread");
        else
        {
            const char * str = lua_tostring(L, i);
            if (str)
                strcat(t,lua_tostring(L, i));
            else
                strcat(t,lua_typename(L, lua_type(L, i)));
        }
        if (i!=nargs)
            strcat(t,"\t");
    }

    return t;
}

static int lua_print(lua_State * L)
{
    char * msg = _get_message(L);
    LOGI("[LUA-print] %s", msg);
    free((void *)msg);
    return 0;
}
static int lua_print_error(lua_State * L)
{
    char * msg = _get_message(L);
    LOGE("[LUA-print] %s", msg);
    free((void *)msg);
    return 0;
}
static int lua_print_debug(lua_State * L)
{
    char * msg = _get_message(L);
    LOGD("[LUA-print] %s", msg);
    free((void *)msg);
    return 0;
}
static int lua_print_verbose(lua_State * L)
{
    char * msg = _get_message(L);
    LOGV("[LUA-print] %s", msg);
    free((void *)msg);
    return 0;
}
static int lua_print_warn(lua_State * L)
{
    char * msg = _get_message(L);
    LOGW("[LUA-print] %s", msg);
    free((void *)msg);
    return 0;
}

int lua_register_print(lua_State * L){
	lua_pushcfunction(L,lua_print);
	lua_setglobal(L,"print");

    lua_getglobal(L,"print");
    lua_setglobal(L,"printi");

	lua_pushcfunction(L,lua_print_error);
	lua_setglobal(L,"printe");

	lua_pushcfunction(L,lua_print_debug);
	lua_setglobal(L,"printd");

	lua_pushcfunction(L,lua_print_verbose);
	lua_setglobal(L,"printv");

	lua_pushcfunction(L,lua_print_warn);
	lua_setglobal(L,"printw");
}


