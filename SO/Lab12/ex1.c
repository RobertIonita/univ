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
    // pipe descriptor

    int descriptor[2],
        nr;
    char buffer[100];

    // open pipe

    pipe(descriptor);

    if (fork() == 0) // child
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
