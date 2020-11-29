#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* deal_func(void* param)
{
	// 线程执行函数
	printf("thread function\n");

	// 返回不能使用栈内存变量，会导致结果未知
	// 使用malloc和new申请的内存，需要主要内存释放的问题
	int* retval = malloc(sizeof(int));
    *retval = 1;	
	pthread_exit(retval);
}
	

int main()
{
	//创建线程, 无参数
	pthread_t thread;
	if( pthread_create(&thread, NULL, deal_func, NULL) < 0)
	{
		printf("create thread fail\n");
	}

	int* retval = NULL;
	pthread_join(thread, (void*)&retval);
	//没有处理内存释放问题，有内存泄漏的情况
	if(retval)
	{
		printf("thread %02x retval = %d\n", (unsigned)thread, *retval);
		free(retval);
	}

	return 0;
}
