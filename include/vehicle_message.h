#ifndef VEHICLE_MESSAGE_H_
#define VEHICLE_MESSAGE_H_

#define CAN_SPEED_ID 0x100

/*创建消息结构体*/
struct VehicleMessage
{
    long msg_type;    //消息类型
    int can_id;         //消息can id
    unsigned char data[8];    //消息数据,Byte0:speed、Byte1:temperature
    
};

#endif 