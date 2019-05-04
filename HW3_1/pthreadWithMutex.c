#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "common.h"

// 컴파일러에 관련된 명령어로 더 빠른 속도로 처리된다
// volatile은 메모리에 저장하여 전역변수로 사용된다
// 속도를 위해 메모리보다 CPU에 바로 저장하는 경우도 있다
volatile int counter = 0;
int loops;
pthread_mutex_t lock;

void *workerWithMutex(void *arg)
{
    pthread_mutex_lock(&lock);

    int i;
    for(i=0;i<loops;i++)
    {
        counter++;
    }
    
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "usage: threads <value>\n");
		exit(1);
	}
	loops = atoi(argv[1]);
	pthread_t p1,p2;
	printf("Mutex가 있는 경우\n");
	printf("10억까지도 전역변수가 안깨집니다\n");
    
    
	printf("Initial value with mutex : %d\n", counter);

	pthread_create(&p1, NULL, workerWithMutex, NULL);
	pthread_create(&p2, NULL, workerWithMutex, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("Final value with mutex : %d\n", counter);
	return 0;
}