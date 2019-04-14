CC=gcc

myShell : main.o pwd.o
    $(CC) -o myShell main.o pwd.o

main.o : main.c
    $(CC) -c main.c
    
pwd.o : pwd.c
    $(CC) -c $pwd.c

clean :
    /bin/rm -f core *.o