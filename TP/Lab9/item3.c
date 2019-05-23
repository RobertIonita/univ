#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, nr;
    printf("dati n: ");
    scanf("%d", &n);
    printf("dati nr: ");
    scanf("%d", &nr);
    printf("\ncatul este %d", (nr >> n));
    printf("\nrestul este %d", (nr & (1 << n) - 1));
    return 0;
}