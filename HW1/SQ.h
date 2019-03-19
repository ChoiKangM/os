/*
Stack - pop, push
Queue - enqueue, dequeue
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void typeInstruction(void);
typedef struct node NODE;
typedef struct queue QUEUE;
void showStack(NODE **startPtr,char *input);
bool push(NODE **startPtr, char *token);
bool pop(NODE **startPtr, char **printData);

void showQueue(QUEUE **queuePtr, char *input);
QUEUE* createQueue(void);
bool enqueue(QUEUE* queueNODE, char* token);
bool dequeue(QUEUE* queueNODE, char** printData);

