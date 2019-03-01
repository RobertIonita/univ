//test1
#include<stdio.h>
double f(double a,double b)
{
	return a-b >0 ? a-b : b-a;
}
int main(void)
{
	printf("%lf\n",f(2,4));
	printf("%lf\n",f(4,2));
	printf("%lf\n",f(-2,4));
	printf("%lf\n",f(4,-2));
	printf("%lf\n",f(-2,-4));
	printf("%lf\n",f(-4,-2));
	printf("%lf\n",f(2,-4));
	printf("%lf\n",f(-4,2));
	return 0;
}
// Programul returneaza modulul diferentei dintre doua numere
