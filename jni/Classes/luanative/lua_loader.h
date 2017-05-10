#ifndef __LUA_LOADER_H__
#define __LUA_LOADER_H__

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern void lua_register_loader(lua_State * L);

#endif // __LUA_LOADER_H__
