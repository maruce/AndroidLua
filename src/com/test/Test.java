package com.test;

import android.util.Log;

public class Test {
	
	public static int mvalue = 100;

	public static int echo(){
		Log.i("Test","echo .........");
		return 100;
	}
	
	public static String echo(int vi){
		Log.i("Test","echo ......... iii");
		return "echo--" + vi;
	}
	
	public static String echo(String vs){
		Log.i("Test","echo ......... sss");
		return "echo s ---" + vs;
	}
	
}
