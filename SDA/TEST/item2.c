#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct list {
    char fun_name[MAX];
    struct list * next;
} node;

node * functii = NULL;
node * cod = NULL;

node * add (node * first, char * fun_name) {
    node *q1, *q2,
        *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> fun_name, fun_name);
    clone -> next = NULL;

    for(q1 = q2 = first; q1 != NULL && (strcmp(q1 -> fun_name, clone -> fun_name) < 0); q2 = q1, q1 = q1 -> next);
    if (q1 == q2) {
        clone -> next = first;
        first = clone;
    } else {
        q2 -> next = clone;
        clone -> next = q1;
    }
    return first;
}
void showOff(node * first) {
    node * q;
    for (q = first; q != NULL; q = q -> next) {
        printf("\n%s", q -> fun_name);
    }
}

node * read(node * item, char * path) {
    char str[MAX];
    FILE *f;
    if( (f = fopen(path, "rt") ) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", str);
            item = add(item, str);
        }
        fclose(f);
    }
    return item;
}

void nr_aparitii () {
    int k = 0;
    node * i,
        *j;
    for(i = functii; i !=NULL; i = i -> next) {
        k=0;
        for(j=cod; j!=NULL; j = j -> next) {
            if( strcmp(i -> fun_name, j -> fun_name )==0 ) {
                k++;
            }
        }
        if (k > 0) 
            printf("\n function name: %s,  %d times", i -> fun_name, k);
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
    functii = read(functii, "SDA/TEST/functii.txt");
    printf("\nfunctions in library: \n"); showOff(functii);
    cod = read(cod, "SDA/TEST/cod.txt");
    printf("\nused functions: \n"); showOff(cod);

    nr_aparitii();
    printf("\nInsert desired node to be deleted: ");
    scanf("%s", desired);
    cod = deleteNode(cod, desired);

    showOff(cod);

    return 0;
}