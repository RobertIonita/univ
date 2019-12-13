#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
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
void handler(int sig)
{
	printf("\nALARM");
	alarm(5);
}

int main ()
{
	signal(SIGALRM, handler);
	// SIGALARM - wait for alarm()
	alarm(5);
	for (int i = 0; i <= 11; i++)
	{
		printf("\n%2d Hello, World", i);
		sleep(1);
	}
	return 0;
}
*/

void handler(int sig)
{
	printf("\nHi there!");
}

int main ()
{	int pid;
	pid = fork();
	if(pid)
	{
		int status;
		sleep(5);
		kill(pid, SIGUSR2);
		wait(&status);
	}
	else
	{
		signal(SIGUSR2, handler);
		for (int i = 1; i <= 10; i++)
		{
			sleep(1);
			printf("\n%2d Child process working..", i);
		}	
	}
	return 0;
}