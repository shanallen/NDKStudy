//
// Created by 单继强 on 2020-04-30.
//

#include <base.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIAccessMethod_accessInstanceMethod(JNIEnv * env,jobject instance,jobject animal){


    jclass  cls = env->GetObjectClass(animal);
    jmethodID  mid = env->GetMethodID(cls,"callInstanceMethod","(I)V");
    env->CallVoidMethod(animal,mid,2);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIAccessMethod_accessStatiMethod(JNIEnv *env,jobject instance,jobject animal){


    jclass  cls = env->GetObjectClass(animal);
    jmethodID  mid = env->GetStaticMethodID(cls,"callStaticMethod","(Ljava/lang/String;)Ljava/lang/String;");
    jstring  str = env->NewStringUTF("jstring");
    env->CallStaticObjectMethod(cls,mid,str);
    mid = env->GetStaticMethodID(cls,"callStaticMethod","([Ljava/lang/String;I)Ljava/lang/String;");
    jclass  strClas = env->FindClass("java/lang/String");
    int size = 2;
    jobjectArray  strArray = env->NewObjectArray(size,strClas, nullptr);

    jstring  strItem;
    for(int i= 0;i < size; ++i){
        strItem = env->NewStringUTF("this is str in native");
        env->SetObjectArrayElement(strArray,i,strItem);
    }
    env->CallStaticObjectMethod(cls,mid,strArray,size);

}