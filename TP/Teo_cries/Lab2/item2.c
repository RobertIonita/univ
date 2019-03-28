#include<stdio.h>
#define n 2
#define m 3

void transp(int (*mat)[m][n], int (*v)[n][m])
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        (*mat)[i][j]=(*v)[j][i];
    }
}

void afisare(int v[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%2d ",v[i][j]);
        printf("\n");
    }
}

int main()
{
    int mat[m][n], v[n][m], i, j;
    for( i = 0; i < n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("v[%d][%d]=",i,j);
            scanf("%d",&v[i][j]);
        }

    }
    transp(&mat,&v);
    afisare(mat);

    
}