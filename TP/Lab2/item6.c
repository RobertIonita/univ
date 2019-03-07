#include <stdio.h>

#define MAX 10


void quit() {
    printf("\nquiting..");
}
void populate(int arr[MAX][MAX], int * x) {
    int i, j, s = 0;
    for (i = 0; i < * x; i++) {
        for (j = 0; j < * x; j++, s++) {
            arr[i][j] = s*s;
        }
    }
}
void showOff(int arr[][MAX], int * x) {
    int i, j;
        printf("\n");

    for (i = 0; i < * x; i++) {
        for (j = 0; j < * x; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

}

int main(void) {
    int M[MAX][MAX],
        n = 0;

    printf("\nInsert nr of lines and columns: ");
    scanf("%d", & n);

    populate(M, &n);

    printf("\nMatrix is: \n");
    showOff(M, &n);

}