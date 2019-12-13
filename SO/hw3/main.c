#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pid_t pid;

int main(void)
{
    pid = fork();
    if (pid)
    {
        printf("\nHello, I'm parent!");
    }
    else if (pid == -1)
    {
        printf("\nnu se poate");
    }
    else
    {
        printf("\nHello, I'm son!");
    }
    return 0;
}