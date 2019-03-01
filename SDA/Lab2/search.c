#include <stdio.h>
#include <curses.h>
#include <string.h>



typedef struct{
    int key;
}
value;

typedef value tab[20];

int linear_search(tab a, int n, int x) {
    int i = 0;
    while (i < n && a[i].key != x) { // reduc la a 2-a cand while(a[i].key != x)
        i++;
    }
    return i;
}

int binary_search (tab a, int n, int x) {
    int s = 0,
        d = n-1,
        m = (s+d)/2;

    do {
        m = (s+d)/2;
        if (a[m].key > x) {
            d = m-1;
        } else {
            s = m+1;
        }

    } while (a[m].key != x && s<=d);
    return m;
}
int binary_Psearch (tab a, int n, int x) {
    int s = 0,
        d = n-1,
        m = (s+d)/2;

    do {
        m = (s+d)/2;
        if (a[m].key > x) {
            d = m;
        } else {
            s = m+1;
        }

    } while (a[m].key != x && s<d);
    return d;
}

int interpolar_search (tab a, int n, int x) {
    int s = 0,
        d = n-1,
        m;

    do {
        m = (s+d)/2;
    m = (d-s)*(a[m].key - a[s].key) / (a[d].key - a[s].key);

    if(a[m].key > x) {
        d = m-1;
    } else {
        s = m+1;
    }

    } while (a[m].key !=x && s<=d && a[d].key-a[s].key != 0 && x<= a[d].key && x <= a[s].key);

    return m;
}


int read(tab t) {
    FILE * f;
    int i = 0;
    if ((f = fopen("SDA/Lab2/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%d", &t[i].key);
            i++;
        }
        fclose(f);
    }
    return i;
}
void showOf(tab t, int n) {
    printf("\n%d",
        t[n].key
    );
}
int main() {
    int x, i = 0,
        nr, opt;

    value tab[30];
    nr = read(tab);

    for (i = 0; i < nr; i++) {
        showOf(tab, i);
    }
    printf("\nInsert desired nr: ");
    scanf("%d", &x);


    do {
        printf("\n0. exit");
        printf("\n1. linear");
        printf("\n2. binary");
        printf("\n3. binary performed");
        printf("\n3. interpolar");
        printf("\nUr choice: ");
        scanf("%d", & opt);

        switch (opt) {
            case 0:
                printf("\nquiting..");
                break;
            case 1:
                printf("\nlinear search:  %d", linear_search(tab, nr, x) );
                break;
            case 2:
                printf("\nbinary search:  %d", binary_search(tab, nr, x) );
                break;
            case 3:
                printf("\nperformance search:  %d", binary_Psearch(tab, nr, x) );
                break;
            case 4:
                printf("\ninterpolar search:  %d", interpolar_search(tab, nr, x) );
                break;
            default:
                printf("\ninvalid option");
                break;
        }

    } while (opt != 0);    
}
