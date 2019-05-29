#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
    char *title;
    struct book *next;
} manual;

typedef struct autor
{
    char *name;
    struct book *sublist;
    struct autor *next;
} writer;

writer *root = NULL;

manual *add_manual(manual *list, manual *item)
{
    manual *q1, *q2;
    for (q1 = q2 = list; q1 != NULL && strcmp(q1->title, item->title) < 0; q2 = q1, q1 = q1->next)
        ;
    item->next = q1;
    if (q1 == q2)
        return item;
    q2->next = item;
    return list;
}

writer *add_writer(writer *list, writer *item)
{
    writer *q1, *q2;
    for (q1 = q2 = list; q1 != NULL && strcmp(q1->name, item->name) < 0; q2 = q1, q1 = q1->next)
        ;
    item->next = q1;

    if (q1 == q2)
        return item;

    q2->next = item;
    return list;
}
void link_book(writer *autor, manual *work)
{
    char *title,
        answer;
    do
    {
        printf("\nDo you wanna add a new book? (enter 'n' to reject): ");
        scanf(" %c", &answer);
        if (answer == 'n')
            continue;
        printf("\nTitle:");
        work = (manual *) malloc (sizeof(manual));
        work->title = (char *)malloc(strlen(title) + 1);
        if (!work || !work->title)
            printf("\nAn error occured while allocating memory ");
        strcpy(work->title, title);
        autor->sublist = add_manual(autor->sublist, work);
    } while (answer != 'n');
}
void addnod()
{
    writer *autor;
    manual *work;
    char answer,
        name[30];
    do {
        printf("\nDo you wanna add a new autor? (enter 'n' to reject): ");
        scanf(" %c", &answer);
        if (answer == 'n')
            continue;
        
        printf("\nAutor: ");
        scanf("%s", name);
        printf("\nname: %s", name);
        autor = (writer *)malloc(sizeof(writer));
        autor->name = (char *)malloc(strlen(name) + 1);
        if (!autor || !autor->name) {
            printf("\nAn error occured while allocating memory ");
            continue;
        }
        else {
            strcpy(autor->name, name);
            root = add_writer(root, autor);
            link_book(autor, work);
        }

    } while (answer != 'n');
    
}

void afisare()
{
    writer *autor;
    manual *work;
    printf("\nAutor\t| book");
    for (autor = root; autor != NULL; autor = autor->next)
    {
        printf("\n%s", autor->name);
        if (autor->sublist != NULL)
        {
            for (work = autor->sublist; work != NULL; work = work->next)
            {
                printf("\t%s\n", work->title);
            }
        }
    }
}

int main()
{
    addnod();
    afisare();
    return 0;
}