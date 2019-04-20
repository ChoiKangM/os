#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("hello world (pid:%d)\n", (int)getpid());
	int rc = fork();
	// fork failed; exit
	if(rc < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	// child (new process)
	else if (rc == 0)	
	{
		printf("hello, I am child (pid:%d)\n", (int)getpid());
	}
	//parent goes down this path (main)
	else
	{
		printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
	}
	return 0;
}