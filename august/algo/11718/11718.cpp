#include<stdio.h>

int main()
{
    char temp;
    while((temp=getchar())!= EOF)
    {
        printf("%c",temp);
    }
    return 0;
}
