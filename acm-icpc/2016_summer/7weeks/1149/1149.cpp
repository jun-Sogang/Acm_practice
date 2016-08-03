#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[1002];
int b[1002];
int c[1002];
int dp[1001][3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
    
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            dp[i][0]=a[i];
            dp[i][1]=b[i];
            dp[i][2]=c[i];
        }
        else
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+a[i];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+b[i];
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+c[i];
        }

    }
    int ans=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    printf("%d\n",ans);
    return 0;
}
