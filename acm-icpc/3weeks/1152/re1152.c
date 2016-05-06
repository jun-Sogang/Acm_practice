#include<stdio.h>

char s[1000001];
int main()
{
    int i,count=1;
    gets(s);
    for(i=0; s[i] != '\0'; i++)
    {
        if(s[i] == ' '&& i!=0)
            count++;
    }
    if(s[i-1] == ' ')
        count--;
    
    printf("%d\n",count);

    return 0;
}
