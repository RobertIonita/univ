#include<stdio.h>
#include<math.h>
#define n 3

int suma(float v[n][n])
{
    int i, j, s=0,
        intreg;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
            intreg = v[i][j];
            if(intreg == v[i][j] && intreg%2==0 && i<=j) {
                s += intreg;
            }
        }
    }
    return s;
}

void afisare(float v[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%.2f ", v[i][j]);
        printf("\n");
    }
}

int main()
{
    float v[n][n];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
            printf("v[%d][%d]=", i,j);
            scanf("%f", &v[i][j]);
        }

    }
    afisare(v);
    printf("\nsuma = %d",suma(v));
}