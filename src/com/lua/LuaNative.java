package com.lua;

public class LuaNative {

	native public static boolean start();
	native public static void onResume();
	native public static void onPause();
	native public static void onDestroy();
	native public static void loop(long dtime); 	// 毫秒
	
}
