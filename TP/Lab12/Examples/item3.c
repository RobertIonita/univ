#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *f;
    unsigned int k;
    int rez;
    f = fopen("TP/Lab12/assets/fbin.dat", "rb");
    if(!f) {
        exit(EXIT_FAILURE);
    }
    while ((rez = fread(&k, sizeof(k), 1, f)) == 1)
    {
        printf("%08X ", k);
    }
    printf("\n");
    fclose(f);
    return 0;
}