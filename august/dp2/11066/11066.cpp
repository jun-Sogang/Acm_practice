#include <cstdio>
#include <cstring>
int a[505];
int preprocessing[505];
int dp[505][505];

int dynamic(int i,int j){
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int &ans = dp[i][j];
    for(int k=i; k<=j-1; k++){
        int temp = dynamic(i,k) + dynamic(k+1,j) + preprocessing[j]-preprocessing[i-1];
        if(ans == -1 || ans > temp)
            ans=temp;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(preprocessing,0,sizeof(preprocessing));
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            preprocessing[i]=preprocessing[i-1]+a[i];
        }
        printf("%d\n",dynamic(1,n));
    }
}
