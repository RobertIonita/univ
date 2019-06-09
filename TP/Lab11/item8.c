// Un fișier are câte o propoziție pe fiecare linie
// Se cere să se scrie într-un fișier destinație fiecare propoziție pe o line
// dar între ghilimele

#include <stdio.h>
#include <stdlib.h>

void read(char *path_in, char *path_out)
{
    FILE *f;
    FILE *g;
    char str[256];
    if ((f = fopen(path_in, "rt")) == NULL || (g = fopen(path_out, "wt")) == NULL)
        printf("error");
    else
        while (!feof(f))
        {
            fgets(str, 256, f);
            size_t i;
            for (i = 0; str[i] != '\0'; i++)
                ; //aflu lungimea șirului
            str[i - 1] = '"'; // ultimul carater este '\n' (new line), îl înlocuiesc cu '"'
            str[i] = '\0';
            fprintf(g, "\"%s\n", str); // șmecher
        }
    fclose(f);
}
int main()
{
    read("TP/Lab11/assets/input8.txt", "TP/Lab11/assets/output8.txt");
    return 0;
}