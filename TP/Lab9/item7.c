// să se memoreze numerele pe 8 biți nr1 și nr2 într-un întreg nr pe 16 biți

#include <stdio.h>

int main()
{
    short nr1,
        nr2,
        nr;
    printf("\nInsert nr1: ");
    scanf("%hd", &nr1);
    printf("Insert nr2: ");
    scanf("%hd", &nr2);
    nr = nr1 * 256 + nr2;
    for (int i = 15; i >= 0; i--)
    {
        if (i == 7)
            printf(" ");
        printf("%d", (nr >> i) & 1);
    }
}