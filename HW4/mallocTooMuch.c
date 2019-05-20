///////////////////////////////////////////////////////////////////////////
//  TouchLotsOfMemory.c
//  This program allocates memory from the heap and 
//  1.  Touches it by reading from it.
//  2.  Modifies it by writing to it.
//  3.  Neither - the memory is never accessed.
//
//  Arg 1 - The memory size (in Megabytes) to be allocated.
//  Arg 2 - Specify <Read, Write, Neither> for touching the memory.
//          Compiler Instructions:
//          Windows:  gcc -g TouchLotsOfMemory.c -o TouchLotsOfMemory
//
//  Running Hints:  You can use top to find the total memory on LINUX system
//                  vmstat -5 gives running account of memory usage.
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define   ONE_MEG   1048576
///////////////////////////////////////////////////////////////////////////
//  Prototypes  &  Globals
///////////////////////////////////////////////////////////////////////////
long       *MemoryPtr;

///////////////////////////////////////////////////////////////////////////
//  The main code is here
///////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]){

    long         NumberOfMegaBytes, NumberOfAllocations = 0;
    long         Temp;
    long         *TempPointer;
    char         MemoryFunction[32];
    int          Function = 0;

    if (argc < 3 ) {
        printf( "Usage: %s <MemorySizeInMegabyte> <Read|Write|Nothing>\n", argv[0]);
        exit(1);
    }

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

