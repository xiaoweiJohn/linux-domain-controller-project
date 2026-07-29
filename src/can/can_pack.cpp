#include "can_pack.h"



/**
 * @brief 打包速度和温度
 * 
 * @param frame 
 * @param speed 
 * @param temp 
 */
void pack_speed_temp(CAN_Frame &frame,uint8_t speed,uint8_t temp)
{
    frame.id = 0x100;
    frame.dlc = 8;

    // 打包速度
    uint16_t speed_raw;
    speed_raw = speed*10;
    frame.data[0] = speed_raw & 0xFF;
    frame.data[1] = (speed_raw >> 8) & 0xFF;
    
    // 打包温度
    frame.data[2] = temp;
}
