#include "comm.h"
#include <string.h>

int main()
{
  int msgid = createMsgQueue(); //创建消息队列
  char buf[256];
  while(1)
  {
    //recv  从消息队列接收client的消息
    recvMsg(msgid,buf,CLIENT_TYPE);
    if(strcmp(buf,"quit") == 0)
    {
      printf("client is quit! me too!\n");
      break;
    }
    printf("client#%s\n",buf);
    //send  回应给client消息，并把消息发送到消息队列
    printf("Please Enter:");
    scanf("%s",buf);
    sendMsg(msgid,buf,SERVRE_TYPE);

  }
  destroyMsgQueue(msgid);
  return 0;
}
