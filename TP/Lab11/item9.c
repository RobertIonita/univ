#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 30

typedef struct
{
    int x, y;
} dot;


typedef struct item {
    dot data;
    struct item * next;
} node;

double get_dist(int a, int b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

node * add (node * first, int x, int y) {
    node *q1, *q2,
        *clone;
    clone = (node *)malloc(sizeof(node));
    clone -> data.x = x;
    clone -> data.y = y;
    clone -> next = NULL;

    for(q1 = q2 = first; q1 != NULL && get_dist(q1 -> data.x, q1 -> data.y) < get_dist(clone -> data.x, clone -> data.y); q2 = q1, q1 = q1 -> next);
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
    int x, y;
    FILE *f;
    if( (f = fopen(path, "rt") ) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%d %d", &x, &y);
            item = add(item, x, y);
        }
        fclose(f);
    }
    return item;
}

node * root = NULL;

void write(node * first, char * path) {
    FILE *f;
    node * q;
    if( (f = fopen(path, "wt") ) == NULL) {
        printf("\nerror writing file");
    } else {
        for (q = first; q != NULL; q = q -> next)
            fprintf(f, "\n%d %d", q -> data.x, q -> data.y);
        fclose(f);
    }
}

int main() {
    root = read (root, "TP/Lab11/assets/input3.txt");
    write(root, "TP/Lab11/assets/output9.txt");
    return 0;
}