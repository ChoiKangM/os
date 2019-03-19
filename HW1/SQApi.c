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


// Stack
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
  // Stack - pop 완료
  printf("\n"); 
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
    // Stack에 데이터 들어가는거 보여주자
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

// Queue
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
    printf("token: %s\n",token);
    token = strtok(NULL,s);
  }
  printf("dequeue!\n");
    
  while(dequeue(queueNODE, &printData))
  {
    printf("%s ", printData);  
  }
  // Queue - dequeue 완료
  printf("\n"); 
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
    NODE* qnew;
    
    if(!(qnew = (NODE*)malloc(sizeof(NODE))))
        return false;
    qnew->data = token;
    // Queue에 데이터 들어가는거 보여주자
    printf("qnew->data : %s\n",qnew->data);
    qnew->link = NULL;
    
    if(queueNODE->count == 0)
        // Inserting into NULL queue
        queueNODE->front = qnew;
    else
        queueNODE->rear->link = qnew;
    
    (queueNODE->count)++;
    queueNODE->rear = qnew;
    return true;
}


bool dequeue(QUEUE* queueNODE, char** printData)
{
    NODE* qdel;
    
    if(!queueNODE->count)
        return false;
    *printData = queueNODE->front->data;
    qdel = queueNODE->front;
    if(queueNODE->count == 1)
        //Deleting only item in queue
        queueNODE->rear = queueNODE->front = NULL;
    else
        queueNODE->front = queueNODE->front->link;
    (queueNODE->count)--;
    free(qdel);
    
    return true;
}
