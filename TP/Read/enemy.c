#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 256

int main(void)
{
    char *input;
    FILE *f, *g;
    f = fopen("TP/Read/input.txt", "r");

    clock_t begin = clock();
    fgets(input, MAX, f);
    clock_t end = clock();

    fclose(f);

    g = fopen("TP/Read/output.txt", "w");
    fprintf(g, "%s", input);
    fclose(g);

    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\ntook %f", time);
    // free(input);
    return 0;
}