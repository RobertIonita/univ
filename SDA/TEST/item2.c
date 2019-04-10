#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct item{
    char email[MAX];
    int times;
    struct item *next;
} node;

node *root = NULL;

node * add (node * first, char * str, int times) {
    node *q1, *q2,
        *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> email, str);
    clone -> times = times;
    clone -> next = NULL;

    for(q1 = q2 = first; q1 != NULL && (strcmp(q1 -> email, clone -> email) < 0); q2 = q1, q1 = q1 -> next);
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
    char str[MAX];
    int times;
    FILE *f;
    if( (f = fopen(path, "rt") ) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %d", str, &times);
            item = add(item, str, times);
        }
        fclose(f);
    }
    return item;
}

void showOff(node *item) {
  node *q;
  for (q = item; q != NULL; q = q -> next) {
    printf("\n%s %d",
        q -> email,
        q -> times
    );
  }
}

void filter(node *item) {
  node *q;
  for (q = item; q != NULL; q = q -> next) {
      if (q -> times > 2) {
        printf("\n%s %d",
            q -> email,
            q -> times
        );
      }
  }
}

node * deleteItem(node * item, char * str) {
    node * q1, * q2;
    for (q1 = q2 = item; q1 != NULL && (strcmp(q1 -> email, str)); q2 = q1, q1 = q1 -> next);
    if (q1 != NULL && ((strcmp(q1 -> email, str) == 0))) {
        if (q1 == q2)
            item = item -> next;
        else
            q2 -> next = q1 -> next;
        free(q1);
    }
    return item;
}

int main () {
    char desired[MAX];
    root = read (root, "SDA/TEST/e_mail.txt");
    printf("\nAll mails: ");
    showOff(root);
    printf("\nAt least 3 times: ");
    filter(root);
    printf("\nInsert record to be deleted: ");
    scanf("%s", desired);
    root = deleteItem(root, desired);
    showOff(root);
    return 0;
}