
LUADIR 				= $(CLSDIR)/lua

LUASRC 				:= $(LUADIR)/lapi.c
LUASRC 				+= $(LUADIR)/lauxlib.c
LUASRC 				+= $(LUADIR)/lbaselib.c
LUASRC 				+= $(LUADIR)/lbitlib.c
LUASRC 				+= $(LUADIR)/lcode.c
LUASRC 				+= $(LUADIR)/lcorolib.c
LUASRC 				+= $(LUADIR)/lctype.c
LUASRC 				+= $(LUADIR)/ldblib.c
LUASRC 				+= $(LUADIR)/ldebug.c
LUASRC 				+= $(LUADIR)/ldo.c
LUASRC 				+= $(LUADIR)/ldump.c
LUASRC 				+= $(LUADIR)/lfunc.c
LUASRC 				+= $(LUADIR)/lgc.c
LUASRC 				+= $(LUADIR)/linit.c
LUASRC 				+= $(LUADIR)/liolib.c
LUASRC 				+= $(LUADIR)/llex.c
LUASRC 				+= $(LUADIR)/lmathlib.c
LUASRC 				+= $(LUADIR)/lmem.c
LUASRC 				+= $(LUADIR)/loadlib.c
LUASRC 				+= $(LUADIR)/lobject.c
LUASRC 				+= $(LUADIR)/lopcodes.c
LUASRC 				+= $(LUADIR)/loslib.c
LUASRC 				+= $(LUADIR)/lparser.c
LUASRC 				+= $(LUADIR)/lstate.c
LUASRC 				+= $(LUADIR)/lstring.c
LUASRC 				+= $(LUADIR)/lstrlib.c
LUASRC 				+= $(LUADIR)/ltable.c
LUASRC 				+= $(LUADIR)/ltablib.c
LUASRC 				+= $(LUADIR)/ltm.c
# LUASRC 				+= $(LUADIR)/lua.c
# LUASRC 				+= $(LUADIR)/luac.c
LUASRC 				+= $(LUADIR)/lundump.c
LUASRC 				+= $(LUADIR)/lutf8lib.c
LUASRC 				+= $(LUADIR)/lvm.c
LUASRC 				+= $(LUADIR)/lzio.c

LUASRC 				+= $(LUADIR)/log2.c

LOCAL_LDLIBS 		+= -ldl

LOCAL_CFLAGS		+= -D"lua_getlocaledecpoint()=('.')"
LOCAL_CFLAGS		+= -DLUA_USE_POSIX
#LOCAL_CFLAGS		+= -DLUA_USE_DLOPEN

LOCAL_C_INCLUDES	+= $(LOCAL_PATH)/$(LUADIR)

LOCAL_SRC_FILES 	+= $(LUASRC)
