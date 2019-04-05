#include<stdio.h>


int cifra(int n, int c) {
    int ct = 0;
    while (n != 0)
    {
        if (n % 10 == c)
            ct++;
            n=n/10;
    }
    if (ct != 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n,c,f;

    printf("n este"); scanf("%d",&n);
    printf("c este"); scanf("%d",&c);
    while (n > 0) {
        f=cifra(n,c);
        if(f)
            printf("%d", n);
        n--;
    }

    return 0;
}