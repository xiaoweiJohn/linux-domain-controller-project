#include "can_filter.h"
#include <cstdint> 


bool can_filter(uint32_t id)
{
    if(id == 0x100)       //速度与温度报文ID
        return true;

    if(id == 0x300)        //车身控制报文ID
        return true;
    return false;
}