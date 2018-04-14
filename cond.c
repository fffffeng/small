#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_cond_t cond;	//定义条件变量
pthread_mutex_t mutex;  //定义互斥量

int money;	//定义全局资源

void* pthread_func(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);	//上锁

		while(money>0)
		{
			printf("让子线程等待money等于0\n");
			pthread_cond_wait(&cond,&mutex);	//等待（阻塞）
		}

		//让子线程进入临界区查看
		if(money==0)
		{
			money += 200;
			printf("子线程money=%d\n",money);
		}

		//解锁
		pthread_mutex_unlock(&mutex);

		sleep(1);
	}
	return NULL;
}


int main()
{
	pthread_t tid;

	pthread_mutex_init(&mutex,NULL); //初始化互斥量
	pthread_cond_init(&cond,NULL);	 //初始化条件变量
	
	pthread_create(&tid,NULL,pthread_func,NULL);//创建子线程

	money=1000;
	while(1)
	{
		//上锁
		pthread_mutex_lock(&mutex);

		if(money>0)
		{
			money-=100;
			printf("主线程:money=%d\n",money);
		}
		//解锁
		pthread_mutex_unlock(&mutex);

		//如果money=0就通知子线程
		if(money==0)
		{
			printf("通知子线程>:\n");
			pthread_cond_signal(&cond);
		}

		sleep(1);
	}

	return 0;
}

