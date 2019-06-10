#include <stdio.h>
#include <stdlib.h>

void binar(int nr)
{
    printf("\nreprezentare binara:\n");
    for (int i = sizeof(int) * 4 - 1; i >= 0; i--)
    {
        printf("%d", nr >> i & 1);
    }
}
int invert(int *nr)
{
    int n;
    printf("\nn: ");
    scanf("%d", &n);
    *nr = *nr ^ ((1 << n) - 1);
    return *nr;
}

int main()
{
    int nr;
    printf("\nNr: ");
    scanf("%d", &nr);
    binar(nr);
    printf("reprezentarea zecimala:\n%d", invert(&nr));
    binar(nr);
    return 0;
}