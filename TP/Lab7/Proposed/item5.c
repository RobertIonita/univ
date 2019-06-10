#include <stdio.h>
#include <stdlib.h>

#define MAX 20


void dynamicRead(char **str, FILE *terminal, char finish)
{
    char ch;
    unsigned short
        size = 1,
        index = 0;
    *str = (char *)malloc(sizeof(char) * size);
    while ((ch = fgetc(terminal)) != EOF && ch != finish)
    {
        (*str)[index++] = ch;
        if (index == size)
            (*str) = realloc((*str), sizeof(char) * (size += 1));
    }
    (*str)[index++] = '\0';
}

int split(char ***token, char *str, char separator)
{
    int j = 0, k = 0, i = 0,
        size = 0;
    *token = (char **)malloc(sizeof(char *) * (size+1));
    (*token)[k] = (char *)malloc(sizeof(char) * (j));

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != separator)
        {
            (*token)[k] = realloc((*token)[k], sizeof(char) * (j + 1));
            (*token)[k][j++] = str[i];
            size++;
        }
        else
        {
            *token = realloc(*token, sizeof(char *) * (size + 1));
            (*token)[k++][j] = '\0';
            j = 0;
        }
    }
    return k+1;
}

void showOff(char(**arr), int n)
{
    for (int i = 0; i < n; i++)
        printf("\n%s", arr[i]);
}

int main(void)
{
    char *input,
        (**token);
    int r;
    printf("input string : ");
    dynamicRead(&input, stdin, '\n');
    printf("%s\n", input);
    r = split(&token, input, ' ');
    showOff(token, r);
    free(input);
    return 0;
}