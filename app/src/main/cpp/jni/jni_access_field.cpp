//
// Created by 单继强 on 2020-04-30.
//

#include <base.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIAccessField_accessInstanceField(JNIEnv *env, jobject instance,
                                                             jobject animal) {

    jclass cls = env->GetObjectClass(animal);
    jfieldID fid = env->GetFieldID(cls, "name", "Ljava/lang/String;");
    jstring str = env->NewStringUTF("this is new name");
    env->SetObjectField(animal, fid, str);


}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIAccessField_accessStaticField(JNIEnv *env, jobject instance,
                                                           jobject animal) {

    jclass cls = env->GetObjectClass(animal);
    jfieldID fid = env->GetStaticFieldID(cls, "num", "I");
    int num = env->GetStaticIntField(cls, fid);
    env->SetStaticIntField(cls, fid, ++num);

}


extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_jni_JNIAccessField_staticAccessInstanceField(JNIEnv *env, jclass cls) {
    jfieldID fid = env->GetStaticFieldID(cls, "num", "I");
    int num = env->GetStaticIntField(cls, fid);
    env->SetStaticIntField(cls, fid, ++num);
}