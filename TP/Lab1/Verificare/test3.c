//test 3
#include<stdio.h>
void spatii(int n)
{
	int i;
	for(i=0;i<n;i++)
		putchar(' ');
}
void stelute(int n)
{
	int i;
	for(i=0;i<n;i++)
		putchar('*');
}
int main(void)
{ int i,j;
for(i=0;i<8;i++)
{
	for(j=0;j<4;j++) {
		if((i/2+j)%2)stelute(2);
		else spatii(2);
	}
	putchar('\n');
}
return 0;
}