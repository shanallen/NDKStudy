//
// Created by 单继强 on 2020-05-01.
//

#include <base.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIException_nativeInvokeJavaException(JNIEnv *env,jobject instance){

    jclass  cls = env->FindClass("com/sjq/learnndk/jni/JNIException");
    jmethodID  mid = env->GetMethodID(cls,"operation","()I");
    jmethodID mid2 = env->GetMethodID(cls,"<init>","()V");
    jobject obj = env->NewObject(cls,mid2);
    env->CallIntMethod(obj,mid);

    jthrowable  exc = env->ExceptionOccurred();
    if(exc){
        env->ExceptionDescribe();
        env->ExceptionClear();
    }

}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIException_nativeThrowException(JNIEnv *env,jobject instance){

    jclass  cls = env->FindClass("java/lang/IllegalArgumentException");
    env->ThrowNew(cls,"native throw exception");
}