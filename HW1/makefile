CC=gcc


helloStackQueue : SQmain.o SQApi.o
	$(CC) -o helloStackQueue SQmain.o SQApi.o

SQmain.o : SQmain.c
	$(CC) -c SQmain.c

SQApi.o : SQApi.c
	$(CC) -c SQApi.c

clean:
	/bin/rm -f core *.o


	