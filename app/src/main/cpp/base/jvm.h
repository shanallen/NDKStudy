//
// Created by 单继强 on 2020-04-29.
//

#ifndef LEARNNDK_JVM_H
#define LEARNNDK_JVM_H

#include <base.h>
#ifdef __cplusplus
extern "C"{
#endif
    void setJvm(JavaVM *jvm);
    JavaVM *getJvm();
#ifdef __cplusplus
};
#endif




#endif //LEARNNDK_JVM_H
