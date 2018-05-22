
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define PATH_NAME "/tmp"
#define PATH_ID 0X6666

int main()
{
  key_t k = ftok(PATH_NAME,PATH_ID);  //创建标识符
  if(k < 0)
  {
    printf("ftok error!\n");
    return -1;
  }

 int  shmid = shmget(k,4*1024,IPC_CREAT|IPC_EXCL|0x666);  //开辟共享内存
  if(shmid < 0)
  {
    printf("shmget error!\n");
  }

  char* ptr = (char*)shmat(shmid,NULL,0);  //挂接共享内存
  while(1)
  {
    printf("%s\r",ptr);
    fflush(stdout);
    sleep(1);
  }

  shmdt(ptr); //取消挂接共享内存
  shmctl(shmid,IPC_RMID,NULL);
  return 0;
}
