#include<stdio.h>

int main()
{
    int i;
    char a[101];
    scanf("%s",a);
    for(i=0; i<101; i++)
    {
        if(a[i]>='a' && a[i]<='z')
        {
            a[i]-=32;
        } 
        else if(a[i]>='A' && a[i]<='Z')
        {
            a[i]+=32;
        }
    }
    printf("%s\n",a);
}
