#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
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