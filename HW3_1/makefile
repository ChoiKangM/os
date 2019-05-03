CC=gcc
OBJ=pthreadWithVolatile.o

pthread : pthreadWithVolatile.c
	$(CC) -o pthread pthreadWithVolatile.c -Wall -pthread




.c.o :
	$(CC) -c $< -o $@


clean:
	/bin/rm -f core *.o
