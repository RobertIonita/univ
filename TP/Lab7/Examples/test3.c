#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int * x, * z;
    x = z = (int * ) malloc(7 * sizeof(int));
    if (!x) {
        printf("Eroare alocare 1.\n");
        exit(EXIT_FAILURE);
    }

    free(x);
    return 0;
}