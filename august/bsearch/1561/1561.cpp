#include <cstdio>
#include <vector>
using namespace std;
vector < int > v;
typedef long long ll;
int m;
ll n;
bool go(ll mid){
    ll index=mid;
    ll count=m;
    for(int i=0; i<m; i++){
        count+=index/v[i];
    }
    if(count < n)
        return true;
    else
        return false;
}
int main(){
    scanf("%lld %d",&n,&m);
    for(int i=0; i<m ;i++){
        int tmp;
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    if(n<=m){
        printf("%lld\n",n);
        return 0;
    }
    ll left=1, right=2000000000LL * 1000000LL;
    while(left<=right){
        ll mid = (left+right)/2;
        if(go(mid)){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    ll ans=0;
    for(int i=0; i<m; i++){
        ans+=(left-1)/v[i];
    }
    ans+=m;
    ll temp=0;
    for(int i=0; i<m; i++){
        if((left)%v[i]==0)
            temp++;
        if(ans+temp == n){
            printf("%d\n",i+1);
            break;
        }
    }
}
