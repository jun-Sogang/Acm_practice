#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n,m;
vector < long long > a;
bool check(ll mid){
    ll val=0;
    for(int i=0; i<n; i++){
        if(mid<a[i]){
            val+=a[i]-mid;
        }
    }
    return val >= m;

}
int main(){
    
    scanf("%lld %lld",&n,&m);
    ll temp;
    for(int i=0; i<n; i++){
        scanf("%lld",&temp);
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    ll l=0;
    ll r=a.back();
    ll ans=0;
    while(l<=r){
        ll mid=(r+l)/2;
        if(check(mid)){
            if(ans<mid){
                ans=mid;
            }
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%lld\n",ans);
}
