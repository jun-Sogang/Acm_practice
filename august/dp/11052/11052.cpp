#include <cstdio>
int cost[1002];
int benefit[1002];
int dynamic(int n){
    if(n ==0)
        return benefit[n];
    if(benefit[n]>0)
        return benefit[n];
    for(int i=1; i<=n; i++){
        if(benefit[n] < cost[i]+dynamic(n-i))
            benefit[n]=cost[i]+dynamic(n-i);
    }
    return benefit[n];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&cost[i]);
    printf("%d\n",dynamic(n));
}
