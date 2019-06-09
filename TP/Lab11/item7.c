// Se cere numele unui fișier. Să se controleze de cțte ori apare în el fiecare literă
// și să se afișeze literele apărute și numărul lor de apariții

#include <stdio.h>
#include <stdlib.h>

void read(char *path, int (*arr)[])
{
    FILE *f;
    char c;
    if ((f = fopen(path, "r")) == NULL)
    {
        printf("error");
    }
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%c", &c);
            (*arr)[c]++;
        }
        fclose(f);
    }
    (*arr)[c]--;
}
int main()
{
    int arr[256];
    for (size_t i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }

    read("TP/Lab11/assets/input7.txt", &arr);
    for (size_t i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
            printf("%c: %d\n", i, arr[i]);
    }

    return 0;
}