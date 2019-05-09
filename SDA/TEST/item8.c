#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct list {
    char data[MAX];
    struct list * next;
}
node;

node * root = NULL;

void *add (node *first, char * data) {
    node *q1, *q2, *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> data, data);
    clone -> next = NULL;

    for(q1 = q2 = first; q1!=NULL && (strcmp(q1 -> data, clone -> data) < 0); q2=q1, q1=q1->next);
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
    int i = 1;
    for (q = first; q != NULL; q = q-> next, i++) {
        printf("%s", q -> data);
        if (i%2 == 0) {
            printf(" ");
        }
        if (i%8 == 0) {
            printf("\n");
        }
        
    }
}
void count(node * first) {
    node * q;
    int k = 0;
    for (q = first; q != NULL; q = q-> next) {
        if (strcmp(q -> data, "1110") == 0) {
            k++;
        }
    }
    printf("\nThere are %d '1110' records\n", k);
}

node * deleteItem (node * item) {
    node *q1, *q2;
    for (q1 = q2 = item; q1 != NULL && strcmp (q1 -> data, "0000"); q2 = q1, q1 = q1 -> next);

    if (q1 != NULL && (strcmp (q1 -> data, "0000") == 0) ) {
        if (q1 == q2) {
            item = item -> next;
        } else {
            q2 -> next = q1 -> next;
            free(q1);
        }
    }
    return item;
}
void read() {
    char data[MAX];
    FILE * f;
    if ((f = fopen("SDA/TEST/binary1.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", data);
            root = add(root, data);
        }
        fclose(f);
    }
}

int main() {
    read();
    show(root);
    count(root);
    root = deleteItem(root);
    printf("\nAfter delete: \n");
    show(root);
    return 0;
}