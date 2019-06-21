#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 13
typedef struct subnode
{
    int id;
    char data[MAX];
    struct subnode *next;
} subnode;

typedef struct node
{
    int id;
    char data[MAX];
    struct node *next;
    struct subnode *sublist;
} node;

node *addNode(node *head, int id, char *data);
subnode *addSubnode(subnode *head, int id, char *data);
node *readNode(node *head, char *path);
subnode *readSubnode(subnode *head, int node_id, char *path);
void showOff(node *head);

int main()
{
    node *list = NULL;
    subnode *sublist = NULL;
    list = readNode(list, "SDA/Practice/Lists/assets/list.txt");
    showOff(list);
    return 0;
}

node *addNode(node *head, int id, char *data)
{
    node *token,
        *q1, *q2;
    token = (node *)malloc(sizeof(node));
    token->id = id;
    strcpy(token->data, data);
    token->next = NULL;
    token->sublist = NULL;
    for (q1 = q2 = head; q1 != NULL && q1->data > token->data; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}
subnode *addSubnode(subnode *head, int id, char *data)
{
    subnode *token,
        *q1, *q2;
    token = (subnode *)malloc(sizeof(subnode));
    token->id = id;
    strcpy(token->data, data);
    token->next = NULL;
    for (q1 = q2 = head; q1 != NULL && q1->data > token->data; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}

subnode *readSubnode(subnode *head, int node_id, char *path)
{
    FILE *f = NULL;
    int id;
    char data[MAX];
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %s", &id, data);
            if (id == node_id)
                head = addSubnode(head, id, data);
        }
        fclose(f);
    }
    return head;
}

node *readNode(node *head, char *path)
{
    FILE *f = NULL;
    int id;
    char data[MAX];
    node *list;
    subnode *sublist;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %s", &id, data);
            head = addNode(head, id, data);
            sublist = head->sublist;
            sublist = readSubnode(sublist, id, "SDA/Practice/Lists/assets/sublists.txt");
            head->sublist = sublist;
        }
        fclose(f);
    }
    return head;
}

void showOff(node *head)
{
    node *list;
    subnode *sublist;
    for (list = head; list != NULL; list = list->next)
    {
        printf("\nnode: %d %s", list->id, list->data);
        if (list->sublist != NULL)
            for (sublist = list->sublist; sublist != NULL; sublist = sublist->next)
                printf("\n\tsubnode: %s", sublist->data);
    }
}