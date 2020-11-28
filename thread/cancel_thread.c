#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* deal_func(void* param)
{
	// 线程执行函数
	while(1)
	{
		printf("thread function\n");
	}

	pthread_exit(NULL);
}	

int main()
{
	//创建线程, 无参数
	pthread_t thread;
	if( pthread_create(&thread, NULL, deal_func, NULL) < 0)
	{
		printf("create thread fail\n");
	}

	sleep(1);
	if(pthread_cancel(thread) < 0) 
	{
		printf("thread cancel fail\n");
		return 0;
	}
	printf("child thread end\n");
	sleep(1);
	printf("main thread\n");

	return 0;
}
