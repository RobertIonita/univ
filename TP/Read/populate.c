#include <stdio.h>
#include <stdlib.h>

#define MAX 20000000
int main () {
    FILE *f = NULL;
    f = fopen("TP/Read/input.txt", "w");
    for (size_t i = 0; i < MAX; i++)
    {
        fputc('a', f);
    }
    fputc('#', f);
    fclose(f);
    return 0;
}