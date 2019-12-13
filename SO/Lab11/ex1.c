#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


void handler(int sig)
{
	if(sig == SIGINT)
		printf("\nSIGINT captured!");
	else if (sig == SIGSTOP)
		printf("\nSIGSTOP captured!");
	printf("\nInterrupt handler has been called");
}

int main ()
{
	signal(SIGINT, handler);
	// signal() - latch SIGINT parameter with funtion of the second parameter

	for (int i = 0; i < 10; i++)
	{
		printf("\n%d Hello, World", i);
		sleep(1);
	}
	return 0;
}