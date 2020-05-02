package com.sjq.learnndk.jni;

import com.sjq.learnndk.jni.base.ICallbackMethod;
import com.sjq.learnndk.jni.base.IThreadCallback;

public class JNIInvokeMethod {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native void nativeCallback(ICallbackMethod callback);

    public native void nativeThreadCallback(IThreadCallback callback);

}
