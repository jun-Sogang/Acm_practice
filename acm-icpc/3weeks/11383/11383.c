#include<stdio.h>

int main()
{
    int n,m;
    char temp1[11][21];
    char temp2[11][11];
    scanf("%d %d",&n, &m);
    int i,j;
    int flag=0;
    for(i=0; i<n; i++)
    {
        scanf("%s",temp2[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%s",temp1[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m*2; j++)
        {
            if(temp2[i][j/2] != temp1[i][j])
                flag=1;
        }
    }
    if(!flag)
        printf("Eyfa\n");
    else
        printf("Not Eyfa\n");

    return 0;
}
