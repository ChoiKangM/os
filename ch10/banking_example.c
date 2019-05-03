#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include "bank.h"

int main()
{
    volatile int balance = 1000;
    pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    pthread_t t11, t12, t13, t14, t15, t16, t17, t18, t19, t20;
    pthread_create(&t1, NULL, withdraw, (void*)800);
    pthread_create(&t2, NULL, withdraw, (void*)800);
	pthread_create(&t3, NULL, withdraw, (void*)800);
	// pthread_create(&t4, NULL, withdraw, (void*)800);
	// pthread_create(&t5, NULL, withdraw, (void*)800);
	// pthread_create(&t6, NULL, withdraw, (void*)800);
	// pthread_create(&t7, NULL, withdraw, (void*)800);
	// pthread_create(&t8, NULL, withdraw, (void*)800);
	// pthread_create(&t9, NULL, withdraw, (void*)800);
	// pthread_create(&t10, NULL, withdraw, (void*)800);
	// pthread_create(&t11, NULL, withdraw, (void*)800);
	// pthread_create(&t12, NULL, withdraw, (void*)800);
	// pthread_create(&t13, NULL, withdraw, (void*)800);
	// pthread_create(&t14, NULL, withdraw, (void*)800);
	// pthread_create(&t15, NULL, withdraw, (void*)800);
	// pthread_create(&t16, NULL, withdraw, (void*)800);
	// pthread_create(&t17, NULL, withdraw, (void*)800);
	// pthread_create(&t18, NULL, withdraw, (void*)800);
	// pthread_create(&t19, NULL, withdraw, (void*)800);
	// pthread_create(&t20, NULL, withdraw, (void*)800);
    
    
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	// pthread_join(t4,NULL);
	// pthread_join(t5,NULL);
	// pthread_join(t6,NULL);
	// pthread_join(t7,NULL);
	// pthread_join(t8,NULL);
	// pthread_join(t9,NULL);
	// pthread_join(t10,NULL);
	// pthread_join(t11,NULL);
	// pthread_join(t12,NULL);
	// pthread_join(t13,NULL);
	// pthread_join(t14,NULL);
	// pthread_join(t15,NULL);
	// pthread_join(t16,NULL);
	// pthread_join(t17,NULL);
	// pthread_join(t18,NULL);
	// pthread_join(t19,NULL);
	// pthread_join(t20,NULL);
    
    printf("All done: balance is $%d\n",balance);
    return 0;
}
