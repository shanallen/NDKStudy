//
// Created by 单继强 on 2020-05-01.
//

#include <base.h>
extern "C"
JNIEXPORT jobject JNICALL
Java_com_sjq_learnndk_jni_JNIConstructorClass_invokeAnimalConstructors(JNIEnv *env,jobject instance){

//    jclass  cls = env->FindClass("com/sjq/learnndk/bean/Animal");
//    jmethodID  mid = env->GetMethodID(cls,"<init>","(Ljava/lang/String;)V");
//    jstring  str = env->NewStringUTF("this is animal name");
//    jobject  animal = env->NewObject(cls,mid,str);
//    return animal;

}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_sjq_learnndk_jni_JNIConstructorClass_allocObjectConstructor(JNIEnv *env,jobject instance){


//    jclass  cls = env->FindClass("com/sjq/learnndk/bean/Animal");
//    jmethodID  mid = env->GetMethodID(cls,"<init>","(Ljava/lang/String;)V");
//    jobject animal = env->AllocObject(cls);
//    jstring  str = env->NewStringUTF("this is animal name 2");
//    env->CallNonvirtualVoidMethod(animal,cls,mid,str);
//    return animal;
}