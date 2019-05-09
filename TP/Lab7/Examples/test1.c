#include <stdio.h>
#include <stdlib.h>

int main() {

    int * x, * z;
    x = (int * ) malloc(7 * sizeof(int));
    if (!x) {
        printf("Eroare alocare 1.\n");
        exit(EXIT_FAILURE);
    }

    z = (int * ) malloc(24 * sizeof(int));
    if (!z) {
        printf("Eroare alocare 2.\n");
        free(x);
        exit(EXIT_FAILURE);

    }

    free(x);
    free(z);
    return 0;
}