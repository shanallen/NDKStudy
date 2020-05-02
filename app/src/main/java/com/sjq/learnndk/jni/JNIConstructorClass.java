package com.sjq.learnndk.jni;

import com.sjq.learnndk.bean.Animal;

public class JNIConstructorClass {
    static {
        System.loadLibrary("native-lib");
    }

    public native Animal invokeAnimalConstructors();

    public native Animal allocObjectConstructor();
}
