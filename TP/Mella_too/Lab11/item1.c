#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f;
    int n, i, j;
    printf("Dati un numar n: ");
    scanf("%d", &n);
    if ((f = fopen("in1.txt", "w")) == NULL)
    {
        printf("Fisierul nu a fost deschis\n");
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i == j)
                fprintf(f, "0");
            else if (i > j)
                fprintf(f, "+");
            else
                fprintf(f, "-");
        fprintf(f, "\n");
    }
    fclose(f);
}