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
    char title[30], answer;
    do
    {
        printf("\nDo you wanna add a new book? (enter 'n' to reject): ");
        fflush(stdin);
        scanf(" %c", &answer);
        if (answer == 'n')
            continue;
        printf("\nTitle:");
        scanf("%s", title);
        if ((work = (manual *)malloc(sizeof(manual))) == NULL || (work->title = (char *)malloc(strlen(title) + 1)) == NULL)
            printf("\nAn error occured while allocating memmory ");
        strcpy(work->title, title);
        autor->sublist = add_manual(autor->sublist, work);
    } while (answer != 'n');
}
void addnod(char *n)
{
    writer *autor;
    manual *work;
    if ((autor = (writer *)malloc(sizeof(writer))) == NULL || (autor->name = (char *)malloc(strlen(n) + 1)) == NULL) {
        printf("\nAn error occured while allocating memmory ");

    }
    strcpy(autor->name, n);

    root = add_writer(root, autor);
    link_book(autor, work);
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
    char n1[10];
    printf("\nAutorul:");
    scanf("%s", n1);
    addnod(n1);
    afisare();
    return 0;
}