#include <stdio.h>

#define MAX 100


int length(char (*str)[]) {
    int i;
    for (i = 0; (*str)[i] != '\0'; i++);
    return i;
}

int includes(char (*string)[], char (*substr)[]) {

    int i, j,
        k = 0,
        len1 = length(&(*string)),
        len2 = length(&(*substr));


    if (len1 < len2) {
        return -1;
    } 
    for (i = 0; i < len1; i++) {
        for(j = 0; j < len2 && (*string)[i+j] == (*substr)[j]; j++) {
            if(++k == len2) return 1;
        }
    }
    return -1;
}


int main() {

    char str1[MAX],
        str2[MAX];
    printf("Insert first string: ");
    scanf("%s", str1);

    printf("Insert second string: ");
    scanf("%s", str2);

    printf("%d", includes( &str1, &str2));

    return 0;
}