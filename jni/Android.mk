# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Lua

CLSDIR 			= Classes

LUADIR 			= $(CLSDIR)/lua

LUASRC 			:= $(LUADIR)/lapi.c
LUASRC 			+= $(LUADIR)/lauxlib.c
LUASRC 			+= $(LUADIR)/lbaselib.c
LUASRC 			+= $(LUADIR)/lbitlib.c
LUASRC 			+= $(LUADIR)/lcode.c
LUASRC 			+= $(LUADIR)/lcorolib.c
LUASRC 			+= $(LUADIR)/lctype.c
LUASRC 			+= $(LUADIR)/ldblib.c
LUASRC 			+= $(LUADIR)/ldebug.c
LUASRC 			+= $(LUADIR)/ldo.c
LUASRC 			+= $(LUADIR)/ldump.c
LUASRC 			+= $(LUADIR)/lfunc.c
LUASRC 			+= $(LUADIR)/lgc.c
LUASRC 			+= $(LUADIR)/linit.c
LUASRC 			+= $(LUADIR)/liolib.c
LUASRC 			+= $(LUADIR)/llex.c
LUASRC 			+= $(LUADIR)/lmathlib.c
LUASRC 			+= $(LUADIR)/lmem.c
LUASRC 			+= $(LUADIR)/loadlib.c
LUASRC 			+= $(LUADIR)/lobject.c
LUASRC 			+= $(LUADIR)/lopcodes.c
LUASRC 			+= $(LUADIR)/loslib.c
LUASRC 			+= $(LUADIR)/lparser.c
LUASRC 			+= $(LUADIR)/lstate.c
LUASRC 			+= $(LUADIR)/lstring.c
LUASRC 			+= $(LUADIR)/lstrlib.c
LUASRC 			+= $(LUADIR)/ltable.c
LUASRC 			+= $(LUADIR)/ltablib.c
LUASRC 			+= $(LUADIR)/ltm.c
# LUASRC 			+= $(LUADIR)/lua.c
# LUASRC 			+= $(LUADIR)/luac.c
LUASRC 			+= $(LUADIR)/lundump.c
LUASRC 			+= $(LUADIR)/lutf8lib.c
LUASRC 			+= $(LUADIR)/lvm.c
LUASRC 			+= $(LUADIR)/lzio.c

LUANATIVEDIR 	= $(CLSDIR)/luanative

LOCAL_LDLIBS    := -llog -ldl

LOCAL_CFLAGS	+= -O2 -Wall -Wextra
LOCAL_CFLAGS	:= -D"lua_getlocaledecpoint()=('.')"
LOCAL_CFLAGS	+= -DLUA_USE_POSIX
#LOCAL_CFLAGS	+= -DLUA_USE_DLOPEN

LOCAL_C_INCLUDES 	:= $(LOCAL_PATH)
LOCAL_C_INCLUDES	+= $(LOCAL_PATH)/$(CLSDIR)
LOCAL_C_INCLUDES	+= $(LOCAL_PATH)/$(LUADIR)
LOCAL_C_INCLUDES	+= $(LOCAL_PATH)/$(LUANATIVEDIR)

LOCAL_SRC_FILES := $(LUASRC) main-jni.c
LOCAL_SRC_FILES += log2.c

# luanative
LOCAL_SRC_FILES += $(LUANATIVEDIR)/com_lua_LuaNative.c
LOCAL_SRC_FILES += $(LUANATIVEDIR)/lua_print.c
LOCAL_SRC_FILES += $(LUANATIVEDIR)/main-lua.c

include $(BUILD_SHARED_LIBRARY)

