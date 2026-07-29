#ifndef CAN_UNPACK_H_
#define CAN_UNPACK_H_
#include "can_frame.h"
#include <stdint.h>

/*CAN解析函数
*@param frame 输入的CAN帧
*@param speed 解析出的速度值
*@param temp 解析出的温度值
*/
void unpack_speed_temp(CAN_Frame &frame, int &speed, int &temp);




#endif 