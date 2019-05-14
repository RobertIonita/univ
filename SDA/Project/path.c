#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void run()
{
    char cwd[1024],
        open[1024] = "open ";
    if (!getcwd(cwd, sizeof(cwd)))
        perror("getcwd() error");
    strcat(open, cwd);
    strcat(open, "/SDA/Project/index.html");
    printf("file: %s", open);
    system(open);
}

int main()
{
    run();
    return 0;
}