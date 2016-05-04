#include<stdio.h>


int main()
{
    char temp;
    while((temp=getchar()) != EOF)
    {
        if(temp == '\n')
            break;
        if(temp >= 'A' && temp <= 'Z')
            printf("%c",temp);
    }
    
    printf("\n");
}
