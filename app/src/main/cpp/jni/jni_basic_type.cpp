//
// Created by 单继强 on 2020-04-30.
//
#include <jni.h>
#include <string>
#include "../base/base.h"
extern "C"
JNIEXPORT jint JNICALL
Java_com_sjq_learnndk_jni_JNIBasicType_callNativeInt(JNIEnv *env,jobject jobj,
                                                                            jint num){
    LOGD("java int value is %d",num);
    int c_num = num * 2;
    return c_num;
}

