#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* deal_func(void* param)
{
	// 线程执行函数
	printf("thread function\n");
	return NULL;
}
	

int main()
{
	//创建线程, 无参数
	pthread_t thread;
	if( pthread_create(&thread, NULL, deal_func, NULL) < 0)
	{
		printf("create thread fail\n");
	}
	//直接return的情况下，子线程无法执行
	sleep(1);

	return 0;
}
