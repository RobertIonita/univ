#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct list {
    char str[MAX];
    struct list * next;
}
node;

node * root = NULL;

void *add (node *first, char * str) {
    node *q1, *q2, *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> str, str);
    clone -> next = NULL;

    for(q1 = q2 = first; q1!=NULL && (strcmp(q1 -> str, clone -> str) < 0); q2=q1, q1=q1->next);
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
        printf("%s\n", q -> str);
    }
}

void complement(node * first) {
    node * q;
    int i;
    for (q = first; q != NULL; q = q-> next) {
        for(i = 0; (q -> str)[i] != '\0'; i++) {
            if ((q -> str)[i] == '0') {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

void max(node * first) {
    node * q;
    int i,
        k = 0,
        j= 0,
        n = 1;
    char reg[MAX+1];
    strcpy(reg, "");
    for (q = first; q != NULL; q = q-> next, j++) {
        k = 0;
        for(i = 0; (q -> str)[i] != '\0'; i++) {
            if ((q -> str)[i] == '1') {
                k++;
            }
        }
        if (reg[0] < '0'+k){
            n = 1;
            reg[0] = '0'+k;
            reg[1] = '0'+j;
            reg[2] = '\0';
        } else if( reg[0] == '0'+k) {
            n++;
            reg[n] = '0'+j;
        }
        reg[n+1] = '\0';
    }
    for(i = 1; reg[i] != '\0'; i++) {
        n = 0;
        q = first;
        while(reg[i]-48 > n++ && q != NULL){
            q = q->next;
        }
        
        printf("\nindices: %c %s", reg[i], q->str);
    }
    printf("\nmax: %c", reg[0]);
}

void read() {
    char str[MAX];
    FILE * f;
    if ((f = fopen("SDA/TEST/binary.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", str);
            root = add(root, str);
        }
        fclose(f);
    }
}

int main() {
    read();
    show(root);
    complement(root);
    max(root);
    return 0;
}