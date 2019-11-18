#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#define MAX 256

void copiaza(char sursa[MAX], char destinatie[MAX], mode_t mod)
{
    DIR *dr;
    dr = opendir(sursa);
    struct dirent *dir;
    struct stat info;
    char aux_sursa[MAX], aux_dest[MAX];
    int intrare, iesire, contor, *lng;

    mkdir(destinatie, mod);

    if (dr == NULL)
    {
        printf("\nEroare la deschiderea directorului!");
    }

    while ((dir = readdir(dr)) != NULL)
    {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
        {

            sprintf(aux_sursa, "%s/%s", sursa, dir->d_name);
            sprintf(aux_dest, "%s/%s", destinatie, dir->d_name);
            stat(aux_sursa, &info);
            if (S_ISDIR(info.st_mode))
                copiaza(aux_sursa, aux_dest, info.st_mode);
            else
            {
                intrare = open(aux_sursa, O_RDONLY);
                iesire = open(aux_dest, O_CREAT | O_APPEND | O_WRONLY, mod);
                if ((lng = malloc(info.st_size)) != NULL)
                {
                    contor = read(intrare, lng, info.st_mode);
                    while (contor != 0)
                    {
                        write(iesire, lng, contor);
                        contor = read(intrare, lng, info.st_mode);
                    }
                }
                free(lng);
                close(intrare);
                close(iesire);
            }
        }
    }
    closedir(dr);
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        for (int i = 0; i < argc; i++)
        {
            printf("\nargv[%d]=%s\n", i, argv[i]);
        }
        struct stat info;
        char sursa[MAX];
        char destinatie[MAX];
        char mod[MAX];

        strcpy(sursa , argv[1]);
        strcpy(destinatie , argv[2]);
        strcpy(mod , argv[3]);

        stat(sursa, &info);
        if (!S_ISDIR(info.st_mode))
        {
            printf("\nNu exista acest director!");
            return 0;
        }

        if (strcmp(mod, "2") == 0)
            link(sursa, destinatie);
        else
        {
            copiaza(sursa, destinatie, info.st_mode);
        }
    }
    else
    {
        printf("\nNumarul argumentelor nu este bun!");
        printf("\nMod: 1 pentru copii, 2 pentru link-uri");
        printf("\n");
    }
    return 0;
}