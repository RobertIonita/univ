#include <stdio.h>

#define MAX 100

int length(char (*str)[]) {

    int i;
    for (i = 0; (*str)[i] != '\0'; i++);
    return i;
}


int main() {

    char str[MAX];
    printf("Insert string: ");
    scanf("%s", str);

    printf("%d", length( &str));

    return 0;
}