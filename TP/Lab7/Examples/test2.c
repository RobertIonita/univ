#include <stdio.h>
#include <stdlib.h>

int main() {

    int * x;
    x = (int * ) malloc(7 * sizeof(int));
    if (!x) {
        printf("Eroare alocare 1.\n");
        exit(EXIT_FAILURE);
    }

    x = (int * ) malloc(24 + sizeof(int));
    if (!x){
        printf("Eroare alocare 2.\n");
        exit(EXIT_FAILURE);
    }
    free(x);
    return 0;
}