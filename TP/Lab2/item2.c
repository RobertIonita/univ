#include <stdio.h>

#define rows 5
#define cols 7

void showOff (int vect[cols][rows]) {
    int i, j;
    for(i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%3d ", vect[i][j]);
        }
        printf("\n");
    }
}

void trans (int (*t)[cols][rows], int vect[rows][cols]) {

    int i, j;
    for(i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            (*t)[i][j] = vect[j][i]; 
        }
    }
};


int main() {

    int v[rows][cols],
        t[cols][rows],
        i, j,
        s=0;

    printf("\nInintial matrix: \n");


    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++, s++) {
            v[i][j] = s;
            printf("%3d ", v[i][j]);
        }
        printf("\n");
    }

    trans(&t, v);
    printf("\nResult matrix: \n"); showOff(t);

    return 0;
}