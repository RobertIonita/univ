#include<stdio.h>

#define MAX 10

int prim(int n) {
    int i, pr = 0;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            pr++;
    }
    if (pr != 0 || n == 1)
        return 0;
    else
        return 1;
}

int main() {
    int v[MAX], n, i, m=0;
    printf("n este:\n");
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        printf("v[%d]=", i);
        scanf("%d", & v[i]);
    }
    for (i = 0; i <n; i++) {
        if(prim(v[i])) {
            v[m]=v[i];
            m++;
        }
    }
    
    for(i=0; i<m; i++)
        printf("%d ", v[i]);
        printf("SA MA IEI DE OUA CU VECTORII TAI 🖕🏻");
    return 0;
}


//BAG SULAAAAA
