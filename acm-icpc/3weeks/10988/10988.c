#include<stdio.h>
#include<string.h>

int main()
{
    char input[101];
    int len,i;
    scanf("%s",input);
    len=strlen(input);
    int flag=0;

    for(i=0; i<len/2+1; i++)
    {
        if(input[i] != input[len-1-i])
        {
            flag = 0;
            break;  
            
        }else
            flag=1;        
    }
    printf("%d\n",flag);
    return 0;
}
