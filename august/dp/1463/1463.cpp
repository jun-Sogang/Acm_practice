#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];
int dynamic(int n)
{
    if(n==1)
        return dp[1];
    if(dp[n]>0)
        return dp[n];
    dp[n]=dynamic(n-1)+1;
    if(n%3==0 &&dp[n]>dp[n/3]+1)
        dp[n]=dynamic(n/3)+1;
    if(n%2==0 &&dp[n]>dp[n/2]+1)
        dp[n]=dynamic(n/2)+1;
    return dp[n];
}
int main()
{
    int n;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    scanf("%d",&n);
    printf("%d\n",dynamic(n));
}

