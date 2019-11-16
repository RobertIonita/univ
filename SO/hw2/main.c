#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

char *concat(char *str1, char *str2, char *formater);
int copySourceIntoDestination(char *source, char *destination, mode_t st_mode);

int main(int argc, char *argv[])
{
    struct stat statbuf;
    char *source,
        *destination,
        *option;

    if (argc != 4)
    {
        printf("\nInvalid arguments");
        printf("\nExample: >$ ./${workspaceRoot}//${objectBasename} sourceName destinationName option");
        printf("\nInsert '0' as option to link files, and !'0' to copy them\n");
        return 1;
    }
    source = argv[1];
    destination = argv[2];
    option = argv[argc - 1];

    stat(destination, &statbuf);
    if (S_ISDIR(statbuf.st_mode))
    {
        char answer;
        printf("Destination directory already exists\nOverwrite? (Y/n :Yes/no): ");
        scanf("%c", &answer);
        if (answer != 'Y')
            return -1;
    }
    printf("\noption: %s", option);

    stat(source, &statbuf);
    if (!S_ISDIR(statbuf.st_mode))
    {
        printf("Ivalid source directory\n");
        return 1;
    }

    if (strcmp(option, "0"))
    {
        printf("\nYou've choosed to copy %s from %s\n", destination, source);
        if (copySourceIntoDestination(source, destination, statbuf.st_mode) != -1)
            printf("\nFiles have been copied successfuly\n");
        else
            printf("\nAn error occured while copying files\n");
    }
    else
    {
        printf("\nYou've choosed to link %s to %s\n", destination, source);
        link(source, destination);
    }

    return 0;
}

char *concat(char *s1, char *s2, char *formater)
{
    char *ns = malloc(strlen(s1) + strlen(formater) + strlen(s2) + 1);
    ns[0] = '\0';
    strcat(ns, s1);
    strcat(ns, formater);
    strcat(ns, s2);
    return ns;
}

int copySourceIntoDestination(char *source, char *destination, mode_t st_mode)
{
    DIR *dp;
    dp = opendir(source);
    struct dirent *dirp;
    struct stat statbuf;
    char *tokenSource,
        *tokenDestination;
    int input,
        output,
        count,
        *size;

    mkdir(destination, st_mode);

    if (dp == NULL)
    {
        printf("\nError opening %s directory", source);
        return -1;
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
        {
            tokenSource = concat(source, dirp->d_name, "/");
            tokenDestination = concat(destination, dirp->d_name, "/");
            stat(tokenSource, &statbuf);
            if (S_ISDIR(statbuf.st_mode))
                copySourceIntoDestination(tokenSource, tokenDestination, statbuf.st_mode);
            else
            {
                input = open(tokenSource, O_RDONLY);
                output = open(tokenDestination, O_CREAT | O_APPEND | O_WRONLY, st_mode);
                if ((size = malloc(statbuf.st_size)) != NULL)
                {
                    count = read(input, size, statbuf.st_size);
                    while (count != 0)
                    {
                        write(output, size, count);
                        count = read(input, size, statbuf.st_size);
                    }
                }
                free(size);
                close(input);
                close(output);
            }
        }
    }
    closedir(dp);
    return 0;
}
