#include "body_ecu.h"
#include <iostream>
using namespace std;
#include<unistd.h>
#include "can_frame.h"
#include "message_queue.h"
#include "battery_ecu.h"
#include "can_unpack.h"

void decode_battery(CAN_Frame &frame);


/*此文件任务*/
/*接受CAN Frame ->判断ID -> 解析 -> 控制逻辑*/

void body_task(int queue_id)
{

    while(1)
    {
        CAN_Frame frame;
        receive_can_message(queue_id, frame);
        switch(frame.id)
            {
                case CAN_ID_SPEED_TEMP:
                {
                    int speed;

                    int temp;
                    unpack_speed_temp(frame, speed, temp);
                    cout<<"speed="<<speed<<endl;
                    cout<<"temp="<<temp<<endl;
                    if(speed>120)
                    {
                        cout<<"OVER SPEED"<<endl;
                    }
                    break;
                    

                }
                
                // 【新增】电池数据解析分支（不参与超时检测）
                case CAN_ID_BATTERY:
                {
                    decode_battery(frame);
                    
                    // 可在此添加电池相关的报警逻辑（如低电量），但无超时要求
                    break;
                }
                
                // 其他ID的帧忽略
                default:
                    break;
            }
        }

        
       
    
}



// 电池数据解析函数
void decode_battery(CAN_Frame &frame)
{
    uint16_t voltage_raw = frame.data[0] | (frame.data[1] << 8);
    float voltage = voltage_raw / 10.0f;

    uint16_t current_raw = frame.data[2] | (frame.data[3] << 8);
    float current = current_raw / 10.0f;

    int soc = frame.data[4];

    cout << "Battery:" << endl;
    cout << "Voltage=" << voltage << "V" << endl;
    cout << "Current=" << current << "A" << endl;
    cout << "SOC=" << soc << "%" << endl;

    if (voltage < 10) {
        cout << "Battery Fault" << endl;
    }
}
