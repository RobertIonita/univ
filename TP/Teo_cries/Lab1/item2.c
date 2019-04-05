#include<stdio.h>

#define MAX 5
int max(int v[MAX], int n) {
    int i, max = v[0];
    for (i = 0; i < n; i++) {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

int main() {
    int v[MAX], n, i;
    printf("n este\n");
    scanf("%d", & n);
    for( i = 0; i < n; i++)
    {
        printf("v[%d]:", i);
        scanf("%d",&v[i]);
    }
    printf("%d",max(v,n));

    return 0;
}