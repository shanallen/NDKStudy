package com.sjq.learnndk.jni;

import com.sjq.learnndk.bean.Animal;

public class JNIAccessMethod {
    static {
        System.loadLibrary("native-lib");
    }

    public native void accessInstanceMethod(Animal animal);
    public native void accessStatiMethod(Animal animal);
}
