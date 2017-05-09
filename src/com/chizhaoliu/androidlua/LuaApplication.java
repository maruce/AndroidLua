package com.chizhaoliu.androidlua;

import android.app.Application;

public class LuaApplication extends Application{

	@Override
	public void onCreate(){
		super.onCreate();
		try{
			System.loadLibrary("Lua");
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
}
