#include "can_unpack.h"
#include <iostream>


/*CAN解析函数
*@param frame 输入的CAN帧
*@param speed 解析出的速度值
*@param temp 解析出的温度值
*/
void unpack_speed_temp(CAN_Frame &frame, int &speed, int &temp)
{
    uint16_t raw;
    raw = frame.data[0]| (frame.data[1] << 8);
    speed = raw/10;
    temp = frame.data[2];
}