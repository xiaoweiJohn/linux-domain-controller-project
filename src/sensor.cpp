#include "sensor.h"
#include <iostream>
using namespace std;
#include<unistd.h>
#include "vehicle_message.h"
#include "message_queue.h"

void sensor_task(int queue_id)
{
    while(1)
    {
        VehicleMessage msg;       // 定义一个车辆消息对象
        msg.msg_type =1;
        msg.can_id = CAN_SPEED_ID;
        msg.data[0] =80;
        msg.data[1] = 35;

        /* 发送消息到消息队列 */
        send_message(queue_id, &msg);

        cout << "Sensor Send Message:" <<endl;
        cout <<"Speed: "<<msg.data[0]<<endl;
        
        sleep(1);
        
    }
}