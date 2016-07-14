#include <stdio.h>

int dp[41][2];
int flag[41];
int main()
{
    int t,n,i;
    scanf("%d",&t);
    for(i=0; i<41; i++)
    {
        dp[i][0]=0;
        dp[i][1]=0;
        flag[i]=0;
    }
    dp[0][0]=1;
    dp[1][1]=1;
    dp[2][0]=dp[1][0]+dp[0][0];
    dp[2][1]=dp[1][1]+dp[0][1];
    while(t--)
    {
        scanf("%d",&n);
        for(i=2; i<=n; i++)
        {
            if(flag[i]==0)
            {
                flag[i]=1;
                dp[i][0]=dp[i-1][0]+dp[i-2][0];
                dp[i][1]=dp[i-1][1]+dp[i-2][1];
            }
        }
        printf("%d %d\n",dp[n][0],dp[n][1]);
    }
    return 0;
}
