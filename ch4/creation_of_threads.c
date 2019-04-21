#include <stdio.h>
#include <pthread.h>

void *func1(void *args)
{
	int i = *((int*)args);
	printf("Phrase %i: Powerful Minds goes crazed after learning the truth\n", i);
	pthread_exit(0);
}
void *func2(void *args)
{	
	int i = *((int*)args);
	printf("Phrase %i: Look at the stars, even giants leave only a speckle after they are gone\n", i);
	pthread_exit(0);
}
void *func3(void *args)
{
	int i = *((int*)args);
	printf("Phrase %i: Madness is the step after genius\n", i);
	pthread_exit(0);
}
int main(int argc, char **argv)
{
	void *funcs[3];
	int i, y[3];
	pthread_t id[3];
	funcs[0] = func1;
	funcs[1] = func2;
	funcs[2] = func3;
	for(i=0;i<3;i++)
	{
		y[i] = i + 10;
		if(pthread_create(&id[i],NULL,funcs[i],(void*)&y[i]))
		{
			printf("Error: in pthread creation\n");
			return(0);
		}
	}
	return(0);
}