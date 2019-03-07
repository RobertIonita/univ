#include <stdio.h>

#define rows 5
#define cols 7
#define line 2

void showOff (int vect[rows][cols]) {
    int i, j;
    for(i = 0; i < rows+1; i++) {
        for (j = 0; j < cols; j++) {
            printf("%3d ", vect[i][j]);
        }
        printf("\n");
    }
}

void zeros (int (*vect)[rows][cols]) {

    int i, j;
    for(i = rows+1; i > 0; i--) {
        for (j = 0; j < cols; j++) {
            if(i > line) {
                (*vect)[i+1][j] = (*vect)[i][j];
            }
            if(i == line+1) {
                (*vect)[i][j] = 0;
            }
        }
    }
};


int main() {

    int v[rows][cols],
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

    zeros(&v);
    printf("\nResult matrix: \n"); showOff(v);

    return 0;
}