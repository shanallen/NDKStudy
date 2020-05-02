package com.sjq.learnndk.jni;

import com.sjq.learnndk.bean.Animal;

public class JNIAccessField {
    static {
        System.loadLibrary("native-lib");
    }

    public static int num;
    public native void accessInstanceField(Animal animal);
    public native void accessStaticField(Animal animal);
    public static native void staticAccessInstanceField();
}
