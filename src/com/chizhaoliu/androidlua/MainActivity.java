package com.chizhaoliu.androidlua;

import com.lua.LuaNative;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        if(LuaNative.start()){
        	new Thread("lua-thread"){
        		@Override
        		public void run(){
        			LuaNative.loop(1000 / 60);
        		}
        	}.start();
        }
    }
    
    @Override
    protected void onResume(){
    	super.onResume();
    	LuaNative.onResume();
    }
    
    @Override
    protected void onPause(){
    	super.onPause();
    	LuaNative.onPause();
    }
    
    @Override
    protected void onDestroy(){
    	super.onDestroy();
    	LuaNative.onDestroy();
    }
}
