// să se marchez cu 1 bitul bit a lui nr

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr;
    unsigned short bit;
    printf("dati nr: ");
    scanf("%d", &nr);
    for (int poz = 15; poz >= 0; poz--)
        printf("%d", ((nr >> poz) & 1));
    printf("\nal catelea bit? ");
    scanf("%hu", &bit);
    printf("%d", nr & (1 << bit));
    return 0;
}