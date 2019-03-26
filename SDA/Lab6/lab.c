#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node * next;
}
node;

node * root = NULL;


void *add (node *first, int x) {
    node *q1, *q2, *clone;
    clone = (node *)malloc(sizeof(node));
    clone -> key = x;
    clone -> next = NULL;

    for(q1 = q2 = first; q1!=NULL && q1 -> key < clone -> key; q2=q1, q1=q1->next);
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
        printf("%d\n", q -> key);
    }

}

void read() {
    int x;
    FILE * f;
    if ((f = fopen("SDA/Lab6/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%d", &x);
            root = add(root, x);
        }
        fclose(f);
    }
}

int main() {

    read();
    show(root);
    return 0;
}