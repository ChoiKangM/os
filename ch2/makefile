
fork : fork_system_call.o
	gcc -o fork fork_system_call.o
	
fork_system_call.o : fork_system_call.c
	gcc -c fork_system_call.c
	
fork_test_1 : fork_test_1.c
	gcc -g -o fork_test_1 fork_test_1.c

fork_test_2 : fork_test_2.c
	gcc -c fork_test_2 fork_test_2.c
    
pthread : pthread_linux.o
	gcc -o pthread pthread_linux.o

pthread_linux.o : pthread_linux.c
	gcc -c pthread_linux.c -lpthread
	
unix_file : UNIX_File_example.o
	gcc -o unix_file UNIX_File_example.o
	
UNIX_File_example.o : UNIX_File_example.c
	gcc -c UNIX_File_example.c
	
clean :
	/bin/rm -f core *.o