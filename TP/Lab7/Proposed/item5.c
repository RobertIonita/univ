#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void split(int length, char (*token)[length], char *str, char separator)
{
    int j = 0, k = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != separator)
        {
            token[k][j++] = str[i];
        }
        else
        {
            token[k][j] = '\0';
            k++;
            j = 0;
        }
    }
}

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
    printf("\n%llu", index);
}

int main(void)
{
    char *input,
        token[4][MAX];
    FILE *f;
    f = fopen("TP/Lab7/Proposed/test.txt", "r");
    printf("input string : ");
    dynamicRead(&input, f, '#');
    // printf("%s\n", input);

    free(input);
    return 0;
}