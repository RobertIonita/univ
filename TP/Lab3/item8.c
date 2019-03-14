#include <stdio.h>
#include <math.h>

#define MAX 100

int main(void) {
    char string[MAX];
    int rank,
        i, j,
        k = 0,
        len;
    float root;
    printf("\nInsert string: ");
    scanf("%[^.]s", string);

    for (len = 0; string[len] != '\0'; len++);
    root = sqrt(len);
    rank = trunc(++root);

    char matrix[rank][rank];
    printf("\nMatrix is:\n");

    for(i = 0; i < rank; i++) {
        for(j = 0; j < rank && len-k; j++, k++) {
            if (string[k] == ' ' || string[k] == '\n') {
                while(string[k++] != ' ');
            }
            matrix[i][j] = string[k];
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}