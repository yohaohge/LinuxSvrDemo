#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* deal_func(void* param)
{
	// 线程执行函数
	printf("thread function\n");

	// can not be stack val for retval
	// stack val will be wrong val pthread_join
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

	printf("thread %02x retval = %d\n", (unsigned)thread, *retval);

	return 0;
}
