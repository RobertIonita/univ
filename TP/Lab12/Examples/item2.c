#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *f;
    unsigned char c;
    int rez;
    f = fopen("TP/Lab12/assets/fbin.dat", "rb");
    if(!f) {
        exit(EXIT_FAILURE);
    }
    while ((rez = fread(&c, sizeof(c), 1, f)) == 1)
    {
        printf("%02X ", c);
    }
    printf("\n");
    fclose(f);
    return 0;
}