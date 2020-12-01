#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/*
 * 自旋锁的特点是不释放CPU的执行权
 * 在等待锁的时候，cpu负载很高
 * 通过top 可以看到进程对CPU的负载到95%以上
 * 所以，自旋锁不适用于执行很久的代码段
 */
pthread_spinlock_t lock;

int target = 0;

void* thread_func(void* param)
{
	while(1)
	{
		pthread_spin_lock(&lock);
		printf("child thread get lock\n");
		sleep(1);
		pthread_spin_unlock(&lock);	
	}
}

int main() 
{
	pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);

	// create child thread
	
	pthread_t thread;
	if( pthread_create(&thread, NULL, thread_func, NULL) < 0 )
	{
		printf("thread create fail\n");
		return 0;
	}

	while(1)
	{
		pthread_spin_lock(&lock);
		
		printf("main thread get lock\n");
		sleep(1);

		pthread_spin_unlock(&lock);
	}
	return 0;

}

