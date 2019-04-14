#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "instructions.h"
#define size 10

int main()
{
	char str[size]; 

	printf("-------------------SHELL-------------------\n");
	printf("help, pwd, ls, cd, exit\n");

	while (true)
	{
		printf("-> ");
		gets(str);

        if (!strcmp("help", str))
			help();
        if (!strcmp("pwd", str))
			pwd();
        if (!strcmp("ls", str))
			ls();
        if (!strcmp("cd", str))
			cd();
		if (!strcmp("exit", str))
			break;
	}

	return 0;
}
