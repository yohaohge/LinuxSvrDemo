#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* dead_loop(void* param)
{
	while(1)
	{
		sleep(1);
	}
}

void* deal_func(void* param)
{
	// 线程执行函数
	printf("%02x thread function\n",(unsigned)pthread_self());
	pthread_exit(NULL);
}

// 使用pthread_detach, 在线程结束后释放资源 
void* deal_func2(void* param)
{
	pthread_detach(pthread_self());
	printf("%02x thread fucnthon#2 \n", (unsigned)pthread_self());	
}
int main()
{
	//创建一个线程
	pthread_t long_time_thread;
	if( pthread_create(&long_time_thread, NULL,dead_loop, NULL) )
	{
		printf("thread create fail\n");
		return 0;
	}	

	//创建100个线程
	//分别使用deal_func 和 deal_func2 来创建线程
	//通过top命令查看进程的资源使用（释放）情况
	//【主要观察指标是虚拟内存VIRT 和 实际内存RES】
	pthread_t thread;
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		if( pthread_create(&thread, NULL, deal_func2, NULL) < 0)
		{
			printf("create thread fail\n");
		}
	}

	pthread_join(long_time_thread, NULL);


	return 0;
}
