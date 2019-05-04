CC=gcc

withMutex : pthreadWithMutex.c
	$(CC) -o withMutex pthreadWithMutex.c -Wall -pthread

withoutMutex : pthreadWithoutMutex.c
	$(CC) -o withoutMutex pthreadWithoutMutex.c -Wall -pthread



.c.o :
	$(CC) -c $< -o $@


clean:
	/bin/rm -f core *.o
