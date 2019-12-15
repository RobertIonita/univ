#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

unsigned int count = 0,
			 current = 0,
			 time[5],
			 second = 0,
			 value = 0;
int pipefdtr[2],
	pipefdst[2];
pid_t cpid;

void handleStatistics()
{
	printf("child recieved SIGUSR1.\n");
	time[second] = current;
	second++;
	count += current;
	current = 0;
}

void handleTransmit()
{
	int i;
	write(pipefdst[1], &count, sizeof(unsigned long));
	for (i = 0; i < 5; i++)
		write(pipefdst[1], &time[i], sizeof(unsigned long));
	close(pipefdst[1]);
	exit(EXIT_SUCCESS);
}
void handleAlarm()
{
	int i = 0;
	if (value == 5)
	{
		kill(cpid, SIGUSR2);
		read(pipefdst[0], &count, sizeof(unsigned long));
		printf("\nStatistics:\n");
		while (read(pipefdst[0], &time[i], sizeof(unsigned long)) > 0)
		{
			printf("@%d %u chars were sent\n", i + 1, time[i]);
			i++;
		}
		printf("%u chars sent overall\n", count);
		close(pipefdst[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		kill(cpid, SIGUSR1);
		value++;
		alarm(1);
	}
}

int main(int argc, char *argv[])
{
	char buff;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefdtr) == -1)
    {
        exit(EXIT_FAILURE);
    }
	perror("Transmision pipe");

	if (pipe(pipefdst) < 0)
	{
		exit(EXIT_FAILURE);
	}
	perror("Statistics pipe");

	if ((cpid = fork()) < 0)
	{
		exit(EXIT_FAILURE);
	}
	perror("fork");

	if (cpid == 0)
	{
		close(pipefdtr[1]);
		close(pipefdst[0]);
		signal(SIGUSR1, handleStatistics);
		signal(SIGUSR2, handleTransmit);
		while (read(pipefdtr[0], &buff, 1) > 0)
			current++;
		close(pipefdtr[0]);
		close(pipefdst[0]);
		exit(EXIT_SUCCESS);
	}

	else
	{
		close(pipefdtr[0]);
		close(pipefdst[1]);
		signal(SIGALRM, handleAlarm);
		alarm(1);
		while (1)
			write(pipefdtr[1], argv[1], 1);
	}
	return 0;
}
