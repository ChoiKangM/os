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

typedef struct queue
{    
    // enqueue 쪽 - 들어오는 쪽
    NODE* front;
    // dequeue 쪽 - 나가는 쪽
    NODE* rear;
    int count;
}QUEUE;


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
    printf("token: %s\n",token);
    token = strtok(NULL,s);
  }
  printf("pop!\n");
  while(pop(startPtr, &printData))
  {
      
    printf("%s ",printData);  
  }
    
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
    printf("snew->data : %s\n",snew->data);
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
/*
// queue 자료구조 못만들면 이거 쓰자
void queue(char *input)
{
  char *token;
  const char s[2] = " ";
  printf("dequeue!\n");
  token = strtok(input, s);
  while(token != NULL)
  {
    printf("%s ", token);
    token = strtok(NULL,s);
  }
}
*/


// queue 만들자
void showQueue(QUEUE **queuePtr, char *input)
{
  QUEUE *queueNODE;
  char *token;
  char *printData;
  const char s[2] = " ";
  
  queueNODE = createQueue();
  printf("enqueue!\n");
  token = strtok(input, s);
    
  while(token != NULL)
  { 
    enqueue(queueNODE,token);
    token = strtok(NULL,s);
  }
  printf("dequeue!\n");
    
  while(dequeue(queueNODE, &printData))
  {
    printf("%s ", printData);  
  }
    
}

QUEUE* createQueue(void)
{
    QUEUE* queueNODE;
    queueNODE = (QUEUE*)malloc(sizeof(QUEUE));
    if(queueNODE)
    {
        queueNODE->front = NULL;
        queueNODE->rear  = NULL;
        queueNODE->count = 0;
    }
    return queueNODE;
}

bool enqueue(QUEUE* queueNODE, char* token)
{
    NODE* newPtr;
    
    if(!(newPtr = (NODE*)malloc(sizeof(NODE))))
        return false;
    newPtr->data = token;
    newPtr->link = NULL;
    
    if(queueNODE->count == 0)
        // Inserting into NULL queue
        queueNODE->front = newPtr;
    else
        queueNODE->rear->link = newPtr;
    
    (queueNODE->count)++;
    queueNODE->rear = newPtr;
    return true;
}


bool dequeue(QUEUE* queueNODE, char** printData)
{
    NODE* deleteLoc;
    
    if(!queueNODE->count)
        return false;
    *printData = queueNODE->front->data;
    deleteLoc = queueNODE->front;
    if(queueNODE->count == 1)
        //Deleting only item in queue
        queueNODE->rear = queueNODE->front = NULL;
    else
        queueNODE->front = queueNODE->front->link;
    (queueNODE->count)--;
    free(deleteLoc);
    
    return true;
}
