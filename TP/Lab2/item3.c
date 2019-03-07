#include <stdio.h>
#define N 6

void showOff(float (*arr)[][N], int n){
    int i, j;
    for(i=0; i< n; i++) {
        for(j=0; j< n; j++) {
            printf(" %6.2f ", (*arr)[i][j]);
        }
        printf("\n\n");
    }

}
void populate (float (*arr)[][N], int n) {
    int i, j;
    float s = 0;
    for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++, s++) {
            (*arr)[i][j] = s/4;
        }
    }
}



int main(void) {

    int  i, j,
        check,
        summ = 0;
    float matrix[N][N];

    populate(&matrix, N);
    printf("\nMatrix is: \n"); showOff(&matrix, N);

    for(i = 0; i<N; i++) {
        for(j = i+1; j<N; j++) {
            check = matrix[i][j];
            if (matrix[i][j] == check) summ += check;
        }
    }
    printf("\nsumm of odd numbers is: %d", summ);
    return 0;
}