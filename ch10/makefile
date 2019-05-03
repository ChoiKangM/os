CC=gcc
OBJ= banking_example.o bank.o


bank : bank $(OBJ)
	$(CC) -Wall -lpthread -o bank $(OBJ)
	
# gcc -Wall -lpthread -o bank banking_example.c
#  while true; do ./bank; sleep 1; done;

.c.o :
	$(CC) -c $< -o $@

clean :
	/bin/rm -f core *.o