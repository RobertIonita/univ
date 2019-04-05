#include <stdio.h>

#define MAX 100

typedef struct {
    int l, c,
        linii[MAX],
        coloane[MAX],
        n;
    float nenul[MAX];
}
matrix;


void populate(matrix * mat, int * count) {
    int i, j;
    float value = 0;
    mat[ * count].n = 0;

    printf("\nInsert nr of lines: ");
    scanf("%d", & mat[ * count].l);
    printf("\nInsert nr of columns: ");
    scanf("%d", & mat[ * count].c);
    for (i = 0; i < mat[ * count].l; i++) {
        for (j = 0; j < mat[ * count].c; j++) {
            printf("\nmatrix[%d][%d]: ", i+1, j+1);
            scanf("%f", & value);
            if (value) {
                mat[ * count].linii[mat[ * count].n] = i;
                mat[ * count].coloane[mat[ * count].n] = j;
                mat[ * count].nenul[mat[ * count].n++] = value;
            }
        }
    }
    ( * count) ++;
}


void showRecords(matrix * mat, int count) {
    int i, j,
    n;
    for (i = 0; i < count; i++) {
        printf("\nRecord %d is:\nValue Line Column", i + 1);
        n = mat[i].n;
        for (j = 0; j < n; j++) {
            printf("\n%5.2f %5d %5d",
                mat[i].nenul[j],
                mat[i].linii[j],
                mat[i].coloane[j]
            );
        }
        printf("\n");
    }
}

void showMatrices(matrix * mat, int count) {
    int i, j, k,
    non_null = 0;
    for (k = 0; k < count; k++) {
        non_null = 0;
        printf("\nMatrix %d is:\n", k + 1);
        for (i = 0; i < mat[k].l; i++) {
            for (j = 0; j < mat[k].c; j++) {
                if (mat[k].linii[non_null] == i && mat[k].coloane[non_null] == j) {
                    printf("%5.2f ", mat[k].nenul[non_null]);
                    non_null++;
                } else {
                    printf(" 0.00 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

void summ(matrix * mat, int count) {
    int i, j,
        first, second,
        summ, k = 0;

    printf("\nInsert two matrices (order Nrs) that you want to summ up: ");
    scanf("%d %d", &first, &second); first--; second--;

    while (mat[first].l != mat[second].l || mat[first].c != mat[second].c) {
        printf("Choosen matrices are not of the same size, please select another ones:");
        scanf("%d %d", &first, &second); first--; second--;
    }

    printf("\nResult matrix\n");
    for(i = 0; i < mat[first].l; i++) {
        for(j = 0; j < mat[first].c; j++){
            printf("%5.2f ",mat[first].nenul[k] + mat[second].nenul[k++]);
        }
        printf("\n");
    }

}

int main() {
    matrix zeros[10];

    int option,
        nr_of_matrices = 0,
        lines, column;

    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show records");
        printf("\n3. show matrices");
        printf("\n4. summ two matrices");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                return 0;
            case 1:
                populate(zeros, &nr_of_matrices);
                break;
            case 2:
                showRecords(zeros, nr_of_matrices);
                break;
            case 3:
                showMatrices(zeros, nr_of_matrices);
                break;
            case 4:
                summ(zeros, nr_of_matrices);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option != 0);
}