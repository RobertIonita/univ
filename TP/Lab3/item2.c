#include <stdio.h>

#define MAX 100

int matches(char (*str)[], char ch) {

    int i, k;

    for (i = 0;  (*str)[i] != '\0'; i++) {
        if ( (*str)[i] == ch) k++;
    }
    return k;
}


int main() {

    char str[MAX],
        ch;
    printf("Insert string: ");
    scanf("%s", str);

    printf("Insert character: ");
    scanf(" %c", &ch);

    printf("%d", matches( &str, ch));

    return 0;
}