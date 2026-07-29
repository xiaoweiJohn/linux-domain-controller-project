#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include "can_frame.h"
#include <cstdint>

/**
 * @brief 消息队列
 * 
 */
 int create_queue();


/**
 * @brief 发送消息
 * 
 * @param queue_id 队列ID
 * @param msg 消息内容
 * @return int 成功返回0，失败返回错误码
 */
 int send_can_message(int queue_id, CAN_Frame &frame);

 
 /**
  * @brief 接收消息
  * 
  * @param queue_id 队列ID
  * @param msg 消息内容
  * @return int 成功返回0，失败返回错误码
  */
 int receive_can_message(int queue_id, CAN_Frame &frame);

#endif 