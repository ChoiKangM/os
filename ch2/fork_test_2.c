#include <stdio.h>

int main(int argc, char * argv[])
{
	int pid;
	// fork another process
	pid = fork();
	// error occured
	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	//child process
	else if(pid==0)
	{
		execlp("/root/syscall/text", "test", NULL);
	}
	//parent process
	else
	{
		//parent will wait for the child to complete
		wait(NULL);	
		printf("Child Complete\n");
	}
	printf("PID == %d\n", getpid());
	exit(0);
}