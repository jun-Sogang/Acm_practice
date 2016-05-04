#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1025
int main()
{
    int n,m;
    long long **field;
    long long **suminfo;
    int i,j;
    int x1,x2,y1,y2;
    long long sum=0;
    scanf("%d %d",&n,&m);
    field=(long long **)malloc(sizeof(long long *)*(n+1));
    for(i=0; i<n+1; i++)
        field[i]=(long long *)malloc(sizeof(long long)*(n+1));
    suminfo=(long long **)malloc(sizeof(long long)*(n+1));
    for(i=0; i<n+1; i++)
        suminfo[i]=(long long *)malloc(sizeof(long long)*(n+1));
    
    for(i=0; i<n; i++)
    {
        sum=0;
        for(j=0; j<n; j++)
        {
            scanf("%lld",&field[i][j]);
            sum+=field[i][j];
            if(!i)
                suminfo[i][j]=sum;
            else
            {
                suminfo[i][j]=suminfo[i-1][j]+sum;
            }
        }
    }
    sum=0;
    while(m--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1>=2 && y1>=2)
            sum=suminfo[x2-1][y2-1]-suminfo[x1-2][y2-1]-suminfo[x2-1][y1-2]
                +suminfo[x1-2][y1-2];
        else if(x1>=2 && y1==1)
            sum=suminfo[x2-1][y2-1]-suminfo[x1-2][y2-1];
        else if(x1==1 && y1>=2)
            sum=suminfo[x2-1][y2-1]-suminfo[x2-1][y1-2];
        else if(x1==1 && y1==1)
            sum=suminfo[x2-1][y2-1];
        printf("%lld\n",sum);
        
    }

    return 0;
}
