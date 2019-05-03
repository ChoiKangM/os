#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"

// 컴파일러에 관련된 명령어로 더 빠른 속도로 처리된다
// volatile은 메모리에 저장하여 전역변수로 사용된다
// 속도를 위해 메모리보다 CPU에 바로 저장하는 경우도 있다
volatile int counter = 0;
int loops;

void *worker(void *arg)
{
	int i;
	for(i=0;i<loops;i++)
	{
		counter++;
	}
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
	printf("100만까지는 정상적으로 작동하지만\n");
	printf("1000만부터는 전역변수가 깨집니다\n");
	printf("Initial value : %d\n", counter);

	pthread_create(&p1, NULL, worker, NULL);
	pthread_create(&p2, NULL, worker, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("Final value : %d\n", counter);
	return 0;
}