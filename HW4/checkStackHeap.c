#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define ONE_MEG 1048576
#define STACK_ALLOC ONE_MEG/20
#define BASE 16
#define GROUP 4
#define MAXTEXT 25

long       *MemoryPtr;
unsigned long    FirstStackLocation;

void     RecursiveRoutine( int );
char     *commas(unsigned long amount);
int 	 prepend(char *, unsigned, char *);
int 	 preprintf(char *, unsigned, char *, ...);

//  This is a global so the subroutine can see it.

int main(int argc, char *argv[]){

    long         NumberOfMegaBytes, NumberOfAllocations = 0;
    long         Temp;
    long         *TempPointer;
    char         MemoryFunction[32];
    int          Function = 0;
    int          TopOfStack;
    int          Counter = 0;
    
    
    // resurciveCall.c
    FirstStackLocation = (unsigned long)(&TopOfStack);
    printf("First location on stack: %s\n", 
            commas( (unsigned long)FirstStackLocation  ) );
    RecursiveRoutine( 0 );

    if (argc < 3 ) {
        printf( "Usage: %s <MemorySizeInMegabyte> <Read|Write|Nothing>\n", argv[0]);
        exit(1);
    }
    
    // mallocTooMuch.c
    //  Get the arguments and validate them
    NumberOfMegaBytes = atoi( argv[1] );
    strcpy( MemoryFunction, argv[2] );
	// Nothing = 1, Read = 2, Write = 3
    if ( strncmp ( MemoryFunction, "Nothing", 7 ) == 0 ) Function = 1;
    if ( strncmp ( MemoryFunction, "Read", 4 ) == 0    ) Function = 2;
    if ( strncmp ( MemoryFunction, "Write", 5 ) == 0   ) Function = 3;
    if ( Function == 0 )  {
        printf( "Unable to recognize the Read|Write|Nothing portion of the command\n");
		return;
    }

    //  Now loop through each of the megabytes and perhaps touch each of the 1024 pages
    //  in that megabyte.
    //  MemoryPtr을 이용해 1MG씩 malloc, NumberofAllocations -> 할당된 메모리
	while ( NumberOfAllocations < NumberOfMegaBytes ) 
	{
        MemoryPtr = ( long * ) malloc( ONE_MEG );
        if ( MemoryPtr == 0 ) 
		{
            printf( "The program is ending because we could allocate no more memory.\n");
			printf( "Total megabytes allocated = %d\n", NumberOfAllocations );
            exit(0);
        }
		NumberOfAllocations++;

		if ( ( NumberOfAllocations % 100 ) == 0 )    // Print out status every so often
			printf( "We have allocated %d Megabytes\n", NumberOfAllocations );

		TempPointer = MemoryPtr;
		if ( Function == 2 )   
		{                     // Read from each page in the megabyte
			while ( (unsigned long)TempPointer < (unsigned long)((long)MemoryPtr + ONE_MEG) )  
			{
					Temp                   = TempPointer[0];
					TempPointer = (long *)((unsigned long)TempPointer +4096);
			}          // End of while
		}              // End of if Function is Read

		if ( Function == 3 )    
		{                    // Write to each page in the megabyte
			while ( (unsigned long)TempPointer < (unsigned long)((long)MemoryPtr + ONE_MEG) )  
			{
					TempPointer[0] = Temp;
					TempPointer = (long *)((unsigned long)TempPointer +4096);
			}          // End of while
		}              // End of if Function is Write
    }                  // End of while memory still can be allocated

}                             // End of main

void  RecursiveRoutine( int RecursiveDepth )
{
    char    Temp[ STACK_ALLOC ];
    char    StringTop[32];
    char    StringBottom[32];

    strcpy( StringTop,  commas( (unsigned long)(FirstStackLocation) ) );
    strcpy( StringBottom, commas( (unsigned long)&(Temp[STACK_ALLOC]) ) );
    printf("Iteration = %3d:  Stack Top/Bottom/Bytes: %s  %s  %d\n", 
             RecursiveDepth, StringTop, StringBottom,
             FirstStackLocation - (unsigned long)&(Temp[STACK_ALLOC])  );
    RecursiveDepth++;
    RecursiveRoutine( RecursiveDepth );
}
char *commas(unsigned long amount)
{
    short i;
    short offset = MAXTEXT-1;   /* where the string "starts"  */
    short place;                /* the power of BASE for      */
                                /* current digit              */
    static char text[MAXTEXT];

    for ( i = 0; i < MAXTEXT; i++ )
        text[i] = '\0';
					     
   /* Push digits right-to-left with commas */
   for (place = 0; amount > 0; ++place)
     {
      if (place % GROUP == 0 && place > 0)
         offset = prepend(text,offset,",");
      offset = preprintf(text,offset,"%X",amount % BASE);
      amount /= BASE;
    }
    return (offset >= 0) ? text + offset : NULL;
}
    /* preprint.c: Functions to prepend strings */
int prepend(char *buf, unsigned offset, char *new_str)
{
    int new_len = strlen(new_str);
    int new_start = offset - new_len;
    /* Push a string onto the front of another */
    if (new_start >= 0)
        memcpy(buf+new_start,new_str,new_len);
    
    /* Return new start position (negative if underflowed) */
    return new_start;
}
    
int preprintf(char *buf, unsigned offset, char *format, ...)
{
    int pos = offset;
    char *temp = malloc(BUFSIZ);
    
    /* Format, then push */
    if (temp)
    {
        va_list args;
        
        va_start(args,format);
        vsprintf(temp,format,args);
        pos = prepend(buf,offset,temp);
        va_end(args);
        free(temp);
    }
    return pos;
}

