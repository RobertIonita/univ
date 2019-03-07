#include <stdio.h>

#define MAX 10

void populate(float arr[MAX][MAX], int * x, int * y) {
    int i, j;
    for (i = 0; i < * x; i++) {
        for (j = 0; j < * y; j++) {
            printf("\narr[%d][%d]: ", i, j);
            scanf("%f", & arr[i][j]);
        }
    }
}
void showOff(float arr[][MAX], int * x, int * y) {
    int i, j;
        printf("\n");

    for (i = 0; i < * x; i++) {
        for (j = 0; j < * y; j++) {
            printf("%5.2f ", arr[i][j]);
        }
        printf("\n");
    }

}
void multiplication(float( * mult)[][MAX], float arr1[][MAX], float arr2[][MAX], int x, int y) {
    int i, j, k;
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            (*mult)[i][j] = 0;
            for (k = 0; k < y; k++) {
                (*mult)[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main(void) {
    float m1[MAX][MAX],
        m2[MAX][MAX],
        m3[MAX][MAX];

    int n = 0, m = 0,
        N = 1, M = 1;

    do {
        printf("\nInsert nr of lines and columns of first matrix: ");
        scanf("%d %d", & n, & m);

        printf("\nInsert nr of lines and columns of second matrix: ");
        scanf("%d %d", & N, & M);
        if (n != M || N != m) {
            printf("\nIncompatible matrices");
        }

    } while (n != M || N != m);

    printf("\nPopulate first matrix: ");
    populate(m1, & n, & m);
    printf("\nPopulate second matrix: ");
    populate(m2, & N, & M);

    printf("\nFirst matrix is: \n");
    showOff(m1, & n, & m);
    printf("\nSecond matrix is: \n");
    showOff(m2, & N, & M);

    if (n > N) N = n;

    multiplication( & m3, m1, m2, n, N);

    printf("\nResult matrix is: \n");
    showOff(m3, & N, & N);
}