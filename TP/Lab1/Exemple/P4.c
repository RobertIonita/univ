/* P4.Determina a/b */
#include<stdio.h>
int main (void)
{
int a,b;
scanf("%d%d",&a,&b);
if(b==0){
printf("Impartire la zero.\n");
return 1;
}
printf("Rezultatul este %lf.\n",(double)a/b);
return 0;

}