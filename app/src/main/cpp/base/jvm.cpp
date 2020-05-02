//
// Created by 单继强 on 2020-04-29.
//

#include <jni.h>
#include "jvm.h"
static JavaVM *gVM = nullptr;
#ifdef __cplusplus
extern "C"{
#endif
    void setJvm(JavaVM *jvm){
        gVM = jvm;
    }
    JavaVM * getJvm(){
        return gVM;
    }
#ifdef __cplusplus

};
#endif
