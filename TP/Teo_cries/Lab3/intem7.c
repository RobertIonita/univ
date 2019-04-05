#include<stdio.h>
#include<string.h>
#define MAX 30

int suma(char s[MAX])
{

    int i, n=strlen(s), nr=0, sum=0;
    for(i=0; i<n; i++){
        nr = 0;
        if(s[i]>='0' && s[i]<='9')
        {
            nr=s[i]-48;
            while(s[i+1]>='0' && s[i+1]<='9')
            {
                nr=nr*10+s[i+1]-48;
                i++;
            }
        }
        sum=sum+nr;
    }
    return sum;
}

int main()
{
    char s[MAX];
    printf("Sirul este: ");
    scanf("%s",s);
    printf("\nsuma e: %d",suma(s));
}