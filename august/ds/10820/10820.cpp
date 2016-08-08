#include <stdio.h>

int main() {
    char c;
    int space=0;
    int capital=0;
    int small=0;
    int num=0;
    
    while((c=getchar()) != EOF)
    {
        if(c==' ')
            space++;
        else if(c>=48 && c<= 57)
            num++;
        else if(c>=65 && c<=90)
            capital++;
        else if(c>=97 && c<=122)
            small++;
        else if(c=='\n')
        {
            printf("%d %d %d %d\n",small,capital,num,space);
            small=0;
            capital=0;
            num=0;
            space=0;
        }
        
    }
    return 0;
}