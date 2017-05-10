package com.lua;

import android.content.Context;

public class LuaNative {

	native public static void init(Context cxt,String iLuaPath,String eLuaPath);
	native public static boolean start();
	native public static void onResume();
	native public static void onPause();
	native public static void onDestroy();
	native public static void loop(long dtime); 	// 毫秒
	
}
