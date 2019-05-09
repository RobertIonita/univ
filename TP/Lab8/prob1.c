#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 double fsin(double x) {return sin(x);}
 double fcos(double x) {return cos(x);}
 double fsxc(double x) {return sin(x)*cos(x);}
 double fxx(double x) {return x*x;}

void tab(double (*fptr)(double), int a,int b,int n)
{
    double i;
    for(i=a;i<=b;i+=(double)abs(a-b)/(n-1))
        printf("%.4lf => %.4lf\n", i, (*fptr)(i));
}
int main()
{   int a,n,b;
    scanf("%d %d %d",&a,&b,&n);
    printf("\n sin(x)\n");
    tab(&fsin,a,b,n);
    printf("\n cos(x)\n");
    tab(&fcos,a,b,n);
    printf("\n sin(x)*cos(x)\n");
    tab(&fsxc,a,b,n);
    printf("\n x*x\n");
    tab(&fxx,a,b,n);
    return 0;
}