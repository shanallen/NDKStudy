//
// Created by 单继强 on 2020-05-01.
//
#include <base.h>
#include <pthread.h>
#include <stdio.h>
#include <jvm.h>
#include <unistd.h>
#include <queue>


struct ThreadRunArgs{
    int id;
    int result;
};
void *printThreadHello(void *){
    LOGD("hello thread");
    //耗时操作
    return nullptr;
}
void *printThreadArgs(void *arg){
    ThreadRunArgs *args = static_cast<ThreadRunArgs *>(arg);
//    LOGD("thread id is %d" ,args->id);
//    LOGD("thread result is %d", args->result);
    return nullptr;
}

void *printThreadJoin(void *arg){

    ThreadRunArgs *args = static_cast<ThreadRunArgs *>(arg);
    struct timeval begin;
    gettimeofday(&begin,nullptr);
//    LOGD("start time is %lld",begin.tv_sec);
    sleep(3);
    struct timeval end;
    gettimeofday(&end, nullptr);
//    LOGD("end time is %lld",end.tv_sec);
//    LOGD("Time used is %d" + end.tv_sec - begin.tv_sec);
    return reinterpret_cast<void *>(args->result);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_thread_JNIThread_createNativeThread(JNIEnv *env,jobject instance){

    pthread_t handles;
    int result = pthread_create(&handles, nullptr,printThreadArgs, nullptr);
    if(result == 0){

        LOGD("create thread success");
    } else{

        LOGD("create thread failed");
    }

}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_thread_JNIThread_createNativeThreadWithArgs(JNIEnv *env,jobject instance){

    pthread_t handles;
    ThreadRunArgs *args = new ThreadRunArgs();
    args->id = 2;
    args->result = 100;
    int result = pthread_create(&handles, nullptr,printThreadArgs, args);
    if(result == 0){

        LOGD("create thread success");
    } else{

        LOGD("create thread failed");
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_thread_JNIThread_joinNativeThread(JNIEnv *env,jobject instance){

    pthread_t handles;
    ThreadRunArgs *args = new ThreadRunArgs();
    args->id = 2;
    args->result = 100;
    int result = pthread_create(&handles, nullptr,printThreadJoin, args);

    void *ret = nullptr;
    pthread_join(handles,&ret);
    LOGD("joinNativeThread");
//    LOGD("result is %d",ret);
}
