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
	printf("help, pwd, myls, mycd, exit\n");

	while (true)
	{
		printf("-> ");
		gets(str);

        if (!strcmp("help", str))
			help();
        if (!strcmp("pwd", str))
			pwd();
        if (!strcmp("myls", str))
			myls();
        if (!strcmp("mycd", str))
			//dmycd();
		if (!strcmp("exit", str))
			break;
	}

	return 0;
}
