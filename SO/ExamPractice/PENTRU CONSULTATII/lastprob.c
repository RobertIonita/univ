#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

pid_t c_pid;

void parent_handler(int sig)
{
	printf("\ngasit\n");
	exit(0);
}

void murder_time(int sig)
{
	int exitStatus;

	//stab
	kill(c_pid, SIGKILL);
	//what's the status
	wait(&exitStatus);
	//self-stab
	exit(0);
}

void main(int argc, char *argv[])
{
	int teava[2];
	int bufSize;
	pid_t p_pid;
	
	//validation for argc/argv; not in specs
	
	//how long is the word?
	bufSize = strlen(argv[2]);
	char buffer[bufSize];
	
	//initialize pipe
	pipe(teava);
	
	//who am i? child process will need parent id to send it a signal
	p_pid = getpid();
	
	//spawn progeny
	c_pid = fork();
	
	if(c_pid) //parent process
	{
		//declarations
		int fileDes;
		
		//close what we ain't using
		close(teava[0]);
		//open file
		fileDes = open(argv[1], O_RDONLY);
		//get ready to be told by the child that he found something
		signal(SIGUSR1, parent_handler);
		//get ready to murder child process
		signal(SIGALRM, murder_time);
		//but only after 5 seconds
		alarm(5);
		
		//start writing
		while(read(fileDes, buffer, bufSize) != 0)
			write(teava[1], buffer, bufSize);
		
		//finished writing, clean up after ourselves
		close(teava[1]);
		
		//if the file finished, wait for the child to finish searching
		wait(NULL);
		
		//if we got this far, no signal was received, means word was not found (either at all, or within the time limit)
		printf("\ninexistent\n");
	}
	else //progeny
	{
		//what if the word gets split inbetween reads/writes?
		char biggerBuffer[bufSize*2];
		//close what we don't use
		close(teava[1]);
		
		//super "smart" algorithm
		//read <bufSize> characters, add them to the second half of <biggerBuffer>
		//then, search for word
		//if found, send signal to parent and stop
		//if not, copy second half of <biggerBuffer> over the first half of <biggerBuffer>
		//repeat until nothing to read
		
		//prepare the first half, otherwise it's gibberish
		int i;
		for(i=0;i<bufSize;i++)
			biggerBuffer[i] = ' ';
		
		//read from pipe
		while(read(teava[0], buffer, bufSize) > 0)
		{
			//that '+' is offsetting address - basically saying copy at position biggerBuffer[bufSize]
			strcpy(biggerBuffer + bufSize, buffer);
			
			//if we find our word...
			if(strstr(biggerBuffer, argv[2]))
			{
				//...let the parent process know
				kill(p_pid, SIGUSR1);
				//no point in continuing the search, is there
				exit(0);
			}
			
			//write over the first half of <biggerBuffer>
			strcpy(biggerBuffer, buffer);
		}
	}

}
