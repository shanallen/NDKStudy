package com.sjq.learnndk.jni;

public class JNIReferenceType {
    static {
        System.loadLibrary("native-lib");
    }

    public native String callNativeStringArray(String[] strArray);
}
