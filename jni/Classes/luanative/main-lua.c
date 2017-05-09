#include "global.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua_print.h"

static lua_State * m_Lua = NULL;
static int b_pause = 0;

unsigned char lua_create(){
	if(m_Lua == NULL){
		m_Lua = luaL_newstate();

		if(m_Lua == NULL){
			LOGE("%s","new lua state error!");
		}else{
			LOGI("%s","new a lua state!");
			luaL_openlibs(m_Lua);

			lua_register_print(m_Lua);

			int ret = luaL_dostring(m_Lua,"print('hello lua jni!')");
			if(ret != 0){
				LOGE("%s",luaL_checkstring(m_Lua,-1));
			}
			
			return 1;
		}
	}

	return 0;
}

void lua_on_resume(){
	b_pause = 0;
}
void lua_on_pause(){
	b_pause = 1;
}
void lua_on_destroy(){
	if(m_Lua != NULL){
		lua_close(m_Lua);
		m_Lua = NULL;
	}
}
int lua_on_loop(long dt){
	if(m_Lua != NULL){
		if(b_pause == 0){
			
		}
		return 1;
	}else{
		return 0;
	}
}