#include "stdio.h"
#include "pthread.h"
#include "bank.h"

volatile int balance = 1000;

void* withdraw(void *arg)
{
    int amount = (int)arg;
    if(balance >= amount)
    {
        balance -= amount;
        printf("ATM gives user $%d\n",amount);
    }
}