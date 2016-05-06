#include<stdio.h>
#include<string.h>
int main()
{
    int input;
    char temp[51];
    char ans[51];
    int len;
    int flag=1;
    int i;
    scanf("%d",&input);
   

    while(input--)
    {
        scanf("%s",temp);
        if(flag)
        {
            flag=0;
            len=strlen(temp);
            strcpy(ans,temp);
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if(temp[i] != ans[i])
                    ans[i]='?';
            }
        }

    }
    printf("%s\n",ans);
    return 0;
}
