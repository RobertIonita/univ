#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct list {
    char fun_name[MAX];
    struct list * next;
}
node;

node * functii = NULL;
node * cod = NULL;

void *add (node *first, char * fun_name) {
    node *q1, *q2, *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> fun_name, fun_name);
    clone -> next = NULL;

    for(q1 = q2 = first; q1!=NULL && (strcmp(q1 -> fun_name, clone -> fun_name) < 0); q2=q1, q1=q1->next);
    if (q1 == q2) {
        clone -> next = first;
        first = clone;
    } else {
        q2 -> next = clone;
        clone->next = q1;
    }
    return first;
}
void show(node * first) {
    node * q;
    for (q = first; q != NULL; q = q-> next) {
        printf("\n%s", q -> fun_name);
    }
}

void read_functii() {
    char fun_name[MAX];
    FILE * f;
    if ((f = fopen("SDA/TEST/functii.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", fun_name);
            functii = add(functii, fun_name);
        }
        fclose(f);
    }
}
void read_cod() {
    char fun_name[MAX];
    FILE * f;
    if ((f = fopen("SDA/TEST/cod.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", fun_name);
            cod = add(cod, fun_name);
        }
        fclose(f);
    }
}

void nr_aparitii (node * fun, node * code) {
    int k = 0;
    node * i,
        *j;
    for(i = fun; i !=NULL; i = i -> next) {
        k=0;
        for(j=code; j!=NULL; j = j -> next) {
            if( strcmp(i -> fun_name, j->fun_name )==0 ) {
                k++;
            }
        }
        printf("\n function name: %s,  %d times", i->fun_name, k);
    }
}

node * deleteNode(node * code, char * str) {
    node * q1, * q2;
    for (q1 = q2 = code; q1 != NULL && (strcmp(q1 -> fun_name, str)); q2 = q1, q1 = q1 -> next);
    if (q1 != NULL && ((strcmp(q1 -> fun_name, str) == 0))) {
        if (q1 == q2)
            code = code -> next;
        else
            q2 -> next = q1 -> next;
        free(q1);
    }
    return code;
}

int main() {
    char desired[MAX];
    read_functii();
    read_cod();

    show(functii);
    printf("\n-----------------------");
    show(cod);

    nr_aparitii(functii, cod);
    printf("\nInsert desired node to be deleted: ");
    scanf("%s", desired);
    cod = deleteNode(cod, desired);

    show(cod);

    return 0;
}