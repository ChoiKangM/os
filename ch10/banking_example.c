#include <stdio.h>
#include <pthread.h>

void* withdraw(void *arg);

int balance = 1000;
int main()
{
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, withdraw, (void*)800);
    pthread_create(&t2, NULL, withdraw, (void*)800);
	pthread_create(&t3, NULL, withdraw, (void*)800);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
	pthread_join(t3,NULL);
    printf("All done: balance is $%d\n",balance);
    return 0;
}
void* withdraw(void *arg)
{
    int amount = (int)arg;
    if(balance >= amount)
    {
        balance -= amount;
        printf("ATM gives user $%d\n",amount);
    }
}