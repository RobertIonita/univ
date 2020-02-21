#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int desc[2];
pid_t fiu, fiu2;
char data[100] = "simple message";
char buffer[100];
int statusinfo1,statusinfo2;

void handlerSIGUSR1(int sig)
{
	write(desc[1], data, (strlen(data)+1));
	close(desc[1]);
}

int main(void){

	if (pipe(desc) < 0){
		perror("Eroare la pipe");
		exit(1);
	}
	if (fiu = fork())  //Parinte P1
	{
		close(desc[0]);
		close(desc[1]);
		sleep(1);
		kill(fiu, SIGUSR1);
		wait(NULL);	
		//waitpid(fiu,&statusinfo1,0);
	}
	else //Fiu1
	{
		if (fiu2 = fork()) // Fiu1 e parinte pentru Fiu2 P2
		{	
			close(desc[0]);
			if (signal(SIGUSR1, handlerSIGUSR1) == SIG_ERR)
			{
				perror("Eroare la apel signal\n");
				exit(1);
			}
			//waitpid(fiu2,&statusinfo2,0);

			wait(NULL);	
			//exit(27);
		}
		else //Fiu2 P3
		{
			close(desc[1]);
			read(desc[0], buffer, sizeof(buffer));
			printf("Mesajul citit: %s\n", buffer);
			close(desc[0]);
			//exit(27);
		}
	}
return 0;
}
