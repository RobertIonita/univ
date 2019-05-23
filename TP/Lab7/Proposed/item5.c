#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 80

void shift(char *str, int times)
{
    int i = 0;
    for (i = 0; str[i + times] != '\0'; i++)
        str[i] = str[i + times];
    str[i] = '\0';
}

char *trim(char *str, char ch)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    while (str[--i] == ch)
        str[i] = '\0';
    i = -1;
    while (str[++i] == ch)
        ;
    shift(str, i);
    return str;
}

void split(char (*clone)[3], char *str, char separator) {
    int j = 0, k = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != separator) {
            clone[k][j++] = str[i];
        } else {
            clone[k][j] = '\0';
            k++; j = 0;
        }
    }
    for (int i = 0; i < 4; i++)
        printf("\n[%d]: %s", i, clone[i] );
}

void read (char *str, char (*arr)[3]) {
    scanf("%[^\n]s", str);
    split(arr, str, ' ');
    printf("%s", str);
}

int main () {
    char *input,
        arr[4][3];
    read(&input, arr);

    return 0;
}