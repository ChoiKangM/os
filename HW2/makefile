CC=gcc
OBJ=main.o pwd.o help.o 

myShell : $(OBJ)
    $(CC) -o myShell $(OBJ)

main.o : main.c
    $(CC) -c main.c
    
pwd.o : pwd.c
    $(CC) -c pwd.c

help.o : help.c
    $(CC) -c help.c


clean :
    /bin/rm -f core *.o