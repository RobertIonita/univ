// P1 Se cere un n pozitiv. Sa se scrie intr-un fisier un careu de n*n litere core contine la fiecare pozitie daca indexul
// liniei este mai mare decat al coloanei, "0" doca sunt egale si "-" in caz contrar. 
//Exemplu pentru n==3: 
// 0-- 
// +0-
// ++0

#include <stdio.h>
#include <stdlib.h>

void write(int nr, char *path)
{
    FILE *f;
    if ((f = fopen(path, "wt")) == NULL)
        printf("error");
    else
        for (size_t i = 0; i < nr; i++)
        {
            for (size_t j = 0; j < nr; j++)
            {
                if (j == i)
                    fprintf(f, "0");
                else if (j < i)
                    fprintf(f, "+");
                else
                    fprintf(f, "-");
            }
            fprintf(f, "\n");
        }
    fclose(f);
}

int main()
{
    int n;
    printf("Insert nr: ");
    scanf("%d", &n);
    write(n, "TP/Lab11/assets/output1.txt");
}