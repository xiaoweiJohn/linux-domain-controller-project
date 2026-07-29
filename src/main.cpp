#include<iostream>
using namespace std;
#include <pthread.h>
#include <unistd.h>
#include "message_queue.h"

void sensor_task(int);
void body_task(int);

int queue_id;

/*
传感器线程函数
*/
void *sensor_thread(void*)
{
    sensor_task(queue_id);
    
}

/*车身线程函数*/
void *body_thread(void*)
{
    body_task(queue_id);
}



int main()
{
    queue_id = create_queue();

    /*创建三个线程 sensor,body,gateway*/
    pthread_t sensor_t1,body_t2;
    pthread_create(&sensor_t1, NULL, sensor_thread, NULL);
    pthread_create(&body_t2, NULL, body_thread, NULL);

    /*等待线程结束*/
    pthread_join(sensor_t1, NULL);
    pthread_join(body_t2, NULL);

    return 0;

}
