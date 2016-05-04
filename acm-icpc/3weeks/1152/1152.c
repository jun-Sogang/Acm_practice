#include<stdio.h>
#define MAX_INPUT 1000000
int main()
{
    char temp;
    int count=0;
    int flag=0;
    int max=0;
    while((temp=getchar())!='\n'&& max<MAX_INPUT)
    {
        if(temp !=' ')
            flag=1;
        if(temp == ' '&& (flag))
        {
            flag=0;
            count++;
        }
        max++;
        
    }
    if(flag)
        count+=1;
    printf("%d\n",count);

    return 0;
}
