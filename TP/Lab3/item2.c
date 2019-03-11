#include <stdio.h>

#define MAX 100

int matches(char (*str)[], char ch) {

    int i, k,
        a, b;
        b = ch;
    for(i = 0; (*str)[i] != '\0'; i++) {

        a = (*str)[i];
        if (a == b) k++;
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

    printf("%d", matches(&str, ch));

    return 0;
}