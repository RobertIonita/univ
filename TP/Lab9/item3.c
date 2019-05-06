#include <stdio.h>
#include <stdlib.h>

int main()
{   int nr;
    printf("dati nr");
    scanf("%d",&nr);
    printf("\ncatul este %d",(nr>>3));
    printf("\nrestul este %d",(nr&7));
    return 0;
}