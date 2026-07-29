#include<iostream>
using namespace std;
#include <pthread.h>
#include <unistd.h>
#include "message_queue.h"

void sensor_task(int);
void body_task(int);
void battery_task(int);

int queue_id;

/*
传感器线程函数
*/
void *sensor_function(void*)
{
    sensor_task(queue_id);
    
}

/*车身线程函数*/
void *body_function(void*)
{
    body_task(queue_id);
}

/*电池线程函数*/
void *battery_function(void*)
{
    battery_task(queue_id);
}
int main()
{
    queue_id = create_queue();

    /*创建三个线程 sensor,body,gateway*/
    pthread_t sensor_thread,body_thread,battery_thread;
    pthread_create(&sensor_thread, NULL, sensor_function, NULL);
    pthread_create(&body_thread, NULL, body_function, NULL);
    pthread_create(&battery_thread, NULL, battery_function, NULL);
    /*等待线程结束*/
    pthread_join(sensor_thread, NULL);
    pthread_join(body_thread, NULL);
    pthread_join(battery_thread, NULL);

    return 0;

}
