#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dynamicRead(char **str, FILE * terminal, char finish)
{
    char ch;
    unsigned long long
        size = 1,
        index = 0;
    *str = (char*) malloc(sizeof(char) * size);
    while ((ch = fgetc(terminal)) != EOF && ch != finish)
    {
        (*str)[index++] = ch;
        if (index == size)
        {
            (*str) = realloc((*str), sizeof(char) * (size += 1));
        }
    }
    (*str)[index++] = '\0';
}

int main(void)
{
    char *input;
    FILE *f, *g;
    f = fopen("TP/Read/input.txt", "r");

    clock_t begin = clock();
    dynamicRead(&input, f, '#');
    clock_t end = clock();

    fclose(f);

    g = fopen("TP/Read/output.txt", "w");
    fprintf(g, "%s", input);
    fclose(g);

    double time = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\ntook %f", time);
    free(input);
    return 0;
}