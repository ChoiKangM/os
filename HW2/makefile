CC=gcc
OBJ=main.o pwd.o help.o myls.o mycd.o

myShell : $(OBJ)
	$(CC) -o myShell $(OBJ)

.c.o :
	$(CC) -c $< -o $@

clean :
	/bin/rm -f core *.o