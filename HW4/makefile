CC=gcc

mallocTooMuch : mallocTooMuch.o
	$(CC) -o mallocTooMuch mallocTooMuch.o

recursiveCall : recursiveCall.o
	$(CC) -o recursiveCall recursiveCall.o

checkStackHeap : checkStackHeap.o
	$(CC) -o checkStackHeap checkStackHeap.o



.c.o :
	$(CC) -c $< -o $@


clean:
	/bin/rm -f core *.o
