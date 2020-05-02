//
// Created by 单继强 on 2020-04-30.
//

#include <base.h>
#include <string>
extern "C"
JNIEXPORT jstring JNICALL
Java_com_sjq_learnndk_jni_JNIString_callNativeString(JNIEnv *env, jobject jobj,jstring str_){

    const  char *str = env->GetStringUTFChars(str_, 0);
    LOGD("java string is %s",str);

    env->ReleaseStringUTFChars(str_,str);
    return env->NewStringUTF("this is from C stytle str");

}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIString_stringMethod(JNIEnv *env,jobject JNIString ,jstring jstr){

    const char *str = env->GetStringUTFChars(jstr,0);
    char buf[128];
    int len = env->GetStringLength(jstr);
    LOGD("java string length is %d",len);
    env->GetStringUTFRegion(jstr,0,len-1,buf);
    LOGD("jstring is %s",buf);
    env->ReleaseStringUTFChars(jstr,str);

}
