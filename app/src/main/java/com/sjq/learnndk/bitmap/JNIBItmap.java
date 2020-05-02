package com.sjq.learnndk.bitmap;

import android.graphics.Bitmap;

public class JNIBItmap {
    static {
        System.loadLibrary("native-lib");
    }

    public native Bitmap callNativeMirrorBitmap(Bitmap bitmap);
}
