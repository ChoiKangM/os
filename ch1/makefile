CC=gcc


cpu : virtualizing_the_cpu.o
	$(CC) -o cpu virtualizing_the_cpu.o

mem : virtualizing_the_memory.o
	$(CC) -o mem virtualizing_the_memory.o

con : concurrency_example.c
	$(CC) con concurrency_example.c -lpthread

per : persistence.o
	$(CC) -o per persistence.o



virtualizing_the_cpu.o : virtualizing_the_cpu.c
	$(CC) -c virtualizing_the_cpu.c
    
virtualizing_the_memory.o : virtualizing_the_memory.c
	$(CC) -c virtualizing_the_memory.c

# concurrency_example.o : concurrency_example.c
#	$(CC) -c concurrency_example.c -Wall -pthread

persistence.o : persistence.c
	$(CC) -c persistence.c

clean:
	/bin/rm -f core *.o


	