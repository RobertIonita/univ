#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct 
{
    char linii[MAX];
} linie;

void citire(linie *l, int *n)
{
    (*n)++;
    scanf("%s",(l+*n)->linii);
}


int main()
{
    linie   lin[MAX];
    int n=-1, i;
    
    return 0;
}