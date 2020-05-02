//
// Created by 单继强 on 2020-05-01.
//

#include <base.h>

//局部引用
extern "C"
JNIEXPORT jstring JNICALL
Java_com_sjq_learnndk_jni_JNIReference_errorCacheLocalReference(JNIEnv *env,jobject instance){


//    jclass localRefs = env->FindClass("java/lang/String");
//    jmethodID mid = env->GetMethodID(localRefs,"<init>","(Ljava/lang/String;)V");
//    jstring str = env->NewStringUTF("string");
//    return static_cast<jstring>(env->NewObject(localRefs, mid, str));
}

//全局引用
extern "C"
JNIEXPORT jstring JNICALL
Java_com_sjq_learnndk_jni_JNIReference_cacheWithGlobalReference(JNIEnv *env,jobject instance){

//    static jclass stringClass = nullptr;
//    if(stringClass == nullptr){
//
//        jclass cls = env->FindClass("java/lang/String");
//        stringClass = static_cast<jclass>(env->NewGlobalRef(cls));
//        env->DeleteLocalRef(cls);
//    } else{
//        LOGD("use cached");
//    }
//    jmethodID  mid = env->GetMethodID(stringClass,"<init>","(Ljava/lang/String;)V");
//    jstring str = env->NewStringUTF("string");
//    return static_cast<jstring>(env->NewObject(stringClass, mid, str));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIReference_useWeakGLobalReference(JNIEnv *env,jobject instance){
//    static jclass stringClass = nullptr;
//    if(stringClass == nullptr){
//
//        jclass cls = env->FindClass("java/lang/String");
//        stringClass = static_cast<jclass>(env->NewGlobalRef(cls));
//        env->DeleteLocalRef(cls);
//    } else{
//        LOGD("use cached");
//    }
//    jmethodID  mid = env->GetMethodID(stringClass,"<init>","(Ljava/lang/String;)V");
//    jboolean  isGc = env->IsSameObject(stringClass, nullptr);


}