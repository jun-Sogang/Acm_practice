#include <cstdio>

int dp[1002]={1,1,2,};

int dynamic(int n)
{
    if(dp[n]>0)
        return dp[n];
    dp[n]=(dynamic(n-1)+dynamic(n-2))%10007;
    return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",dynamic(n));
}
