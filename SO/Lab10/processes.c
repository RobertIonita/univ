#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

//how to basic fork
//*
int main()
{
	pid_t pid;

	printf("PID of parent process: %d\n", (int)getpid());

	if((pid=fork()) > 0) //this is still the main process
	{
		//sleep(1);
		printf("PID of parent process: %d\n", (int)getpid());
	}
	else //this is the child process
	{
		printf("PID of child process: %d\n", (int)getpid());
	}
	return 0;
}
//*/

//alternate how to basic fork
/*
void main()
{
	pid_t pid;

	printf("PID of parent process: %d\n", (int)getpid());

	pid=fork(); //fork before splitting code
	if(pid!=0) //this is still the main process
	{
		printf("PID of parent process: %d\n", (int)getpid());
	}
	else //this is the child process (aka pid == 0)
	{
		printf("PID of child process: %d\n", (int)getpid());
	}
}
/*/

//how to run terminal commands - exec
/*
void main()
{
	printf("Exec example: ls -l\n");
	execl("/bin/ls", "ls", "-l", 0);
	printf("This thing here will NOT be printed");
}
*/

//how to wait for child to finish his chores
/*
void main()
{
	pid_t pid;
	int statusinfo;

	if(pid=fork())
	{
		wait(&statusinfo);
		printf("Parent process done.\n");
		printf("Child status code: %d\n", WEXITSTATUS(statusinfo));
	}
	else
	{
		sleep(1);
		printf("1\n");
		sleep(1);
		printf("2\n");
		sleep(1);
		printf("3\n");
		sleep(1);
		printf("4\n");
		sleep(1);
		printf("5\n");
		printf("Child process reached end.\n");
		exit(55);
	}
}
*/
