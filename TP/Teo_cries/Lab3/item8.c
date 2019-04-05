#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 25
#define max 3

void matrice(char s[MAX], char (*m)[max][max])
{
    int n=sqrt(strlen(s))+1, i, j, k=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++, k++) {
            if(s[k])
            {
                (*m)[i][j]=s[k];
                printf("%c ", (*m)[i][j]);
            } 
            else
            {
               (*m)[i][j] = '_';
                printf("%c ", (*m)[i][j]);
            }
            
        }
        printf("\n");
    }
}

int main()
{
    char s[MAX],  m[max][max];
    printf("Sirul este: ");
    scanf("%[^.]s",s);
    matrice(s,&m);
}