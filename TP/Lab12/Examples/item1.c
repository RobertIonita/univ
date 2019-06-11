#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main(int argc, char *argv[])
{
    char buffer[MAX];
    FILE *fs, *fd;
    int nr;
    if ((fs = fopen("TP/Lab12/assets/fbin.dat", "rb")) == NULL)
    {
        printf("\nerror");
        exit(EXIT_FAILURE);
    }
    if ((fd = fopen("TP/Lab12/assets/f02.dat", "rb")) == NULL)
    {
        printf("\nerror");
        exit(EXIT_FAILURE);
    }
    while (!feof(fs))
    {
        nr = fread(buffer, 1, MAX, fs);
        fwrite(buffer, 1, nr, fd);
    }
    fclose(fs);
    fclose(fd);
    return 0;
}