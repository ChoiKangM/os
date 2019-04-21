#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void fatal_error(int err_num, char *function);
void thread1_func();

int main()
{
	pthread_t tid;
	int return_val;
    
    // create a new thread to execute thread1_func()
    return_val = pthread_create(&tid,(pthread_attr_t*)NULL,(void*(*)())thread1_func,(void*)NULL);
    if(return_val!=0)
        fatal_error(return_val,"pthread_create()");
    //wait for the thread to finish executing, then..
    return_val = pthread_join(tid,(void**)NULL);
    if(return_val!=0)
        fatal_error(return_val,"pthread_join()");
    
    printf("Bye\n");
    exit(0);
}
// Thread function
void thread1_func()
{
    printf("Hello World!\n");
    pthread_exit((void*)NULL);
}