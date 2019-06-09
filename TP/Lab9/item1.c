//să se verifice dacă nr este par sau impar

#include <stdio.h>
int main()
{
    int nr;
    printf("dati numarul: ");
    scanf("%d", &nr);
    if ((nr & 1) == 1)
        printf("Numarul este impar");
    else
        printf("Numarul este par");
    return 0;
}