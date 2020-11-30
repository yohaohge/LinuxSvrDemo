#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* thread_func(void* param)
{
}

int main()
{
	pthread_cond_init(&cond, NULL);
	
	pthread_t thread;

	if(pthread_create(&thread, NULL, thread_func, NULL) < 0 )
	{
		printf("thread create fail\n");
		return 0;
	}


	pthread_join(thread,NULL);

	return 0;
}
