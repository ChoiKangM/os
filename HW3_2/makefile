CC=gcc
OBJ=matrixMultiplication.o

matrix : matrixMultiplication.c
	$(CC) -o matrix matrixMultiplication.c -Wall -pthread




.c.o :
	$(CC) -c $< -o $@


clean:
	/bin/rm -f core *.o
