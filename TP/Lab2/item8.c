#include <stdio.h>

#define MAX 5

void populate(int (*arr)[MAX][MAX]) {
    int i, j,
        intit = 10;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++, intit++) {
            (*arr)[i][j] = intit;
        }
    }
}
void showOff(int (*arr)[MAX][MAX]) {
    int i, j;
        printf("\n");

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%4d ", (*arr)[i][j]);
        }
        printf("\n");
    }

}

void findMatches (int arr[][MAX], int *(vect)[]) {

}

int main(void) {
    int M[MAX][MAX],
        v[100];


    populate(&M);
    findMatches(M, &v);
    printf("\nMatrix is: \n");
    showOff(&M);

}