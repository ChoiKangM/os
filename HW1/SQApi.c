#include "SQ.h"


void typeInstruction()
{
  printf("Insert your operation type\n\t"
          "- 1.Stack\n\t"
          "- 2.Queue\n\t");
}

typedef struct node
{
  char *data;
  struct node *link;
}NODE;

// stack에서 오류 난다 ㅠㅠ
void showStack(NODE **startPtr, char *input)
{
  NODE *stackNODE;
  char *token;
  char *printData;
  const char s[2] = " ";
  printf("push!\n");
  token = strtok(input, s);
  while(token != NULL)
  { 
    // stack - push!!
    push(startPtr,token);
    token = strtok(NULL,s);
  }
  printf("pop!\n");
  while(pop(startPtr, &printData))
    printf("%c ",*printData);
}
bool push(NODE **startPtr, char *token)
{
  NODE *snew;
  bool success;
  snew = (NODE*)malloc(sizeof(NODE));
  if(!snew)
    success = false;
  else
  { 
    snew->data = token;
    snew->link = *startPtr;
    *startPtr = snew;
    success = true;
  }
  return success;
}

bool pop(NODE **startPtr, char **printData)
{
  NODE *sdel;
  bool success;

  if(*startPtr)
  {
    success     = true;
    *printData  = (*startPtr)->data;
    sdel        = *startPtr;
    *startPtr   = (*startPtr)->link;
    free(sdel); 
  }else
    success = false;
  return success;
}
/* queue 자료구조 못만들면 이거 쓰자
void queue(char *input)
{
  char *token;
  const char s[2] = " ";
  printf("enqueue!\n");
  token = strtok(input, s);
  while(token != NULL)
  {
    printf("%s ", token);
    token = strtok(NULL,s);
  }
}
*/

/*
typedef struct
{
    NODE* front;
    NODE* rear;
    int count;
}QUEUE;

QUEUE* createQueue()
{
    QUEUE* queue;
    queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(queue)
    {
        queue->front = NULL;
        queue->rear  = NULL;
        queue->count = 0;
    }
    return queue;
}

bool enqueue(QUEUE* queue, char* token)
{
    NODE* newPtr;
    
    if(!(newPtr = (NODE*)malloc(sizeof(NODE))))
        return false;
    
    newPtr->data = token;
    newPtr->link = NULL;
    
    if(queue->count == 0)
        // Inserting into NULL queue
        queue->front = newPtr;
    else
        queue->rear->link = newPtr;
    
    (queue->count)++;
    queue->rear = newPtr;
    return true;
}


bool dequeue(QUEUE* queue, char* printData)
{
    NODE* deleteLoc;
    
    if(!queue->count)
        return false;
    
    printData = *queue->front->data;
    deleteLoc = queue->front;
    if(queue->count == 1)
        //Deleting only item in queue
        queue->rear = queue->front = NULL;
    else
        queue->front = queue->front->link;
    (queue->count)--;
    free(deleteLoc);
    
    return true;
}
*/