#include<stdio.h>
#define MAX_SIZE 101
int main()
{
    int count=0;
    char temp;
    while((temp=getchar())!= EOF)
    {
        if(temp == '\n')
            break;
        printf("%c",temp);
        count++;
        if(count%10 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}
