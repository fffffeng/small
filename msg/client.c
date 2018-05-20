#include "comm.h"
#include <string.h>

int main()
{
  int msgid = getMsgQueue();
  char buf[256];
  while(1)
  {

    //send  client把消息发送到消息队列
    printf("Please Enter:");
    scanf("%s",buf);
    sendMsg(msgid,buf,CLIENT_TYPE);

    if(strcmp(buf,"quit") == 0)
    {
      printf("client is quit!\n");
      break;
    }

    //recv  从消息队列中接收server的回应
    recvMsg(msgid,buf,SERVRE_TYPE);
    printf("Server#%s\n",buf);
  }
  destroyMsgQueue(msgid);
  return 0;
}
