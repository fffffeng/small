#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex;

void printer(char* str)
{
	pthread_mutex_lock(&mutex);	//上锁

	while(*str != '\0')
	{
		putchar(*str);
		fflush(stdout);
		++str;
		sleep(1);
	}
	printf("\n");

	pthread_mutex_unlock(&mutex);	//解锁
}

void* pthread_func1(void* arg)
{
	char* str = "Hello";
	printer(str);
}

void* pthread_func2(void* arg)
{
	char* str = "world";
	printer(str);
}


int main()
{
	pthread_t tid1,tid2;

	pthread_mutex_init(&mutex,NULL);	//初始化互斥锁

	//创建两个线程
	pthread_create(&tid1,NULL,pthread_func1,NULL);
	pthread_create(&tid2,NULL,pthread_func2,NULL);

	//等待线程结束，回收资源
	pthread_join(&tid1,NULL);
	pthread_join(&tid2,NULL);

	//销毁互斥锁
	pthread_mutex_destroy(&mutex);

	return 0;
}
