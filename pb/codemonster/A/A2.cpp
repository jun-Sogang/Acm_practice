#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll bitset_OneCounter(ll n){
    ll count=0;
    while(n){
        count++;
        n&=(n-1);
    }
    return count;
}
ll count(ll n){
    ll num=n-1;
    ll ans=n-1;
    while(num>0){
        num/=2;
        ans+=num;
    }
    return ans;
}
ll dnc(ll from, ll to){
    if((to&(to-1)) ==0)
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll from,to;
        cin >> from >> to;
        dnc(from,to);
        printf("%lld\n",ans);
    }
}
