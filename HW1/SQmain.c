#include "SQ.h"
// stack의 경우 strtok으로 해결 못해 자료구조를 활용하지만
// queue의 경우 strtok으로 잘라내면 그대로이므로 그대로 구현한다
int main(){
  char input[100];
  NODE *startPtr;
  QUEUE *queuePtr;
  
  const char s[2] = " ";
  char type = 0;

  // 1 3 8 11 13 등의 값을 입력받자
  printf("input string: \n\t"
          "ex) 1 3 8 11 13 \n\t");
  gets(input);
  
  // Stack, Queue 중 보여줄 형태를 고른다
  typeInstruction();
  scanf("%c",&type);
  startPtr = NULL;
  // 고른 구조를 보여준다
  if(type == 49)
  {
    showStack(&startPtr, input);
  }else if(type == 50)
  {
    //queue(input);
    showQueue(&startPtr, input);
  }else
  {
    printf("Wrong input\n");
    typeInstruction();
  }
  return 0;
  
}