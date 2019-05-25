#include <stdio.h>

#include <stdlib.h>

typedef struct subitem {
    int id,
        data;
    struct subitem * next;
}
subnode;

typedef struct item {
    int id,
        data;
    struct item * next;
    subnode * subitem;
}
node;

node * root = NULL;




subnode * add_sub(subnode * first, int id, int data) {
    subnode * q1, * q2,
        * clone;
    clone = (subnode * ) malloc(sizeof(subnode));
    clone -> id = id;
    clone -> data = data;
    clone -> next = NULL;

    for (q1 = q2 = first; q1 != NULL && (q1 -> id < clone -> id); q2 = q1, q1 = q1 -> next);
    if (q1 == q2) {
        clone -> next = first;
        first = clone;
    } else {
        q2 -> next = clone;
        clone -> next = q1;
    }
    return first;
}
node * add(node * first, int id, int data) {
    node * q1, * q2,
        * clone;
    clone = (node * ) malloc(sizeof(node));
    clone -> id = id;
    clone -> data = data;
    clone -> next = NULL;
    clone -> subitem = NULL;

    for (q1 = q2 = first; q1 != NULL && (q1 -> id < clone -> id); q2 = q1, q1 = q1 -> next);
    if (q1 == q2) {
        clone -> next = first;
        first = clone;
    } else {
        q2 -> next = clone;
        clone -> next = q1;
    }
    return first;
}
subnode * read_sub(subnode * subitem, char * path) {
    int id,
        data;
    FILE * f;
    if ((f = fopen(path, "rt")) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%d %d", &id, &data);
            subitem = add_sub(subitem, id, data);
        }
        fclose(f);
    }
    return subitem;
}
node * read(node * item, char * path) {
    int id,
        data;
    FILE * f;
    if ((f = fopen(path, "rt")) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%d %d", &id, &data);
            item = add(item, id, data);
        }
        fclose(f);
    }
    return item;
}

void showOff_sub(subnode * item) {
    subnode * q;
    for (q = item; q != NULL; q = q -> next) {
        printf("\n%d %d", q -> id, q -> data);
    }
}
void showOff(node * item) {
    node * q;
    for (q = item; q != NULL; q = q -> next) {
        printf("\n%d %d", q -> id, q -> data);
    }
}

void link (node * list, subnode * sublist) {
    node *n;
    subnode *s;
    for (n = list; n != NULL; n = n -> next) {
        printf("\nnode data: %d %d", n -> id, n -> data);
        for (s = sublist; s != NULL; s = s -> next) {
            if (n -> id == s -> id)
            {
                subnode * item;
                item = (subnode *) malloc (sizeof(subnode));
                item -> id = s -> id;
                item -> data = s -> data;
                (n -> subitem) -> next = item;
                printf("\n\tsubnode data: %d %d", s -> id, s -> data);
            }
        }
    }
    
}

int main() {

    node * root = NULL;
    subnode * branch = NULL;
    root = read(root, "SDA/Project/assets/play.txt");
    branch = read_sub(branch, "SDA/Project/assets/sublist.txt");
    showOff_sub(branch);
    showOff(root);
    link(root, branch);

    return 0;
}