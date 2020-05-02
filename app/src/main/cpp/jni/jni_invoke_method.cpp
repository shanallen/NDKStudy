//
// Created by 单继强 on 2020-05-01.
//

#include <base.h>
#include <sys/types.h>
#include <pthread.h>
#include <base/jvm.h>

void *threadCallback(void *);
static jclass threadClazz;
static jmethodID threadMethod;
static jobject threadObject;
extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIInvokeMethod_nativeCallback(JNIEnv *env, jobject instance,
                                                         jobject callback) {
    LOGD("nativeCallback");
    jclass callbackClzz = env->GetObjectClass(callback);
    jmethodID callMethodId = env->GetMethodID(callbackClzz, "callback", "()V");
    env->CallVoidMethod(callback, callMethodId);

}

extern "C"
JNIEXPORT void
Java_com_sjq_learnndk_jni_JNIInvokeMethod_nativeThreadCallback(JNIEnv *env, jobject instance,
                                                               jobject callback) {
    threadObject = env->NewGlobalRef(callback);
    threadClazz = env->GetObjectClass(callback);
    threadMethod = env->GetMethodID(threadClazz, "callback", "()V");
    pthread_t handle;
    pthread_create(&handle, nullptr,threadCallback, nullptr);

}

void *threadCallback(void *) {

    JavaVM *gvm = getJvm();
    JNIEnv *env = nullptr;
    if(gvm->AttachCurrentThread(&env, nullptr) == 0){

        env->CallVoidMethod(threadObject,threadMethod);
        gvm->DetachCurrentThread();
    }
    return 0;
}