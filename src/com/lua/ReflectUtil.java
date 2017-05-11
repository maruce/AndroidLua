package com.lua;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import android.util.Log;

public class ReflectUtil {
	
	public static Object StaticCall(String cls, String method){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Method[] ms = c.getMethods();
			for(Method m : ms){
				if(m.getName().equals(method)){
					try {
						ret = m.invoke(null);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object StaticCallD(String cls, String method){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Method[] ms = c.getDeclaredMethods();
			for(Method m : ms){
				if(m.getName().equals(method)){
					try {
						ret = m.invoke(null);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object StaticCall(String cls, String method, Object ...objects){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Method[] ms = c.getMethods();
			for(Method m : ms){
				if(m.getName().equals(method)){
					try {
						ret = m.invoke(null,objects);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object StaticCallD(String cls, String method, Object ...objects){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Method[] ms = c.getDeclaredMethods();
			for(Method m : ms){
				if(m.getName().equals(method)){
					try {
						ret = m.invoke(null,objects);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object Call(Object obj, String method){
		
		Object ret = null;
		
		Class cls = obj.getClass();
		Method[] ms = cls.getMethods();
		for(Method m : ms){
			if(m.getName().equals(method)){
				try {
					ret = m.invoke(obj);
					break;
				} catch (Exception e){
					
				}
			}
		}
		
		return ret;
	}
	public static Object CallD(Object obj, String method){
		
		Object ret = null;
		
		Class cls = obj.getClass();
		Method[] ms = cls.getDeclaredMethods();
		for(Method m : ms){
			if(m.getName().equals(method)){
				try {
					ret = m.invoke(obj);
					break;
				} catch (Exception e){
					
				}
			}
		}
		
		return ret;
	}
	public static Object Call(Object obj, String method, Object ...objects){
		
		Object ret = null;
		
		Class cls = obj.getClass();
		Method[] ms = cls.getMethods();
		for(Method m : ms){
			if(m.getName().equals(method)){
				try {
					ret = m.invoke(obj,objects);
					break;
				} catch (Exception e){
					
				}
			}
		}
		
		return ret;
	}
	public static Object CallD(Object obj, String method, Object ...objects){
		
		Object ret = null;
		
		Class cls = obj.getClass();
		Method[] ms = cls.getDeclaredMethods();
		for(Method m : ms){
			if(m.getName().equals(method)){
				try {
					ret = m.invoke(obj,objects);
					break;
				} catch (Exception e){
					
				}
			}
		}
		
		return ret;
	}
	public static Object StaticGet(String cls,String arg){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Field[] fs = c.getFields();
			for(Field f : fs){
				if(f.getName().equals(arg)){
					try {
						ret = f.get(null);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object StaticGetD(String cls,String arg){
		Object ret = null;
		try {
			Class c = Class.forName(cls);
			Field[] fs = c.getDeclaredFields();
			for(Field f : fs){
				if(f.getName().equals(arg)){
					try {
						ret = f.get(null);
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static Object Get(Object obj,String arg){
		Object ret = null;
		Class c = obj.getClass();
		Field[] fs = c.getFields();
		for(Field f : fs){
			if(f.getName().equals(arg)){
				try {
					ret = f.get(obj);
					break;
				} catch (Exception e){
					
				}
			}
		}
		return ret;
	}
	public static Object GetD(Object obj,String arg){
		Object ret = null;
		Class c = obj.getClass();
		Field[] fs = c.getDeclaredFields();
		for(Field f : fs){
			if(f.getName().equals(arg)){
				try {
					ret = f.get(obj);
					break;
				} catch (Exception e){
					
				}
			}
		}
		return ret;
	}
	public static boolean StaticSet(String cls,String arg,Object value){
		boolean ret = false;
		
		try {
			Class c = Class.forName(cls);
			Field[] fs = c.getFields();
			for(Field f : fs){
				if(f.getName().equals(arg)){
					try {
						f.setAccessible(true);
						f.set(null, value);
						ret = true;
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static boolean StaticSetD(String cls,String arg,Object value){
		boolean ret = false;
		
		try {
			Class c = Class.forName(cls);
			Field[] fs = c.getDeclaredFields();
			for(Field f : fs){
				if(f.getName().equals(arg)){
					try {
						f.setAccessible(true);
						f.set(null, value);
						ret = true;
						break;
					} catch (Exception e){
						
					}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ret;
	}
	public static boolean Set(Object obj,String arg,Object value){
		boolean ret = false;
		
		Class c = obj.getClass();
		Field[] fs = c.getDeclaredFields();
		for(Field f : fs){
			if(f.getName().equals(arg)){
				try {
					f.setAccessible(true);
					f.set(obj, value);
					ret = true;
					break;
				} catch (Exception e){
					
				}
			}
		}
		return ret;
	}
	public static boolean SetD(Object obj,String arg,Object value){
		boolean ret = false;
		
		Class c = obj.getClass();
		Field[] fs = c.getDeclaredFields();
		for(Field f : fs){
			if(f.getName().equals(arg)){
				try {
					f.setAccessible(true);
					f.set(obj, value);
					ret = true;
					break;
				} catch (Exception e){
					
				}
			}
		}
		return ret;
	}

}

