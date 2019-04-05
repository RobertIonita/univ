#include<stdio.h>
#define n 5

void inserare(int (*v)[n][n])
{
    int i,j;
    
    for(i=n-1; i>2; i--)
    {
        for(j=0; j<n; j++)
            if(i!=3)
            {
                (*v)[i][j] = (*v)[i-1][j];
            } else {
                (*v)[i][j] = 0;
            }
    }
}

void afisare(int v[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%2d ",v[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int v[n][n], i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("v[%d][%d]=",i,j);
            scanf("%d",&v[i][j]);
        }
    }
    afisare(v);
    printf("rezultat: \n");
    inserare(&v);
    afisare(v);
    return 0;
}