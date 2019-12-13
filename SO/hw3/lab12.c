#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/*
int main ()
{
// pipe descriptor

int descriptor[2],
nr;
char buffer[100];

// open pipe

pipe(descriptor);

if(fork()==0) // child
{
// not used descriptor is being closed
close(descriptor[1]);
nr = read(descriptor[0], buffer, sizeof(buffer));
printf("\nMessage: %s\n", buffer);
}
else // parent
{
char data[100] = "test text";
close(descriptor[0]);
write(descriptor[1], data, strlen(data) + 1);
close(descriptor[1]);
wait(NULL);
}
return 0;
}

int main ()
{
int fileDes;

fileDes = creat("output.txt", 0777);
// option 1 - dup
close(1);
dup(fileDes);

// option 2 -dup2, auto closes new file descriptor
// dup2(fileDes, 1);

printf("You expected me to be in the terminal.");
printf("\nSurprise, bitch\n");

close(fileDes);

return 0;
}

*/