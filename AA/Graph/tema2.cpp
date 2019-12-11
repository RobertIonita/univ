#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 13
typedef struct subnode
{
    int id,
    	cost;
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
node *removeNode(node *head, int id);
subnode *removeSubode(subnode *head, char *data);
subnode *addSubnode(subnode *head, int id, char *data, int cost);
node *readNode(node *head, char *path);
subnode *readSubnode(subnode *head, int node_id, char *path);
node *searchNode(node *head, int id);
void visitNodes(node *head, int id);
void showOff(node *head);

int main()
{
    node *list = NULL;
    list = readNode(list, "assets/list.txt");
    showOff(list);
    // removeNode(list, 3);
    // showOff(list);
    visitNodes(list, 0);
    printf("\n");
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
    for (q1 = q2 = head; q1 != NULL && q1->data < token->data; q2 = q1, q1 = q1->next)
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
subnode *addSubnode(subnode *head, int id, char *data, int cost)
{
    subnode *token,
        *q1, *q2;
    token = (subnode *)malloc(sizeof(subnode));
    token->id = id;
    token->cost = cost;
    strcpy(token->data, data);
    token->next = NULL;
    for (q1 = q2 = head; q1 != NULL && q1->cost < token->cost; q2 = q1, q1 = q1->next)
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

node *removeNode(node *head, int id)
{
    node *q1, *q2;
    subnode *s;
    for (q1 = q2 = head; q1 != NULL && q1->id != id; q2 = q1, q1 = q1->next)
        ;
    if (q1 != q2)
    {
        printf("\n------------------------------\n");
        q2->next = q1->next;
        for (q2 = head; q2 != NULL; q2 = q2->next)
            if (q2->sublist)
            	q2->sublist = removeSubode(q2->sublist, q1->data);
        printf("\n------------------------------\n");
        free(q1);
    }
    return head;
}

subnode *removeSubode(subnode *head, char *data)
{
	subnode *q1, *q2;
		for (q1 = q2 = head; q1 != NULL && strcmp (q1 -> data, data); q2 = q1, q1 = q1 -> next);

		if (q1 != NULL && (strcmp (q1 -> data, data) == 0) ) {
		    if (q1 == q2) {
		        head = head -> next;
		    } else {
		        q2 -> next = q1 -> next;
		        free(q1);
		    }
		}
	return head;
}

subnode *readSubnode(subnode *head, int node_id, char *path)
{
    FILE *f = NULL;
    int id,
    	cost;
    char data[MAX];
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            if (fscanf(f, "%d %s %d", &id, data, &cost) != EOF)
                if (id == node_id)
                    head = addSubnode(head, id, data, cost);
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
    subnode *sublist;
    node *nptr;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError opening file %s", path);
    else
    {
        while (!feof(f))
        {
            if (fscanf(f, "%d %s", &id, data) != EOF)
            {
                if (searchNode(head, id) == NULL)
                {
                    head = addNode(head, id, data);
                }
                nptr = searchNode(head, id);
                sublist = nptr->sublist;
                sublist = readSubnode(sublist, id, "assets/sublist.txt");
                nptr->sublist = sublist;
            }
        }
        fclose(f);
    }
    return head;
}


node *searchNode(node *head, int id)
{
    node *q;
    for (q = head; q != NULL && q->id != id; q = q->next)
        ;
    return q;
}

void visitNodes(node *head, int id)
{
	if(head != NULL)
	{
		node *nptr = head;
		subnode *sublist;
		int min = (head->sublist)->cost;
		//for (nptr = head; nptr != NULL; nptr = nptr->next)
		//{
	    printf("\nnode: %d key: %s", nptr->id, nptr->data);
	    if (nptr->sublist != NULL)
	    {
			if((nptr->sublist)->cost < min)
				min = (nptr->sublist)->cost;
	    	printf("\n\tvertex: %s-%s", nptr->data, (nptr->sublist)->data);
	    	printf("\n\tcost: %d, min: %d", (nptr->sublist)->cost, min);    
		}
		visitNodes(nptr->next, nptr->id);
		//}
	}
}


void showOff(node *head)
{
    node *list;
    subnode *sublist;
    for (list = head; list != NULL; list = list->next)
    {
        printf("\nnode: %d key: %s", list->id, list->data);
        if (list->sublist != NULL)
            for (sublist = list->sublist; sublist != NULL; sublist = sublist->next)
                printf("\n\tvertex: %s-%s, cost: %d", list->data, sublist->data, sublist->cost);
    }
}


