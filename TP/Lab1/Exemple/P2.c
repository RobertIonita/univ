/* P2.minim(a,b,c) */

#include<stdio.h>
double minim(double x,double y)
{

	return x<y ? x:y;

}
int main (void)
{
double a,b,c;
printf("Introduceti trei numere reale: ");
scanf("%lf%lf%lf",&a,&b,&c);
printf("Minimul este %lf.\n",minim(minim(a,b),c));
return 0;

}