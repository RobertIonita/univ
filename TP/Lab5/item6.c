#include <stdio.h>

#define MAX 100

typedef struct {
    int l, c,
        linii[MAX],
        coloane[MAX],
        n;
    float nenul[];
} matrix;


void populate(matrix *mat, int *count){
    (*count)++;
    int i, j;
    float value = 0;
    mat[*count].n = 0;

    printf("\nInsert nr of lines: ");
    scanf("%d", &mat[*count].l);
    printf("\nInsert nr of columns: ");
    scanf("%d", &mat[*count].c);


    for(i=0; i< mat[*count].l; i++) {
        for(j=0; j< mat[*count].c; j++) {
            printf("\nmatrix[%d][%d]: ", i,j);
            scanf("%f", &value);
            if (value) {
                mat[*count].linii[mat[*count].n] = i;
                mat[*count].coloane[mat[*count].n] = j;
                mat[*count].nenul[mat[*count].n++] = value;
            }
        }
    }
}


void showOff(int n, int m, float arr[n][m]){
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf(" %4.2f", arr[i][j]);
        }
        printf("\n");
    }

}

int main() {
    matrix zeros[10];
    
    int option,
        nr_of_matrices = -1,
        lines, column;

    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. search");
        printf("\n4. sort");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                return 0;
            case 1:
                populate(&zeros[0], &nr_of_matrices);
                break;
            case 2:
                // showOff(l, c, mat);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option != 0);
}