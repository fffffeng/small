#include "comm.h"
#include <string.h>
static int commMsgQueue(int flag)
{

  key_t k = ftok(PATH_NAME,PATH_ID);
  if(k < 0)
  {
    printf("ftok error!\n");
    return -1;
  }
  int msgid = msgget(k,flag);
  if(msgid < 0)
  {
    printf("msgget error!\n");
    return -2;
  }
  return msgid;
}

int createMsgQueue()
{
  return commMsgQueue(IPC_CREAT|IPC_EXCL|0644);
}

int getMsgQueue()
{
  return commMsgQueue(IPC_CREAT);
}

int sendMsg(int msgid,char* msg,int type)
{
  struct msgbuf buf;
  buf.mtype = type;
  strcpy(buf.mtext,msg);
  if(msgsnd(msgid,&buf,sizeof(buf.mtext),0) < 0)
  {
    printf("msgsnd error!\n");
    return -1;
  }
  return 0;
}

int recvMsg(int msgid,char* msg,int type)
{
  struct msgbuf buf;
  if(msgrcv(msgid,&buf,sizeof(buf.mtext),type,0) < 0)
  {
    printf("msgrcv error!\n");
    return -1;
  }
  strcpy(msg,buf.mtext);
  return 0;
}

void destroyMsgQueue(int msgid)
{
  if(msgctl(msgid,IPC_RMID,NULL) < 0)
  {
    printf("msgctl error!\n");
  }
}
