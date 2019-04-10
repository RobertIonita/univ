#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct item {
    char data[MAX];
    struct item * next;
} node;

typedef struct  {
    char str[MAX];
} preadd;

preadd items[100];

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
node * read(node * item, char * path) {
    int i = 0,
        j, count = 0;
    FILE *f;
    if( (f = fopen(path, "rt") ) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", items[i].str);
            count=0;
            for(j = 0; j <i; j++) {
                if ( strcmp(items[j].str, items[i].str) == 0) {
                    count++;
                }
            }
            if (count == 0)
                item = add(item, items[i].str);
            i++;
        }
        fclose(f);
    }
    return item;
}

node * root = NULL;

void showOff(node * first) {
    node * q;
    for (q = first; q != NULL; q = q -> next) {
        printf("\n%s", q -> data);
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

void search (node * item) {
    int len;
    printf("\nInsert desired length: ");
    scanf("%d", &len);
    node *q;
    for (q = item; q != NULL; q = q -> next) {
        if (strlen(q -> data) == len) {
            printf("\n%s", q -> data);
        }
    }
}


int main() {
    char desired[MAX];
    int nr, i;

    root = read (root, "SDA/TEST/arta_listelor1.txt");
    
    showOff(root);
    printf("\nInsert record to be deleted: ");
    scanf("%s", desired);
    root = deleteItem(root, desired);
    showOff(root);
    search(root);
    return 0;
}
