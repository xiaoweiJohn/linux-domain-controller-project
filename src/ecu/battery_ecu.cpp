#include<iostream>
#include<unistd.h>
#include "battery_ecu.h"
#include "can_frame.h"
#include "can_config.h"
#include "message_queue.h"
using namespace std;


void battery_task(int queue_id)
{
    while(1)
    {
        CAN_Frame frame;
        /* Set CAN ID*/
        frame.id = CAN_ID_BATTERY;  
        frame.msg_type=1;

        /*DLC*/
        frame.dlc=8;

        /*Voltage：12.8V，raw=128*/
        uint16_t voltage_raw=128;
        frame.data[0] = voltage_raw & 0xff;

        frame.data[1] = (voltage_raw >> 8) & 0xff;
        /*Current：50A，raw=500*/
        uint16_t current_raw = 500;
        frame.data[2] = current_raw & 0xff;
        frame.data[3] = (current_raw >> 8) & 0xff;
       
        /*SOC：85%*/
        frame.data[4]=85;

        /*Temperature：35℃*/
        frame.data[5]=35;

        /*Error：0正常*/
        frame.data[6]=0;
        send_can_message(queue_id,frame);
        cout<<"Battery ECU Send"<<endl;
        cout<<"Voltage=12.8V"<<endl;
        cout<<"Current=50A"<<endl;
        cout<<"SOC=85%"<<endl;
        cout<<"Temperature=35°C"<<endl;

        sleep(5);
    }           
}
