#include <jni.h>
#include <string>
#include "people/People.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_sjq_learnndk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    People people;
    std::string hello = "Hello from C++ mine";
    return env->NewStringUTF(people.getString().c_str());
}
