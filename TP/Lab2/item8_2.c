#include <stdio.h>

#define MAX 5
#define row 25
#define col 25


void split (int nr) {
    int digit,
        arr[10],
        k = 0;
    while (nr) {
        digit = nr % 10;
        arr[k++] = digit;
        nr /= 10;
    }
}

void populate(int (*arr)[MAX][MAX]) {
    int i, j,
        intit = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++, intit++) {
            (*arr)[i][j] = intit;
        }
    }
}
void showOff(int (*arr)[MAX][MAX]) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%4d ", (*arr)[i][j]);
        }
        printf("\n");
    }
}

void showOffVect(int (*vect)[], int el_nr) {
    int i;
    for (i = 0; i < el_nr; i++) {
        printf("%4d ", (*vect)[i]);
    }
}

void findMatches (int arr[][MAX], int (*vect)[], int *el_nr) {
    int i, j,
        el = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++, el++) {
            (*vect)[el] = arr[i][j];
            while(arr[i][j]) {
                (*vect)[el] = arr[i][j]%10;
                (*el_nr)++;
                arr[i][j] /= 10;
            }
        }
    }
    

}

int main(void) {
    int M[MAX][MAX],
        v[] = {0},
        els = 0;

    populate(&M);

    printf("\nMatrix is: \n");
    showOff(&M);

    findMatches(M, &v, &els);

    printf("\nVect is: \n");
    showOffVect(&v, els);

}