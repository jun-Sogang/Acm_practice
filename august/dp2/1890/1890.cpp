#include <cstdio>
int a[105][105];
long long dp[105][105];
int ans=0;
int main(){
    int n;
    scanf("%d",&n);
  
    for(int i=1; i<=n; i++)
        for(int j=1;j<=n; j++)
            scanf("%d",&a[i][j]);
    dp[1][1]=1;
    for(int i=1;i<=n; i++)
        for(int j=1; j<=n; j++){
            if(a[i][j]==0)
                continue;
            if(j+a[i][j]<=n)
                dp[i][j+a[i][j]]+=dp[i][j];
            if(i+a[i][j]<=n)
                dp[i+a[i][j]][j]+=dp[i][j];
        }
    printf("%lld\n",dp[n][n]);
}