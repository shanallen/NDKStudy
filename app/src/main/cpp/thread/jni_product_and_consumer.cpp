//
// Created by 单继强 on 2020-05-02.
//
#include <jni.h>
#include <queue>
#include <base.h>
#include <pthread.h>
#include <stdio.h>
#include <jvm.h>
#include <unistd.h>

using namespace std;
std::queue<int>data;
pthread_mutex_t dataMutex;
pthread_cond_t dataCond;

void *productThread(void *){
    while (data.size() < 10){
        pthread_mutex_lock(&dataMutex);
        LOGD("生产物品");
        data.push(1);
        if(data.size() > 0){

            LOGD("等待消费");
            pthread_cond_signal(&dataCond);

        }
        pthread_mutex_unlock(&dataMutex);
        sleep(3);
    }
    pthread_exit(0);
}

void *consumerThread(void *){
    while (1){
        pthread_mutex_lock(&dataMutex);
        if(data.size() > 0){

            LOGD("消费物品");
            data.pop();
        } else{

            LOGD("等待生产");
            pthread_cond_wait(&dataCond,&dataMutex);

        }
        pthread_mutex_unlock(&dataMutex);
        sleep(1);
    }
    pthread_exit(0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_sjq_learnndk_thread_JNIThread_startProduceAndConsumerThread(JNIEnv *env,jobject instance){

    pthread_mutex_init(&dataMutex,nullptr);
    pthread_cond_init(&dataCond,nullptr);
    pthread_t productHandle;
    pthread_t consumerHandle;
    pthread_create(&productHandle,nullptr,productThread,nullptr);
    pthread_create(&consumerHandle,nullptr,consumerThread,nullptr);

}
