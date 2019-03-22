#include <stdio.h>

#define MAX 100

int compare(char (*first)[], char (*second)[]) {

    int i;
    for (i = 0; (*first)[i] != '\0' || (*second)[i] != '\0'; i++) {

        if ( (*first)[i] < (*second)[i]) {
            return 1;
        } else if ( (*first)[i] > (*second)[i]) {
            return -1;
        }
    }
    return 0;
}


int main() {

    char str1[MAX],
        str2[MAX];
    printf("Insert first string: ");
    scanf("%s", str1);

    printf("Insert second string: ");
    scanf("%s", str2);

    printf("%d", compare( &str1, &str2));

    return 0;
}