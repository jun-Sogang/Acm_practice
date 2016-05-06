#include<stdio.h>
#include<stdlib.h>

int table[102][102]={0};
int main()
{
    int count;
    int x,y,width,height;
    int i,j,k;
    int count_info;
    int *s;
    scanf("%d",&count);
    count_info=count;
    s=(int *)malloc(sizeof(int)*(count_info+1));
    while(count--)
    {
        scanf("%d %d %d %d",&x,&y,&width,&height);
        for(i=0; i<width; i++)
        {
            for(j=0; j<height; j++)
            {
                table[x+i][y+j]=count_info-count;
            }
        }
    }
    for(i=0; i<101; i++)
    {
        for(j=0; j<101; j++)
        {
            for(k=0; k<=count_info;k++)
            {
                if(table[i][j] == k)
                    s[k]++;
            }

        }

    }
    for(i=1; i<=count_info; i++)
        printf("%d\n",s[i]);

    free(s);
    return 0;
}
