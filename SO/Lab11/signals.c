#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

//*
void handler(int sig)
{
	printf("Interrupt handler has just been called.\n");
	
	(void)signal(SIGINT,handler);
}

void main()
{
	//functia signal - leaga semnalul dat in parametrul 1 (SIGINT), de functia data in parametrul 2 (handler)
	(void)signal(SIGINT,handler);
	//semnalul SIGINT ('signal interrupt') asteapta o intrerupere a programului, de exemplu Ctrl-C
	int i = 0;
	//pierdem timpul cat asteptam un semnal de intrerupere din consola/terminal
	while(i<10)
	{
		printf("Hello World!\n");
		sleep(1);
		i++;
	}
}
//*/

/*
void handler(int sig)
{
	printf("ALARM!\n");
	alarm(5);
}

void main()
{
	//SIGALRM - 'signal alarm' asteapta aparitia semnalul dat de functia alarm()
	(void)signal(SIGALRM,handler);
	//alarm(int n) - asteapta n secunde, apoi transmite semnalul SIGALRM
	alarm(5);
	int i = 1;
	while(i<=11)
	{
		printf("%d Hello World!\n", i);
		sleep(1);
		i++;
	}
}
*/

/*
void handler(int sig)
{
	printf("BINGO!\n");
	(void)signal(SIGUSR1,handler);
}

void main()
{
	int pid;

	pid = fork();
	if(pid)
	{
			int status;
			sleep(5);
			//functia kill transmite procesului cu pid egal cu primul parametru, semnalul dat ca al doilea parametru
			kill(pid, SIGUSR1);
			wait(&status);			
	}
	else
	{
		(void)signal(SIGUSR1,handler);	
		int k = 1;
		while(k<=10)
		{
			sleep(1);	
			printf("%d Child process working...\n", k);		
			k++;
		}
	}
	
}
*/
