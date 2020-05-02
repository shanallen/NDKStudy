//
// Created by 单继强 on 2020-04-30.
//

#include <base.h>
extern "C"
JNIEXPORT jstring JNICALL
Java_com_sjq_learnndk_jni_JNIReferenceType_callNativeStringArray(JNIEnv * env,jobject JNIReferenceType,jobjectArray str_array){

    int len = env->GetArrayLength(str_array);
    LOGD("str_array lengty is %d",len);
     jstring  firstStr = static_cast<jstring>(env->GetObjectArrayElement(str_array, 0));
     const  char *str = env->GetStringUTFChars(firstStr,0);
     LOGD("first item is %s",str);
     env->ReleaseStringUTFChars(firstStr,str);
    return env->NewStringUTF(str);
}