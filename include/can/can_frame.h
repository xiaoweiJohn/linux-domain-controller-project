#ifndef CAN_FRAME_H_
#define CAN_FRAME_H_
#include <stdint.h>

#define CAN_DATA_LEN 8

struct CAN_Frame{

     long msg_type;
    uint32_t id;
    uint8_t data[CAN_DATA_LEN];
    uint8_t dlc;
    uint64_t timestamp;
    
};



#endif 