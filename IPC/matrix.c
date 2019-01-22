#include<stdio.h>

#include<stdlib.h>

#define MAX 10
void citire(int mat[][MAX], int * n) {
    int i, j;
    printf("Dati numarul de linii si coloane:");
    scanf("%d", n);
    for (i = 0; i < * n; i++)
        for (j = 0; j < * n; j++) {
            printf("mat[%d][%d]=", i, j);
            scanf("%d", & mat[i][j]);
        }
}

void afisare(int mat[][MAX], int * n) {
    int i, j;
    for (i = 0; i < * n; i++) {
        for (j = 0; j < * n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void suma(int mat[][MAX], int * n) {
    int i, j, s = 0;
    for (i = 0; i < * n; i++)
        for (j = 0; j < * n; j++)
            if (i + j == * n - 1)
                s += mat[i][j];

    printf("Suma elementelor de pe diagonala secundara este: %d", s);
}
int main() {
    int n, a[MAX][MAX], opt;
    do {
        printf("1.Citire\n");
        printf("2.Afisare\n");
        printf("3.Suma\n");
        printf("0.Iesire\n");
        printf("Optiunea dv. este:");
        scanf("%d", & opt);
        switch (opt)

        {
            case 1:
                citire(a, & n);
                break;
            case 2:
                afisare(a, & n);
                break;
            case 3:
                suma(a, & n);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Optiune gresita!\n");
                break;
        }
    } while (opt != 0);
    return 0;

}