#include <stdio.h>

#define MAX 100

int compare(char (*first)[], char (*second)[]) {

    int i,
        a, b;
    for(i = 0; (*first)[i] != '\0' || (*second)[i] != '\0'; i++) {

        a = (*first)[i];
        b = (*second)[i];

        if (a < b) {
            return 1;
        } else if (a > b) {
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

    printf("%d", compare(&str1, &str2));

    return 0;
}