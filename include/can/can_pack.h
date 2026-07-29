#ifndef CAN_PACK_H_
#define CAN_PACK_H_
#include "can_frame.h"
#include <cstdint> 

/**
 * @brief 打包速度和温度
 * 
 * @param frame 
 * @param speed 
 * @param temp 
 */
void pack_speed_temp(CAN_Frame &frame,uint8_t speed,uint8_t temp);





#endif // CAN_PACK_H_
