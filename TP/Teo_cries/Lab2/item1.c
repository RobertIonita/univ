#include <stdio.h>

#define MAX 111

void sortare(int * v, int n) {
    int i, j, ok = 0, aux;
    do {
        ok = 1;
        for (i = 0; i < n - 1; i++) {
            if (v[i] % 2 != 0) {
                for (j = i + 1; j < n; j++) {
                    if (v[j] % 2 != 0 && v[i] > v[j]) {
                        aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                        ok = 0;
                    }
                }
            
            }
        }
    }while (!ok);
}

void afisare(int v[MAX], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int main() {
    int v[MAX], n, i;
    printf("n=\n");
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        printf("v[%d]=", i);
        scanf("%d", & v[i]);
    }
    sortare(v, n);
    afisare(v, n);
    return 0;
}