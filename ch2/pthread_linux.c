#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void fatal_eror(int err_num, char *function);
void thread1_func();

int main()
{
	pthread_t tid;
	int return_val;
}