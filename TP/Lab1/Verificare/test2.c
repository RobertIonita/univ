//test2
#include<stdio.h>
int contributie(int k)
{
	if(k%3==2) return k;
	else if (k%3==1) return 0;
	else return 1;
}
int main (void)
{
	int total=0,i;
	for(i=0;i<10;i++)
		total+=contributie(i);
	printf("%d\n",total);
	return 0;
}
