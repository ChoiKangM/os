CC=gcc


pl : fork_ex.o
	$(CC) -o pl fork_ex.o

fork_ex.o : fork_ex.c
	$(CC) -c fork_ex.c

clean:
	/bin/rm -f core *.o