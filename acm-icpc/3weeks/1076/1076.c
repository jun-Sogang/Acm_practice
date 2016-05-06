#include <stdio.h>
#include <string.h>

int check_registance(char *color);
int main()
{
    long long sum=0;
    char temp[11];
    int i;
    int count;
    scanf("%s",temp);
    sum+=check_registance(temp)*10;
    scanf("%s",temp);
    sum+=check_registance(temp);
    scanf("%s",temp);
    count=check_registance(temp);
   // printf("%lld\n",sum);
    for(i=0; i<count; i++)
    {
        sum*=10;
       // printf("%lld\n",sum);
    }
    printf("%lld\n",sum);

    return 0;
}

int check_registance(char *color)
{
    if(!strcmp(color,"black"))
            return 0;
    else if(!strcmp(color,"brown"))
            return 1;
    else if(!strcmp(color,"red"))
            return 2;
    else if(!strcmp(color,"orange"))
            return 3;
    else if(!strcmp(color,"yellow"))
            return 4;
    else if(!strcmp(color,"green"))
            return 5;
    else if(!strcmp(color,"blue"))
            return 6;
    else if(!strcmp(color, "violet"))
            return 7;
    else if(!strcmp(color, "grey"))
            return 8;
    else if(!strcmp(color,"white"))
            return 9;
    
}

