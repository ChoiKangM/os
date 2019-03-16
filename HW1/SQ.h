/*
Stack - pop, push

Queue - enqueue, dequeue
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 어서 구조 잡아보자
void typeInstruction();
typedef struct node NODE;
typedef struct QUEUE;
void showStack(NODE **startPtr,char *input);
bool push(NODE **startPtr, char *token);
bool pop(NODE **startPtr, char **printData);
void queue(char *input);


void showQueue(QUEUE **queuePtr, char *input);
QUEUE* createQueue(void);
bool enqueue(QUEUE* queue, char* token);
bool dequeue(QUEUE* queue, char* printData);
