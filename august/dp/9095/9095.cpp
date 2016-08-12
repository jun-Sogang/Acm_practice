#include <cstdio>
int dp[13]={0,1,2,4,};
int dynamic(int t){
    if(dp[t]>0)
        return dp[t];
    dp[t]=dynamic(t-1)+dynamic(t-2)+dynamic(t-3);
    return dp[t];
}
int main(){
    int n,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        printf("%d\n",dynamic(t));
    }
}
