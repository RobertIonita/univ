#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

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