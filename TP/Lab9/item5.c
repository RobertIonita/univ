#include <stdio.h>
#include <stdlib.h>

int main()
{   int nr;
    printf("dati nr\n");
    scanf("%d",&nr);
    if((nr&nr-1)==0)
        printf("%d este o putere a lui 2",nr);
    else
        printf("%d nu este o putere a lui 2",nr);
    return 0;
}