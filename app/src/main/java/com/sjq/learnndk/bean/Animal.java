package com.sjq.learnndk.bean;

import android.util.Log;

public class Animal {
    protected String name;
    public static int num = 0;


    public Animal(){

    }
    public Animal(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public static int getNum() {
        return num;
    }

    public static void setNum(int num) {
        Animal.num = num;
    }

    //C++调用Java的实例方法
    public void callInstanceMethod(int num){
        Log.i("-----------","call instance method num is " + num);
    }

    //C++ 调用Java的类方法
    public static String callStaticMethod(String str){
        if(null != str){
            Log.i("-----------","call static method with" + str);
        }else {
            Log.i("-----------","call static method str is null");
        }
        return "";
    }

    public static String callStaticMethod(String[] strs,int num){
        if(null != strs){
            for(String str :strs){

                Log.i("-----------","str in array is " + str);
            }
        }
        return "";
    }
}
