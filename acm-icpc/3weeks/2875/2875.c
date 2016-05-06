#include <stdio.h>
#include <string.h>
int main()
{
    char fbi[11];
    int i;
    int flag=0;
    for(i=0; i<5; i++)
    {
        scanf("%s",fbi);
        if(strstr(fbi,"FBI"))
        {
            printf("%d\n",i+1);
            flag=1;
        }
    }
    if(!flag)
        printf("HE GOT AWAY!\n");
    return 0;
}
