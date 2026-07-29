#include "sensor_ecu.h"
#include <iostream>
using namespace std;
#include<unistd.h>
#include "can_frame.h"
#include "message_queue.h"
#include "can_pack.h"
#include "can_frame.h"
#include "can_config.h"

void sensor_task(int queue_id)
{
    while(1)
    {
        CAN_Frame frame;
        frame.msg_type=1;
        frame.id=CAN_ID_SPEED_TEMP;
        frame.dlc=8;
        frame.data[0]=80;
        frame.data[1]=35;
        pack_speed_temp(frame,80,35);
        send_can_message(queue_id,frame);
        
        sleep(1);
        
    }
}