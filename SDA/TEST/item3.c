#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct item {
    char data[MAX];
    struct item * next;
} node;

node * func = NULL;
node * code = NULL;

node * add (node * first, char * str) {
    node *q1, *q2,
        *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> data, str);
    clone -> next = NULL;

    for(q1 = q2 = first; q1 != NULL && (strcmp(q1 -> data, clone -> data) < 0); q2 = q1, q1 = q1 -> next);
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
        printf("\n%s", q -> data);
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

void count () {
    int k = 0;
    node *i,
        *j;
    for (i = func; i != NULL; i = i -> next) {
        k = 0;
        for (j = code; j != NULL; j = j -> next) {
            if( strcmp(i -> data, j -> data) == 0) {
                k++;
            }
        }
        if (k > 0) 
            printf("\nfunction: %6s was used %d time(s)", i -> data, k);
    }
}

node * deleteItem (node * item, char * desired) {
    node *q1, *q2;
    for (q1 = q2 = item; q1 != NULL && strcmp (q1 -> data, desired); q2 = q1, q1 = q1 -> next);

    if (q1 != NULL && (strcmp (q1 -> data, desired) == 0) ) {
        if (q1 == q2) {
            item = item -> next;
        } else {
            q2 -> next = q1 -> next;
            free(q1);
        }
    }
    return item;
}
int main() {
    char desired[MAX];
    func = read(func, "SDA/TEST/functii.txt");
    printf("\nfunctions in library: \n"); showOff(func);
    code = read(code, "SDA/TEST/cod.txt");
    printf("\nused functions: \n"); showOff(code);
    count();
    printf("\nInsert function that you want to delete: ");
    scanf("%s", desired);
    code = deleteItem(code, desired);
    showOff(code);
    return 0;
}
