package com.sjq.learnndk.jni;

public class JNIBasicType {
    static {
        System.loadLibrary("native-lib");
    }

    public native int callNativeInt(int num);
}
