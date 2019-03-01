/* P1.Determina i intoare valoarea minim(a,b) */
#include <stdio.h>
double minim(double x,double y)
{

	return x<y? x:y;

}
int main(void)
{
double a,b;
printf("Introduceti doua numere reale:");
scanf("%lf%lf",&a,&b);
printf("Minimul este: %lf\n",minim(a,b));
return 0;


}