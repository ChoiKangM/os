#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    // a1: allocate some memory
    int *p = malloc(sizeof(int));
    assert(p!=NULL);
    // a2: print out the address of the memory
    printf("(%d) address of p: %08x\n",
          getpid(), (unsigned) p);
    // a3: put zero into the first slot of the memory
    *p = 0;
    while(1)
    {
        Spin(1);
        *p = *p + 1;
        // a4
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}