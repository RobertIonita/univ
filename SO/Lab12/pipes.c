#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//*
void main()
{
	//declarare descriptor de pipe
	int descriptor[2];
	int nr; 
	char data[100] = "test whatever random text is here";
	char buffer[100];
	
	//deschidere pipe
	pipe(descriptor);
	
	if(fork()==0)
	{
		//se inchide descriptorul care nu este folosit
		close(descriptor[1]);
		nr = read(descriptor[0], buffer, sizeof(buffer));
		printf("Mesajul citit: %s\n", buffer);
	}
	else
	{
		//as above
		close(descriptor[0]);
		sleep(3);
		write(descriptor[1], data, strlen(data) + 1);
		wait(NULL);
	}
}
//*/

/*
void main()
{
	int fileDes;

	fileDes = creat("outputfile.txt", 0777);

	//option 1 - dup
	close(1);
	dup(fileDes);

	//option 2 - dup2
	//dup2(fileDes, 1);

	printf("You expected me to be in the terminal.\n");
	printf("Surprise!");

	close(fileDes);
}
*/

/*
void main()
{
	int descriptor[2];
	int nr; 
	char data[100] = "another random text test is here";
	char ch;
	
	pipe(descriptor);
	
	if(fork()==0)
	{
		close(descriptor[1]);

		nr = read(descriptor[0], &ch, 1);
		while(nr)
		{
			printf("Caracter citit: '%c'\n", ch);
			nr = read(descriptor[0], &ch, 1);
		}
	}
	else
	{
		int i;
		close(descriptor[0]);
		sleep(3);

		for (i=0; i < strlen(data); i++)
			write(descriptor[1], &data[i], 1);

		//close(descriptor[1]);
		wait(NULL);
	}
}
*/

