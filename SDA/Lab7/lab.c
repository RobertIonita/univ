#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
    char *titlu;
    struct book *next;
} manual;

typedef struct autor
{
    char *name;
    struct book *sublist;
    struct autor *next;
} writer;

writer *prim = NULL;

manual *add2(manual *list, manual *p)
{
    manual *q1, *q2;
    for (q1 = q2 = list; q1 != NULL && strcmp(q1->titlu, p->titlu) < 0; q2 = q1, q1 = q1->next)
        ;
    p->next = q1;
    if (q1 == q2)
        return p;
    q2->next = p;
    return list;
}

writer *add3(writer *list, writer *p)
{
    writer *q1, *q2;
    for (q1 = q2 = list; q1 != NULL && strcmp(q1->name, p->name) < 0; q2 = q1, q1 = q1->next)
        ;
    p->next = q1;

    if (q1 == q2)
        return p;

    q2->next = p;
    return list;
}

void addod(char *n)
{
    writer *autor;
    manual *c;
    char d, tit[30];
    if ((autor = (writer *)malloc(sizeof(writer))) == NULL || (autor->name = (char *)malloc(strlen(n) + 1)) == NULL)
        printf("Nu este suficienta memorie");
    strcpy(autor->name, n);

    prim = add3(prim, autor);
    while (printf("\nDoriti introducerea unei carti d/n:"), (scanf(" %c", &d) ) != 'n') {
        printf("\nTitle:");
        scanf("%s", tit);
        if ((c = (manual * ) malloc(sizeof(manual))) == NULL || (c -> titlu = (char * ) malloc(strlen(tit) + 1)) == NULL)
            printf("Nu este suficienta memorie");
        strcpy(c -> titlu, tit);
        autor->sublist = add2(autor->sublist, c);
    }
}

void afisare()
{
    writer *autor;
    manual *c;
    printf("\nAutor\t| book");
    for (autor = prim; autor != NULL; autor = autor->next)
    {
        printf("\n%s", autor->name);
        if (autor->sublist != NULL)
        {
            for (c = autor->sublist; c != NULL; c = c->next)
            {
                printf("\t%s\n", c->titlu);
            }
        }
    }
}

int main()
{
    char n1[10];
    printf("\nAutorul:");
    scanf("%s", n1);
    addod(n1);
    afisare();
    return 0;
}