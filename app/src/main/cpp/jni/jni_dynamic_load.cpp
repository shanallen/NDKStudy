//
// Created by 单继强 on 2020-04-29.
//

#include <base.h>
#include <jvm.h>

#define JAVA_CLASS  "com/sjq/learnndk/load/JNIDynamicLoad"

jstring getMessage(JNIEnv *env, jobject jobj) {

    return env->NewStringUTF("this is from msg");
}

jint plus(JNIEnv *env, jobject jobj, int x, int y) {
    return x + y;
}

static JNINativeMethod getMethods[] = {
        {"getNativeString", "()Ljava/lang/String;", (void *) getMessage},
        {"sum",             "(II)I",                (void *) plus}
};

int registerNativeMethods(JNIEnv *env, const char *name,
                          const JNINativeMethod *methods,
                          jint nMethods) {

    jclass jcls;
    jcls = env->FindClass(name);
    if (jcls == nullptr) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(jcls, methods, nMethods) < 0) {

        return JNI_FALSE;
    }
    return JNI_TRUE;
}

extern "C" JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {

        return JNI_FALSE;
    }

    setJvm(vm);
    registerNativeMethods(env, JAVA_CLASS, getMethods, 2);
    LOGI("jni onload call");
    return JNI_VERSION_1_6;
}
