#include "body.h"
#include <iostream>
using namespace std;
#include<unistd.h>
#include "vehicle_message.h"
#include "message_queue.h"

void body_task(int queue_id)
{
    while(1)
    {
        VehicleMessage msg;
        /* 从队列中读取消息 */
        receive_message(queue_id, &msg);
        
        /*判断*/
        if(msg.can_id == CAN_SPEED_ID)
        {
            int speed = msg.data[0];
            cout << "Body Receiver speed: " << speed << endl;
            if(speed > 100)
            {
                cout << "Body ECU warning: speed > 100" << endl;
            }
            else
            {
                cout << "Body ECU normal: speed <= 100" << endl;
            }
        }

        
    }
    
}