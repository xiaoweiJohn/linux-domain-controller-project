#include "message_queue.h"
#include <iostream>
#include <sys/msg.h>      
using namespace std;

/**
 * @brief 消息队列
 * 
 */
 int create_queue()
 {
    key_t key = 1234;    // 队列键值
    int msgid = msgget(key, 0666 | IPC_CREAT);     // 创建消息队列
    if (msgid < 0)
    {
        cout << "消息队列创建失败" << endl;
        return -1;
    }

    return msgid;
 }


/**
 * @brief 发送消息
 * 
 * @param queue_id 队列ID
 * @param msg 消息内容
 * @return int 成功返回0，失败返回错误码
 */
 int send_can_message(int queue_id, CAN_Frame &frame)
 {
    int ret = msgsnd(queue_id, &frame, sizeof(CAN_Frame)-sizeof(long), 0);  // 发送消息
    if (ret < 0)
    {
        cout << "消息发送失败" << endl;
        return -1;
    }

    return ret;
 }

 
 /**
  * @brief 接收消息
  * @param queue_id 队列ID
  * @param msg 消息内容
  * @return int 成功返回0，失败返回错误码
  */
 int receive_can_message(int queue_id, CAN_Frame &frame)
 {
    int ret = msgrcv(queue_id, &frame, sizeof(CAN_Frame)-sizeof(long), 0, 0);  // 接收消息
    if (ret < 0)
    {
        cout << "消息接收失败" << endl;
        return -1;
    }

    return ret;
 }
