#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

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