#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int target_src = 0;

void* thread_func_add(void* param)
{
	printf("thread %02x started!\n", (unsigned)(pthread_self()));
	pthread_detach(pthread_self());
	// deal business	
	// 同一个线程对嵌套锁多次加锁
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);


	// do work
	printf("target_src = %d before add\n", target_src);
	target_src++;
	printf("target_src = %d after add\n", target_src);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);
}

void* thread_func_sub(void* param)
{
	printf("thread %02x started!\n", (unsigned)(pthread_self()));
	pthread_detach(pthread_self());
	pthread_mutex_lock(&mutex);
	printf("target_src = %d before sub\n", target_src);	
	target_src--;
	printf("target_src = %d after sub\n", target_src);	
	pthread_mutex_unlock(&mutex);	
	pthread_exit(NULL);
}

int main()
{
	pthread_mutexattr_t mutex_attr;
	pthread_mutexattr_init(&mutex_attr);
	pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);

	
	pthread_mutex_init(&mutex, &mutex_attr);

	pthread_t thread;
	
	// create thread
	if(pthread_create(&thread, NULL, thread_func_add, NULL) < 0 )
	{
		printf("thread create fail\n");
		return 0;
	}
	
	if(pthread_create(&thread, NULL, thread_func_sub, NULL) < 0)
	{
		printf("thread create fail\n");
		return 0;
	}

	sleep(1);
		
	return 0;
}
