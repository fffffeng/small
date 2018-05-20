#ifndef _COMM_H_
#define _COMM_H_ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATH_NAME "/tmp"  //使用ftok()创建消息队列描述符要使用的参数
#define PATH_ID 0x6666

#define SERVRE_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf{
  long mtype;
  char mtext[128];
};

int createMsgQueue(); //创建消息队列
int getMsgQueue();  //获取消息队列
int sendMsg(int msgid,char* msg,int type);  //发送消息到消息队列
int recvMsg(int msgid,char* msg,int type);  //从消息队列接收消息
void destroyMsgQueue(int msgid);  //销毁消息队列

#endif 
