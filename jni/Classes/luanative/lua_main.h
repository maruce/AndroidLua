#ifndef __MAIN_LUA_H__
#define __MAIN_LUA_H__

extern unsigned char lua_create();
extern void lua_on_resume();
extern void lua_on_pause();
extern void lua_on_destroy();
extern int lua_on_loop(long dt);

#endif //__MAIN_LUA_H__