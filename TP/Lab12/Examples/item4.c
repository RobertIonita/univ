#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *f;
    int i;
    unsigned char c;
    f = fopen("TP/Lab12/assets/f02.dat", "wb");
    if(!f) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < 17; i++)
    {
        c = i;
        fwrite(&c, 1, 1, f);
    }
    fclose(f);
    return 0;
}