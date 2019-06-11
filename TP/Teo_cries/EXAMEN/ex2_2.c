#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void citire()
{
    FILE *f, *g;
    char sir[MAX], ch;
    int n, k = 0, lines = 1;
    f = fopen("TP/Teo_cries/EXAMEN/assets/ex2_2.txt", "rt");
    g = fopen("TP/Teo_cries/EXAMEN/assets/ex2_2_iesire.txt", "wt");
    if (!f || !g)
    {
        exit(EXIT_FAILURE);
    }
    while (!feof(f))
    {
        fscanf(f, "%c", &ch);
        if (ch == '\n')
            lines++;
    }
    rewind(f);
    while (lines--)
    {
        fscanf(f, "%s", sir);
        n = strlen(sir);
        for (size_t i = 0; sir[i] != '\0'; i++)
        {
            if (sir[i] >= '0' && sir[i] <= '9')
                k++;
        }
        if (!k)
            fprintf(g, "\n%s", sir);
        k = 0;
    }
        
    fclose(g);
    fclose(f);
}
void afisare()
{
    FILE *f;
    char sir[MAX];
    f = fopen("TP/Teo_cries/EXAMEN/assets/ex2_2_iesire.txt", "rt");
    if (!f)
        exit(EXIT_FAILURE);
    while (!feof(f))
    {
        fscanf(f, "%s", sir);
        printf("\n%s", sir);
    }

    fclose(f);
}

int main()
{
    citire();
    afisare();
    return 0;
}